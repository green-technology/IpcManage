#include "IpcManageTools.h"
#include <Windows.h>
#include "dh\dhnetsdk.h"
#include "hc\HCNetSDK.h"
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

	long ConnectManager::connectDVR(const ConnectInfo &DVRInfo)
	{
		map<ConnectInfo, long>::iterator iter = m_ConnectList.find(DVRInfo);
		if(iter == m_ConnectList.end())
			return iter->second;

		char ip[16] = {0};
		strcpy_s(ip, DVRInfo.ip);
		char userName[100];
		strcpy_s(userName, DVRInfo.userName.c_str());
		char password[100];
		strcpy_s(password, DVRInfo.password.c_str());

		long ret = NULL;
		switch(DVRInfo.type)
		{
		case DeviceTypeDH:
			{
				int err = 0;
				NET_DEVICEINFO info;// 用于返回设备信息
				memset(&info, 0 ,sizeof(NET_DEVICEINFO));
				long ret = CLIENT_Login(ip, DVRInfo.port, userName, password, &info, &err);	// 登录并返回设备信息
			}
			break;
		case DeviceTypeHC:
			{
				NET_DVR_DEVICEINFO_V30 info;
				memset(&info,0,sizeof(NET_DVR_DEVICEINFO_V30));
				long ret = NET_DVR_Login_V30(ip, DVRInfo.port, userName, password, &info);
			}
			break;
		default:
			assert(false);
			break;
		}
		return ret;
	}

}
