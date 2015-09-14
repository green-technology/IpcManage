#include "IpcManageTools.h"
#include "hc\HCNetSDK.h"

void CALLBACK exceptionCallBack(DWORD dwType, LONG lUserID, LONG lHandle, void *pUser)
{
	LOG("\n########����SDK�����ж�########\n");
	LOG("\n########SDK�����ж�########\n");
}

namespace ipcTools
{
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

		switch(dwPTZCommand)
		{
		case HIK_PTZ_CommandType::HIK_TILT_UP:					// ����
		case HIK_PTZ_CommandType::HIK_TILT_DOWN:					// ����
		case HIK_PTZ_CommandType::HIK_PAN_LEFT:					// ����
		case HIK_PTZ_CommandType::HIK_PAN_RIGHT:					//����
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
			LOG("ִ�к�����̨��������ʧ�ܣ�\n");
			return FALSE;
		}

		return TRUE;
	}

}

