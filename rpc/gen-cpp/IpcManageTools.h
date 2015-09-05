#ifndef IpcManageTools_H
#define IpcManageTools_H

#include <string>
#include <map>

using namespace std;

namespace ipcTools
{
	enum DeviceType
	{
		DeviceTypeHC,
		DeviceTypeDH
	};

	class ConnectInfo
	{
	public:
		char ip[16];
		int port;
		DeviceType type;
		string userName;
		string password;
		int channel;

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
		ConnectManager* Instance();

		long connectDVR(const ConnectInfo &info);

	private:
		ConnectManager() {};

		long connectHCDVR(const ConnectInfo &info);
		long connectDHDVR(const ConnectInfo &info);

	private:
		map<ConnectInfo, long> m_ConnectList;

	};

}


#endif