#ifndef IpcManageTools_H
#define IpcManageTools_H

#include <string>
#include <map>

using namespace std;

namespace ipcTools
{
	enum DeviceType
	{
		DeviceTypeNone,
		DeviceTypeHC,
		DeviceTypeDH
	};

	struct ConnectInfo
	{
	public:
		char ip[16];
		int port;
		DeviceType type;
		string userName;
		string password;
		int channel;

		ConnectInfo()
			: port(-1)
			, type(DeviceTypeNone)
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

		void* connectDVR(const char *ipc);

	private:
		ConnectManager() {};

		long connectHCDVR(const ConnectInfo &info);
		long connectDHDVR(const ConnectInfo &info);

	private:
		map<ConnectInfo, void*> m_ConnectList;

	};

}


#endif