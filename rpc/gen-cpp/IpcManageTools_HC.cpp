#include "IpcManageTools.h"
#include "hc\HCNetSDK.h"

void CALLBACK exceptionCallBack(DWORD dwType, LONG lUserID, LONG lHandle, void *pUser)
{
	LOG("\n########����SDK�����ж�########\n");
	LOG("\n########SDK�����ж�########\n");
}

namespace ipcTools
{
	typedef enum _Hik_PTZ_CommandType
	{
		// ͨ����̨����
		HIK_LIGHT_PWRON		= 2,					// ��ͨ�ƹ��Դ 
		HIK_WIPER_PWRON		= 3,					// ��ͨ��ˢ���� 
		HIK_FAN_PWRON		= 4,					// ��ͨ���ȿ��� 
		HIK_HEATER_PWRON	= 5,					// ��ͨ���������� 
		HIK_AUX_PWRON1		= 6,					// ��ͨ�����豸���� 
		HIK_AUX_PWRON2		= 7,					// ��ͨ�����豸���� 
		HIK_ZOOM_IN			= 11,					// ������(���ʱ��) 
		HIK_ZOOM_OUT		= 12,					// �����С(���ʱ�С) 
		HIK_FOCUS_NEAR		= 13,					// ����ǰ�� 
		HIK_FOCUS_FAR		= 14,					// ������ 
		HIK_IRIS_OPEN		= 15,					// ��Ȧ���� 
		HIK_IRIS_CLOSE		= 16,					// ��Ȧ��С 
		HIK_TILT_UP			= 21,					// ��̨���� 
		HIK_TILT_DOWN		= 22,					// ��̨�¸� 
		HIK_PAN_LEFT		= 23,					// ��̨��ת 
		HIK_PAN_RIGHT		= 24,					// ��̨��ת
		HIK_UP_LEFT			= 25,					// ��̨��������ת 
		HIK_UP_RIGHT		= 26,					// ��̨��������ת 
		HIK_DOWN_LEFT		= 27,					// ��̨�¸�����ת 
		HIK_DOWN_RIGHT		= 28,					// ��̨�¸�����ת 
		HIK_PAN_AUTO		= 29,					// ��̨�����Զ�ɨ��

		// Ԥ�õ�����
		HIK_SET_PRESET			= 8,				// ����Ԥ�õ� 
		HIK_CLE_PRESET			= 9,				// ���Ԥ�õ� 
		HIK_GOTO_PRESET			= 39,				// ת��Ԥ�õ� 


	} HIK_PTZ_CommandType;

	// ������̨��������ӳ�䵽�����ڲ�����
	int HIK_PTZ_COMMAND[] = {
		HIK_TILT_UP,					// ����
		HIK_TILT_DOWN,					// ����
		HIK_PAN_LEFT,					// ����
		HIK_PAN_RIGHT,					// ����
		HIK_ZOOM_IN,					// �䱶+
		HIK_ZOOM_OUT,					// �䱶-
		HIK_FOCUS_NEAR,					// ����+
		HIK_FOCUS_FAR,					// ����-
		HIK_IRIS_OPEN,					// ��Ȧ+
		HIK_IRIS_CLOSE,					// ��Ȧ-
		HIK_GOTO_PRESET,				// ת��Ԥ�õ�,���õ��� NET_DVR_PTZPreset
		HIK_SET_PRESET,					// ����Ԥ�õ�,���õ��� NET_DVR_PTZPreset
		HIK_LIGHT_PWRON,				// �򿪵ƹ� - ������
		HIK_LIGHT_PWRON,				// �رյƹ� - ������
		HIK_WIPER_PWRON,				// ����ˢ - ������
		HIK_WIPER_PWRON,				// �ر���ˢ - ������
		HIK_FAN_PWRON,					// ��͸�� - ��ͨ���ȿ���
		HIK_FAN_PWRON,					// �ر�͸�� - ��ͨ���ȿ���
		HIK_AUX_PWRON1,					// �򿪸����豸 - ������
		HIK_AUX_PWRON1,					// �رո����豸 - ������
		HIK_UP_LEFT,					// ����
		HIK_UP_RIGHT,					// ����
		HIK_DOWN_LEFT,					// ����
		HIK_DOWN_RIGHT					// ����
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

