#include "IpcManageTools.h"
#include <assert.h>


namespace ipcTools
{
	ConnectManager* ConnectManager::Instance()
	{
		static ConnectManager* instance = NULL;
		if(!instance)
		{
			instance = new ConnectManager();
			instance->initClient();
		}
		assert(instance);

		return instance;
	}

	BOOL ConnectManager::connectDVR(const IPCResourceDataPacket* ipc)
	{
		ConnectInfo DVRInfo;
		DVRInfo.type = ipc->deviceType;
		strcpy_s(DVRInfo.ip, ipc->IP.c_str());
		DVRInfo.userName = ipc->userName;
		DVRInfo.password = ipc->password;
		DVRInfo.port = ipc->port;
		DVRInfo.channel = ipc->channel;

		for (map<LONG, ConnectInfo>::iterator iter = m_ConnectList.begin();iter != m_ConnectList.end();iter++)
		{
			if(iter->second == DVRInfo)
				return TRUE;
		}

		char ip[16] = {0};
		strcpy_s(ip, DVRInfo.ip);
		char userName[100];
		strcpy_s(userName, DVRInfo.userName.c_str());
		char password[100];
		strcpy_s(password, DVRInfo.password.c_str());

		BOOL ret = FALSE;
		switch(DVRInfo.type)
		{
		case DeviceType::DeviceTypeDH:
			{
				LONG handle = connectDHDVR(ip, DVRInfo.port, userName, password);
				if (handle != 0)
				{
					IPCResourceDataPacket* ipc_temp = const_cast<IPCResourceDataPacket*>(ipc);
					ipc_temp->hPTZ = handle;
					m_ConnectList[handle] = DVRInfo;
					ret = TRUE;
				}
			}
			break;
		case DeviceType::DeviceTypeHC:
			{
				LONG handle = connectHCDVR(ip, DVRInfo.port, userName, password);
				if (handle != -1)
				{
					IPCResourceDataPacket* ipc_temp = const_cast<IPCResourceDataPacket*>(ipc);
					ipc_temp->hPTZ = handle;
					m_ConnectList[handle] = DVRInfo;
					ret = TRUE;
				}
			}
			break;
		default:
			assert(false);
			break;
		}
		return ret;
	}

	BOOL ConnectManager::PTZControl(const PTZControlDataPacket &commad)
	{
		map<LONG, ConnectInfo>::iterator iter = m_ConnectList.find(commad.hPTZ);
		if (iter == m_ConnectList.end())
			return FALSE;

		LONG hLogin = (LONG)commad.hPTZ;
		DWORD dwPTZCommand = (DWORD)commad.command;
		DWORD param1 = (DWORD)commad.param1;
		DWORD param2 = (DWORD)commad.param2;
		DWORD param3 = (DWORD)commad.param3;
		BOOL dwStop = (DWORD)commad.dwStop;

		switch(iter->second.type)
		{
			case DeviceType::DeviceTypeDH:
				{
					int channel = 1;
					PTZControlDH(hLogin, channel, dwPTZCommand, param1, param2, 
						param3, dwStop);
				}
				break;
			case DeviceType::DeviceTypeHC:
				{
					PTZControlHC(hLogin, dwPTZCommand, param1, param2, param3, dwStop);
				}
				break;
			default:
				assert(false);
				break;
		}
		return FALSE;
	}

	BOOL ConnectManager::initClient()
	{
		BOOL ret = initClientHC();
		ret = initClientDH() && ret;
		return ret;
	}

}
