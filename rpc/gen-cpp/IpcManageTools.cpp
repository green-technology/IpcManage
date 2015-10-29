#include "IpcManageTools.h"
#include "glog/logging.h"

namespace ipcTools
{
	ConnectManager* ConnectManager::instance = NULL;

	ConnectManager* ConnectManager::Instance()
	{
		if(!instance)
		{
			//instance = new ConnectManager();
			static ConnectManager manager;
			instance = &manager;
			instance->initClient();
		}
		LOG(ERROR)<<"ConnectManager 初始化失败";

		return instance;
	}

	ConnectManager::~ConnectManager()
	{
		for (map<LONG, IPCResourceDataPacket*>::iterator iter = m_ConnectList.begin();iter != m_ConnectList.end();)
		{
			IPCResourceDataPacket* info = iter->second;
			switch(info->deviceType)
			{
			case DeviceType::DeviceTypeDH:
				{
					closeConnectDH(info->hPTZ);
				}
				break;
			case DeviceType::DeviceTypeHC:
				closeConnectHC(info->hPTZ);
				break;
			default:
				LOG(ERROR)<<"不识别的设备类型";
				break;
			}
			iter = m_ConnectList.erase(iter);
		}
	}

	BOOL ConnectManager::connectDVR(const IPCResourceDataPacket* ipc)
	{
		IPCResourceDataPacket* DVRInfo = new IPCResourceDataPacket();
		DVRInfo->deviceType = ipc->deviceType;
		DVRInfo->IP = ipc->IP.c_str();
		DVRInfo->userName = ipc->userName;
		DVRInfo->password = ipc->password;
		DVRInfo->port = ipc->port;
		DVRInfo->channel = ipc->channel;

		for (map<LONG, IPCResourceDataPacket*>::iterator iter = m_ConnectList.begin();iter != m_ConnectList.end();iter++)
		{
			if(iter->second == DVRInfo)
				return TRUE;
		}

		char ip[16] = {0};
		strcpy_s(ip, DVRInfo->IP.c_str());
		char userName[100];
		strcpy_s(userName, DVRInfo->userName.c_str());
		char password[100];
		strcpy_s(password, DVRInfo->password.c_str());

		BOOL ret = FALSE;
		switch(DVRInfo->deviceType)
		{
		case DeviceType::DeviceTypeDH:
			{
				LONG handle = connectDHDVR(ip, DVRInfo->port, userName, password);
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
				LONG handle = connectHCDVR(ip, DVRInfo->port, userName, password);
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
			LOG(ERROR)<<"不识别的设备类型";
			break;
		}
		return ret;
	}

	BOOL ConnectManager::PTZControl(const PTZControlDataPacket &commad)
	{
		map<LONG, IPCResourceDataPacket*>::iterator iter = m_ConnectList.find(commad.hPTZ);
		if (iter == m_ConnectList.end())
			return FALSE;

		LONG hLogin = (LONG)commad.hPTZ;
		DWORD dwPTZCommand = (DWORD)commad.command;
		DWORD param1 = (DWORD)commad.param1;
		DWORD param2 = (DWORD)commad.param2;
		DWORD param3 = (DWORD)commad.param3;
		BOOL dwStop = (DWORD)commad.dwStop;

		switch(iter->second->deviceType)
		{
			case DeviceType::DeviceTypeDH:
				{
					int channel = 0;
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
				LOG(ERROR)<<"不识别的设备类型";
				break;
		}
		return FALSE;
	}

	void ConnectManager::closeConnect(LONG hPTZ)
	{
		map<LONG, IPCResourceDataPacket*>::iterator iter = m_ConnectList.find(hPTZ);
		if (iter != m_ConnectList.end())
		{
			IPCResourceDataPacket* info = iter->second;
			switch(info->deviceType)
			{
			case DeviceType::DeviceTypeDH:
				{
					closeConnectDH(hPTZ);
				}
				break;
			case DeviceType::DeviceTypeHC:
				closeConnectHC(hPTZ);
				break;
			default:
				LOG(ERROR)<<"不识别的设备类型";
				break;
			}
			iter = m_ConnectList.erase(iter);
		}
	}

	BOOL ConnectManager::initClient()
	{
		BOOL ret = initClientHC();
		ret = initClientDH() && ret;
		return ret;
	}

}
