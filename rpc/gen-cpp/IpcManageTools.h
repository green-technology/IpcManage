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
	class ConnectInfo
	{
	private:
		IPCResourceDataPacket *m_data;
	public:
		char ip[16];
		int port;
		DeviceType::type type;
		string userName;
		string password;
		int channel;

		ConnectInfo()
			: port(-1)
			, type(DeviceType::DeviceTypeNone)
			, userName("")
			, password("")
			,channel(-1)
		{
			memset(ip, 0, 16);
		}

		friend bool operator == (const ConnectInfo &lhs, const ConnectInfo &rhs)
		{
			bool ret = false;
			if(strcmp(lhs.ip, rhs.ip) == 0 && lhs.port == rhs.port)
				ret = true;
			return ret;
		}

		friend bool operator < (const ConnectInfo &lhs, const ConnectInfo &rhs)
		{
			bool ret = false;
			int cmp = strcmp(lhs.ip, rhs.ip);
			if (cmp < 0)
				ret = true;
			else if (ret == 0 && lhs.port < rhs.port)
				ret = true;
			return ret;
		}
	};

	class ConnectManager
	{
	public:
		static ConnectManager* Instance();

		BOOL connectDVR(const IPCResourceDataPacket* ipc);
		BOOL	PTZControl(const PTZControlDataPacket &commad);


	private:
		ConnectManager() {};

		BOOL initClient();
		BOOL initClientDH();
		BOOL initClientHC();

		LONG connectHCDVR(char *sDVRIP, WORD wDVRPort, char *sUserName, char *sPassword);
		LONG connectDHDVR(char *sDVRIP, WORD wDVRPort, char *sUserName, char *sPassword);

		BOOL PTZControlDH(LONG hLogin, int channel, DWORD dwPTZCommand, DWORD param1, DWORD param2, DWORD param3, BOOL dwStop);
		BOOL PTZControlHC(LONG hLogin, DWORD dwPTZCommand, DWORD param1, DWORD param2, DWORD param3, BOOL dwStop);

		void getDeviceType(LONG hLogin);

	private:
		map<LONG, ConnectInfo> m_ConnectList;

	};

}


#endif