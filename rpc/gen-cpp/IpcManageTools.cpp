#include "IpcManageTools.h"
#include <assert.h>


namespace ipcTools
{
	ConnectManager* ConnectManager::Instance()
	{
		static ConnectManager* instance = NULL;
		if(!instance)
			instance = new ConnectManager();

		assert(instance);

		return instance;
	}

	LONG ConnectManager::connectDVR(const char *ipc)
	{
		//通过描述ipc查找对应DVRInfo
		ConnectInfo DVRInfo;
#ifdef _DEBUG
		DVRInfo.type = DeviceType::DeviceTypeHC;
		strcpy_s(DVRInfo.ip, "14.23.115.10");
		DVRInfo.userName = "admin";
		DVRInfo.password = "12345";
		DVRInfo.port = 8000;
		DVRInfo.channel = 0;
#endif
		map<ConnectInfo, LONG>::iterator iter = m_ConnectList.find(DVRInfo);
		if(iter != m_ConnectList.end())
			return iter->second;

		char ip[16] = {0};
		strcpy_s(ip, DVRInfo.ip);
		char userName[100];
		strcpy_s(userName, DVRInfo.userName.c_str());
		char password[100];
		strcpy_s(password, DVRInfo.password.c_str());

		LONG ret = NULL;
		switch(DVRInfo.type)
		{
		case DeviceType::DeviceTypeDH:
			{
				ret = connectDHDVR(ip, DVRInfo.port, userName, password);
			}
			break;
		case DeviceType::DeviceTypeHC:
			{
				ret = connectHCDVR(ip, DVRInfo.port, userName, password);
			}
			break;
		default:
			assert(false);
			break;
		}
		return ret;
	}

	BOOL ConnectManager::PTZControl(const PTZCommandDataPacket &commad)
	{
		LONG hLogin = (LONG)commad.hLogin;
		DWORD dwPTZCommand = (DWORD)commad.command;
		DWORD param1 = (DWORD)commad.param1;
		DWORD param2 = (DWORD)commad.param2;
		DWORD param3 = (DWORD)commad.param3;
		BOOL dwStop = (DWORD)commad.dwStop;

		DeviceType::type deviceType;
		switch(deviceType)
		{
			case DeviceType::DeviceTypeDH:
				{
					int channel = (int)commad.channel;
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

}
