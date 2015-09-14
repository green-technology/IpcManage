#include "IpcManageTools.h"
#include <Windows.h>
#include "dh\dhnetsdk.h"

void CALLBACK DisConnectCallBack(LONG lLoginID, char *pchDVRIP, LONG nDVRPort, DWORD dwUser)
{
	LOG("\n########��SDK�����ж�########\n");
	LOG(pchDVRIP);
	LOG("\n########SDK�����ж�########\n");
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
		NET_DEVICEINFO info;// ���ڷ����豸��Ϣ
		memset(&info, 0 ,sizeof(NET_DEVICEINFO));
		LONG ret = CLIENT_Login(sDVRIP, wDVRPort, sUserName, sPassword, &info, &err);	// ��¼�������豸��Ϣ
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
			LOG("ִ�д���̨��������ʧ�ܣ�\n");
			return FALSE;
		}

		return TRUE;
	}


}
