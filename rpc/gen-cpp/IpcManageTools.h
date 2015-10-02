#ifndef IpcManageTools_H
#define IpcManageTools_H

#include "MediaManagerStruct_types.h"
#include "OperateStruct_types.h"
#include <string>
#include <map>

#ifdef _DEBUG
#define LOG(msg) printf(msg)
#else
#define LOG(msg)
#endif

using namespace std;
using namespace  ::ipcms;

namespace ipcTools
{
	class ConnectManager
	{
	public:
		static ConnectManager* Instance();
		
		~ConnectManager();

		BOOL connectDVR(const IPCResourceDataPacket* ipc);
		BOOL	PTZControl(const PTZControlDataPacket &commad);

		void closeConnect(LONG);

	private:
		ConnectManager() {};
		static ConnectManager* instance;

		BOOL initClient();
		BOOL initClientDH();
		BOOL initClientHC();

		LONG connectHCDVR(char *sDVRIP, WORD wDVRPort, char *sUserName, char *sPassword);
		LONG connectDHDVR(char *sDVRIP, WORD wDVRPort, char *sUserName, char *sPassword);

		BOOL PTZControlDH(LONG hLogin, int channel, DWORD dwPTZCommand, DWORD param1, DWORD param2, DWORD param3, BOOL dwStop);
		BOOL PTZControlHC(LONG hLogin, DWORD dwPTZCommand, DWORD param1, DWORD param2, DWORD param3, BOOL dwStop);

		void getDeviceType(LONG hLogin);

		BOOL closeConnectDH(LONG hLogin);
		BOOL closeConnectHC(LONG hLogin);

	private:
		map<LONG, IPCResourceDataPacket*> m_ConnectList;

	};

}


#endif