#include "IpcManageTools.h"
#include "hc\HCNetSDK.h"

void CALLBACK exceptionCallBack(DWORD dwType, LONG lUserID, LONG lHandle, void *pUser)
{
	LOG("\n########海康SDK连接中断########\n");
	LOG("\n########SDK连接中断########\n");
}

namespace ipcTools
{
	typedef enum _Hik_PTZ_CommandType
	{
		// 通用云台操作
		HIK_LIGHT_PWRON		= 2,					// 接通灯光电源 
		HIK_WIPER_PWRON		= 3,					// 接通雨刷开关 
		HIK_FAN_PWRON		= 4,					// 接通风扇开关 
		HIK_HEATER_PWRON	= 5,					// 接通加热器开关 
		HIK_AUX_PWRON1		= 6,					// 接通辅助设备开关 
		HIK_AUX_PWRON2		= 7,					// 接通辅助设备开关 
		HIK_ZOOM_IN			= 11,					// 焦距变大(倍率变大) 
		HIK_ZOOM_OUT		= 12,					// 焦距变小(倍率变小) 
		HIK_FOCUS_NEAR		= 13,					// 焦点前调 
		HIK_FOCUS_FAR		= 14,					// 焦点后调 
		HIK_IRIS_OPEN		= 15,					// 光圈扩大 
		HIK_IRIS_CLOSE		= 16,					// 光圈缩小 
		HIK_TILT_UP			= 21,					// 云台上仰 
		HIK_TILT_DOWN		= 22,					// 云台下俯 
		HIK_PAN_LEFT		= 23,					// 云台左转 
		HIK_PAN_RIGHT		= 24,					// 云台右转
		HIK_UP_LEFT			= 25,					// 云台上仰和左转 
		HIK_UP_RIGHT		= 26,					// 云台上仰和右转 
		HIK_DOWN_LEFT		= 27,					// 云台下俯和左转 
		HIK_DOWN_RIGHT		= 28,					// 云台下俯和右转 
		HIK_PAN_AUTO		= 29,					// 云台左右自动扫描

		// 预置点设置
		HIK_SET_PRESET			= 8,				// 设置预置点 
		HIK_CLE_PRESET			= 9,				// 清除预置点 
		HIK_GOTO_PRESET			= 39,				// 转到预置点 


	} HIK_PTZ_CommandType;

	// 海康云台控制命令映射到力方内部命令
	int HIK_PTZ_COMMAND[] = {
		HIK_TILT_UP,					// 向上
		HIK_TILT_DOWN,					// 向下
		HIK_PAN_LEFT,					// 向左
		HIK_PAN_RIGHT,					// 向右
		HIK_ZOOM_IN,					// 变倍+
		HIK_ZOOM_OUT,					// 变倍-
		HIK_FOCUS_NEAR,					// 调焦+
		HIK_FOCUS_FAR,					// 调焦-
		HIK_IRIS_OPEN,					// 光圈+
		HIK_IRIS_CLOSE,					// 光圈-
		HIK_GOTO_PRESET,				// 转至预置点,调用的是 NET_DVR_PTZPreset
		HIK_SET_PRESET,					// 设置预置点,调用的是 NET_DVR_PTZPreset
		HIK_LIGHT_PWRON,				// 打开灯光 - 开关量
		HIK_LIGHT_PWRON,				// 关闭灯光 - 开关量
		HIK_WIPER_PWRON,				// 打开雨刷 - 开关量
		HIK_WIPER_PWRON,				// 关闭雨刷 - 开关量
		HIK_FAN_PWRON,					// 打开透雾 - 接通风扇开关
		HIK_FAN_PWRON,					// 关闭透雾 - 接通风扇开关
		HIK_AUX_PWRON1,					// 打开辅助设备 - 开关量
		HIK_AUX_PWRON1,					// 关闭辅助设备 - 开关量
		HIK_UP_LEFT,					// 左上
		HIK_UP_RIGHT,					// 右上
		HIK_DOWN_LEFT,					// 左下
		HIK_DOWN_RIGHT					// 右下
	};

	BOOL convertCommandHC(DWORD src, DWORD &dst)
	{
		if(src > sizeof(HIK_PTZ_COMMAND))
			return FALSE;
		dst = HIK_PTZ_COMMAND[src];
		return TRUE;
	}

	BOOL ConnectManager::initClientHC()
	{
		if(!NET_DVR_Init())
			return FALSE;
		if(!NET_DVR_SetConnectTime(2000, 1))
			return FALSE;
		if(!NET_DVR_SetReconnect(10000, true))
			return FALSE;
		if(!NET_DVR_SetExceptionCallBack_V30( WM_NULL, NULL, exceptionCallBack, NULL ))
			return FALSE;
		return TRUE;
	}

	LONG ConnectManager::connectHCDVR(char *sDVRIP, WORD wDVRPort, char *sUserName, char *sPassword)
	{
		NET_DVR_DEVICEINFO_V30 info;
		memset(&info,0,sizeof(NET_DVR_DEVICEINFO_V30));
		LONG ret = NET_DVR_Login_V30(sDVRIP, wDVRPort, sUserName, sPassword, &info);
		return ret;
	}
	
	BOOL ConnectManager::PTZControlHC(LONG hLogin, DWORD dwPTZCommand, DWORD param1, DWORD param2, DWORD param3, BOOL dwStop)
	{
		BOOL bRet = FALSE;

		DWORD cmd;
		if (!convertCommandHC(dwPTZCommand, cmd))
			return bRet;

		switch(dwPTZCommand)
		{
		case HIK_PTZ_CommandType::HIK_TILT_UP:					// 向上
		case HIK_PTZ_CommandType::HIK_TILT_DOWN:					// 向下
		case HIK_PTZ_CommandType::HIK_PAN_LEFT:					// 向左
		case HIK_PTZ_CommandType::HIK_PAN_RIGHT:					//向右
		case HIK_PTZ_CommandType::HIK_ZOOM_IN:
		case HIK_PTZ_CommandType::HIK_ZOOM_OUT:
		case HIK_PTZ_CommandType::HIK_FOCUS_NEAR:
		case HIK_PTZ_CommandType::HIK_FOCUS_FAR:
		case HIK_PTZ_CommandType::HIK_IRIS_OPEN:
		case HIK_PTZ_CommandType::HIK_IRIS_CLOSE:
			bRet=NET_DVR_PTZControlWithSpeed(hLogin, dwPTZCommand, dwStop, param2);
			break;
		case HIK_PTZ_CommandType::HIK_SET_PRESET:
		case HIK_PTZ_CommandType::HIK_GOTO_PRESET:
			bRet=NET_DVR_PTZPreset(hLogin, dwPTZCommand, param2);
			break;
		case HIK_PTZ_CommandType::HIK_WIPER_PWRON:
			bRet=NET_DVR_PTZControl(hLogin, dwPTZCommand, dwStop);
		default:
			break;
		}

		if(!bRet)
		{
			LOG("执行海康云台控制命令失败！\n");
			return FALSE;
		}

		return TRUE;
	}

}

