#include "IpcManageTools.h"
#include <Windows.h>
#include "dh\dhnetsdk.h"
#include "glog\logging.h"

void CALLBACK DisConnectCallBack(LONG lLoginID, char *pchDVRIP, LONG nDVRPort, DWORD dwUser)
{
	//LOG("\n########大华SDK连接中断########\n");
	//LOG(pchDVRIP);
	//LOG("\n########SDK连接中断########\n");
}

namespace ipcTools
{
	int DH_PTZ_COMMAND[] = {
		DH_PTZ_UP_CONTROL,				// 向上    
		DH_PTZ_DOWN_CONTROL,			// 向下    
		DH_PTZ_LEFT_CONTROL,			// 向左	
		DH_PTZ_RIGHT_CONTROL,			// 向右
		DH_PTZ_ZOOM_ADD_CONTROL,		// 变倍+
		DH_PTZ_ZOOM_DEC_CONTROL,		// 变倍-
		DH_PTZ_FOCUS_ADD_CONTROL,		// 调焦+
		DH_PTZ_FOCUS_DEC_CONTROL,		// 调焦-
		DH_PTZ_APERTURE_ADD_CONTROL,	// 光圈+
		DH_PTZ_APERTURE_DEC_CONTROL,	// 光圈-
		DH_PTZ_POINT_MOVE_CONTROL,		// 转至预置点
		DH_PTZ_POINT_SET_CONTROL,		// 设置

		// 大华接口中的灯光控制值只有一个，对应到我们系统中的两个值，调用一次切换一次状态
		DH_EXTPTZ_LIGHTCONTROL,			// 打开灯光 PTZ_LAMP_OPEN
		DH_EXTPTZ_LIGHTCONTROL,			// 关闭灯光 PTZ_LAMP_CLOSE

		// 大华的灯光雨刷控制
		// 因此需要借助到扩展参数param1（param1 = 0x01开启‚ param1 = x00关闭）
		DH_EXTPTZ_AUXIOPEN,			// 打开雨刷对应打开辅助开关1
		DH_EXTPTZ_AUXICLOSE,			// 关闭雨刷对应关闭辅助开关1

		// 大华、海康的设备未发现有透雾的接口
		DH_EXTPTZ_AUXIOPEN,			// 打开透雾对应打开辅助开关2
		DH_EXTPTZ_AUXICLOSE,			// 关闭透雾对应关闭辅助开关2

		/*
		辅助开关开, param1参数作为辅助点
		param1 = 23, 开背光补偿
		param1 = 24, 开数字变倍能
		param1 = 27, 开夜视功能
		param1 = 41, 摄像机亮度增
		param1 = 43, 开预置题显示
		*/
		DH_EXTPTZ_AUXIOPEN,				// 打开辅助设备
		/*
		辅助开关关, param1参数作为辅助点
		param1 = 23, 关背光补偿
		param1 = 24, 关数字变倍能
		param1 = 27, 关夜视功能
		param1 = 41, 摄像机亮度减
		param1 = 43, 关预置标题显示
		*/
		DH_EXTPTZ_AUXICLOSE,			// 关闭辅助设备

		DH_EXTPTZ_LEFTTOP,				// 左上
		DH_EXTPTZ_RIGHTTOP,				// 右上
		DH_EXTPTZ_LEFTDOWN,				// 左下
		DH_EXTPTZ_RIGHTDOWN				// 右下
	};

	BOOL convertCommandDH(DWORD src, DWORD &dst)
	{
		if(src > sizeof(DH_PTZ_COMMAND))
			return FALSE;
		dst = DH_PTZ_COMMAND[src];
		return TRUE;
	}

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

		DWORD cmd;
		if (!convertCommandDH(dwPTZCommand, cmd))
			return FALSE;

		if (cmd >= DH_EXTPTZ_LEFTTOP)
		{
			bRet=CLIENT_DHPTZControl(hLogin, channel, cmd, (BYTE)param1, (BYTE)param2, 0, FALSE);
		} 
		else
		{
			bRet= CLIENT_DHPTZControl(hLogin, channel, cmd, 0, (BYTE)param2, 0, dwStop);
		}
		if(!bRet)
		{
			DWORD dwError = CLIENT_GetLastError();
			//LOG("执行大华云台控制命令失败！\n");
			return FALSE;
		}

		return TRUE;
	}

	BOOL ConnectManager::closeConnectDH(LONG hLogin)
	{
		BOOL ret = CLIENT_Logout(hLogin);
		if(!ret)
		{
			DWORD dwError = CLIENT_GetLastError();
			LOG(ERROR)<<"大华断开连接失败:"<<dwError;
		}
		return ret;
	}

}
