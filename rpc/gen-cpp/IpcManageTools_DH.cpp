#include "IpcManageTools.h"
#include <Windows.h>
#include "dh\dhnetsdk.h"

void CALLBACK DisConnectCallBack(LONG lLoginID, char *pchDVRIP, LONG nDVRPort, DWORD dwUser)
{
	LOG("\n########大华SDK连接中断########\n");
	LOG(pchDVRIP);
	LOG("\n########SDK连接中断########\n");
}

namespace ipcTools
{
	BOOL ConnectManager::initClientDH()
	{
		BOOL ret = CLIENT_Init(DisConnectCallBack, NULL);
		return ret;
	}

	LONG ConnectManager::connectDHDVR(char *sDVRIP, WORD wDVRPort, char *sUserName, char *sPassword)
	{
		int err = 0;
		NET_DEVICEINFO info;// 用于返回设备信息
		memset(&info, 0 ,sizeof(NET_DEVICEINFO));
		LONG ret = CLIENT_Login(sDVRIP, wDVRPort, sUserName, sPassword, &info, &err);	// 登录并返回设备信息
		return ret;
	}

	BOOL ConnectManager::PTZControlDH(LONG hLogin, int channel, DWORD dwPTZCommand, DWORD param1, DWORD param2, DWORD param3, BOOL dwStop)
	{
		BOOL  bRet=FALSE;

		switch(dwPTZCommand)
		{
		case DH_EXTPTZ_AUXIOPEN:
		case DH_EXTPTZ_AUXICLOSE:
			bRet=CLIENT_DHPTZControlEx(hLogin, channel, dwPTZCommand, param1, 0, 0, FALSE);
			break;
		default:
			bRet= CLIENT_DHPTZControlEx(hLogin, channel, dwPTZCommand, param1, param2, param3, dwStop);
			break;
		}
		if(!bRet)
		{
			LOG("执行大华云台控制命令失败！\n");
			return FALSE;
		}

		return TRUE;
	}


}
