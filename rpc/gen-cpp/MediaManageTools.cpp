#include "MediaManageTools.h"
#include "CppSQLite3.h"
#include <string>
#include "ReturnStruct_types.h"

using namespace std;

namespace ipcTools
{
#ifdef _DEBUG
	const char* g_szFile = "..\\Debug\\media.db";
#else
	const char* g_szFile = "media.db";
#endif

	//UTF-8转Unicode
	std::wstring Utf82Unicode(const std::string& utf8string)
	{
		int widesize = ::MultiByteToWideChar(CP_UTF8, 0, utf8string.c_str(), -1, NULL, 0);
		if (widesize == ERROR_NO_UNICODE_TRANSLATION)
		{
			throw std::exception("Invalid UTF-8 sequence.");
		}
		if (widesize == 0)
		{
			throw std::exception("Error in conversion.");
		}

		std::vector<wchar_t> resultstring(widesize);

		int convresult = ::MultiByteToWideChar(CP_UTF8, 0, utf8string.c_str(), -1, &resultstring[0], widesize);

		if (convresult != widesize)
		{
			throw std::exception("La falla!");
		}

		return std::wstring(&resultstring[0]);
	}

	//unicode 转为 ascii
	string WideByte2Acsi(wstring& wstrcode)
	{
		int asciisize = ::WideCharToMultiByte(CP_OEMCP, 0, wstrcode.c_str(), -1, NULL, 0, NULL, NULL);
		if (asciisize == ERROR_NO_UNICODE_TRANSLATION)
		{
			throw std::exception("Invalid UTF-8 sequence.");
		}
		if (asciisize == 0)
		{
			throw std::exception("Error in conversion.");
		}
		std::vector<char> resultstring(asciisize);
		int convresult =::WideCharToMultiByte(CP_OEMCP, 0, wstrcode.c_str(), -1, &resultstring[0], asciisize, NULL, NULL);

		if (convresult != asciisize)
		{
			throw std::exception("La falla!");
		}

		return std::string(&resultstring[0]);
	}

	//utf-8 转 ascii
	string UTF_82ASCII(string& strUtf8Code)
	{
		string strRet("");


		//先把 utf8 转为 unicode 
		wstring wstr = Utf82Unicode(strUtf8Code);

		//最后把 unicode 转为 ascii
		strRet = WideByte2Acsi(wstr);


		return strRet;
	}

	//ascii 转 Unicode
	wstring Acsi2WideByte(string& strascii)
	{
		int widesize = MultiByteToWideChar (CP_ACP, 0, (char*)strascii.c_str(), -1, NULL, 0);
		if (widesize == ERROR_NO_UNICODE_TRANSLATION)
		{
			throw std::exception("Invalid UTF-8 sequence.");
		}
		if (widesize == 0)
		{
			throw std::exception("Error in conversion.");
		}
		std::vector<wchar_t> resultstring(widesize);
		int convresult = MultiByteToWideChar (CP_ACP, 0, (char*)strascii.c_str(), -1, &resultstring[0], widesize);

		if (convresult != widesize)
		{
			throw std::exception("La falla!");
		}

		return std::wstring(&resultstring[0]);
	}

	//Unicode 转 Utf8
	std::string Unicode2Utf8(const std::wstring& widestring)
	{
		int utf8size = ::WideCharToMultiByte(CP_UTF8, 0, widestring.c_str(), -1, NULL, 0, NULL, NULL);
		if (utf8size == 0)
		{
			throw std::exception("Error in conversion.");
		}

		std::vector<char> resultstring(utf8size);

		int convresult = ::WideCharToMultiByte(CP_UTF8, 0, widestring.c_str(), -1, &resultstring[0], utf8size, NULL, NULL);

		if (convresult != utf8size)
		{
			throw std::exception("La falla!");
		}

		return std::string(&resultstring[0]);
	}

	//ascii 转 Utf8
	string ASCII2UTF_8(string& strAsciiCode)
	{
		string strRet("");

		//先把 ascii 转为 unicode 
		wstring wstr = Acsi2WideByte(strAsciiCode);

		//最后把 unicode 转为 utf8
		strRet = Unicode2Utf8(wstr);

		return strRet;
	}

	ipcms::DeviceType::type str2DeviceType(const string strType)
	{
		if (strType.compare("海康") == 0)
		{
			return DeviceType::DeviceTypeHC;
		} 
		else if (strType.compare("大华") == 0)
		{
			return DeviceType::DeviceTypeDH;
		}
		else
			return DeviceType::DeviceTypeUnSupported;

		return DeviceType::DeviceTypeNone;
	}

	string DeviceType2str(ipcms::DeviceType::type type)
	{
		string strType;
		switch(type)
		{
		case DeviceType::DeviceTypeHC:
			strType = "海康";
			break;
		case DeviceType::DeviceTypeDH:
			strType = "大华";
			break;
		default:
			assert(false);
			break;
		}
		return strType;
	}

#define MAX_HANDLE 16

	HANDLE getHandle(ResourceType::type type, HANDLE src)
	{
		assert(!((int)src >> MAX_HANDLE));

		HANDLE dst = src;
		switch(type)
		{
		case ResourceType::ResourceTypeIPC:
			dst = HANDLE((int)src + 1);
			break;
		case ResourceType::ResourceTypeReplay:
			dst = HANDLE(((int)src << 4) + 1);
		default:
			assert(false);
			dst = NULL;
			break;
		}
		return dst;
	}

	void MediaManager::initFromLocal()
	{
		string		strCameraType;			// 摄像头类型
		string		strCameraName;			// 摄像头名称
		string		strLogin;				// 连接到设备时登录的用户名
		string		strPassword;			// 登录密码
		string		strIp;					// 设备的IP地址
		string		strRtspUrl;				//	rtsp流url串 用户播放视频流

		string strSql = "SELECT * FROM [IPC]";
		EnterCriticalSection(&m_CriticalSectionDevice);

		try
		{
			CppSQLite3DB database;
			database.open(g_szFile);

			//int result = database.setKey( "pwd", 3 );		// 添加密码
			//result = database.resetKey( "sqlite3", 7 );	// 修改密码

			m_DeviceResource.clear();

			CppSQLite3Query query = database.execQuery(strSql.c_str());
			while (!query.eof())
			{
				strIp			= query.getStringField(1);
				strCameraType					= query.getStringField(3);
				strLogin				= query.getStringField(4);
				strPassword				= query.getStringField(5);
				strCameraName			= query.getStringField(7);
				strRtspUrl				= query.getStringField(8);

				IPCResourceDataPacket *lpCamera				= new IPCResourceDataPacket();
				lpCamera->deviceType			= str2DeviceType(UTF_82ASCII(strCameraType));
				lpCamera->deviceName			= UTF_82ASCII(strCameraName);
				lpCamera->userName				= UTF_82ASCII(strLogin);
				lpCamera->password			= UTF_82ASCII(strPassword);
				lpCamera->IP					= UTF_82ASCII(strIp);
				lpCamera->rtspUrl			= UTF_82ASCII(strRtspUrl);
				lpCamera->port				= query.getIntField(2);
				lpCamera->channel				= query.getIntField(6);
				lpCamera->ID				= query.getInt64Field(0);
				HANDLE hRes = getHandle(ResourceType::ResourceTypeIPC, (HANDLE)query.getInt64Field(0));

				m_DeviceResource.insert(map<HANDLE/*resource*/, IPCResourceDataPacket*>::value_type(hRes, lpCamera));
				
				query.nextRow();
			}

		}
		catch(...)
		{
			assert(false);
			// 
		}

		LeaveCriticalSection(&m_CriticalSectionDevice);
	}

	void MediaManager::syncDbData()
	{
		string		strCameraType;			// 摄像头类型
		string		strCameraName;			// 摄像头名称
		string		strLogin;				// 连接到设备时登录的用户名
		string		strPassword;			// 登录密码
		string		strIp;					// 设备的IP地址
		string		strRtspUrl;				//	rtsp流url串 用户播放视频流

		string strSql = "SELECT * FROM [IPC]";
		EnterCriticalSection(&m_CriticalSectionDevice);

		try
		{
			CppSQLite3DB database;
			database.open(g_szFile);

			//int result = database.setKey( "pwd", 3 );		// 添加密码
			//result = database.resetKey( "sqlite3", 7 );	// 修改密码

			m_DeviceResource.clear();

			CppSQLite3Query query = database.execQuery(strSql.c_str());
			while (!query.eof())
			{
				strIp			= query.getStringField(1);
				strCameraType					= query.getStringField(3);
				strLogin				= query.getStringField(4);
				strPassword				= query.getStringField(5);
				strCameraName			= query.getStringField(7);
				strRtspUrl				= query.getStringField(8);

				IPCResourceDataPacket *lpCamera				= new IPCResourceDataPacket();
				lpCamera->deviceType			= str2DeviceType(UTF_82ASCII(strCameraType));
				lpCamera->deviceName			= UTF_82ASCII(strCameraName);
				lpCamera->userName				= UTF_82ASCII(strLogin);
				lpCamera->password			= UTF_82ASCII(strPassword);
				lpCamera->IP					= UTF_82ASCII(strIp);
				lpCamera->rtspUrl			= UTF_82ASCII(strRtspUrl);
					lpCamera->port				= query.getIntField(2);
				lpCamera->channel				= query.getIntField(6);
				lpCamera->ID				= query.getInt64Field(0);
				HANDLE hRes = getHandle(ResourceType::ResourceTypeIPC, (HANDLE)query.getInt64Field(0));

				m_DeviceResource.insert(map<HANDLE/*resource*/, IPCResourceDataPacket*>::value_type(hRes, lpCamera));

				query.nextRow();
			}

		}
		catch(...)
		{
			assert(false);
			// 
		}

		LeaveCriticalSection(&m_CriticalSectionDevice);
	}

	const IPCResourceDataPacket* MediaManager::getResource(HANDLE hRes) const
	{
		map<HANDLE, IPCResourceDataPacket *>::const_iterator iter = m_DeviceResource.find(hRes);
		if(iter == m_DeviceResource.end())
			return NULL;
		return iter->second;
	}

	BOOL MediaManager::addDeviceResource(const IPCResourceDataPacket* res)
	{
		char szSql[MAX_PATH] = {0};
		string tmpstr = DeviceType2str(res->deviceType);
		sprintf(szSql, "insert into IPC values(NULL, '%s','%d'",res->IP.c_str(), res->port);
		sprintf(szSql,"%s,'%s','%s','%s','%d'",szSql,tmpstr.c_str(),res->userName.c_str(),res->password.c_str(),res->channel);
		sprintf(szSql,"%s,'%s','%s' )",szSql,res->deviceName.c_str(),res->rtspUrl.c_str());
		//sprintf_s(szSql,MAX_PATH, "insert into IPC values(NULL, '%s','%d','%s','%s', '%s', '%d') ",res->IP.c_str(), res->port,tmpstr.c_str(), res->userName.c_str(), res->password.c_str(), res->channel);

		try
		{
			CppSQLite3DB db;
			db.open(g_szFile);
			int nRet2 = db.execDML("begin transaction;");
			string strSql = szSql;
			nRet2 = db.execDML(ASCII2UTF_8(strSql).c_str());
			nRet2 = db.execDML("commit transaction;");

			HANDLE hRes = (HANDLE)db.lastRowId();

			IPCResourceDataPacket *lpCamera				= new IPCResourceDataPacket();
			*lpCamera = *res;
			m_DeviceResource.insert(map<HANDLE/*resource*/, IPCResourceDataPacket*>::value_type(hRes, lpCamera));

			m_bDataChange = true;
			db.close();
		}
		catch (...)
		{
			return FALSE;
		}

		return TRUE;
	}

	BOOL MediaManager::deleteDeviceResource(const HANDLE handle)
	{
		char szSql[MAX_PATH] = {0};
		if (((int)handle >> MAX_HANDLE) == 0)
			sprintf_s(szSql, "delete from IPC where id=%d", (int)handle);
		else
			sprintf_s(szSql, "delete from Record where id=%d", (int)handle >> MAX_HANDLE);

		try
		{
			CppSQLite3DB db;
			db.open(g_szFile);
			int nRet2 = db.execDML("begin transaction;");
			string strSql = szSql;
			nRet2 = db.execDML(ASCII2UTF_8(strSql).c_str());
			nRet2 = db.execDML("commit transaction;");

			m_bDataChange = true;
			db.close();
		}
		catch (...)
		{
			return FALSE;
		}

		return TRUE;
	}

	BOOL MediaManager::deleteAllDeviceResource()
	{
		char szSql[MAX_PATH] = {0};
		sprintf_s(szSql, "delete from IPC");

		try
		{
			CppSQLite3DB db;
			db.open(g_szFile);
			int nRet2 = db.execDML("begin transaction;");
			string strSql = szSql;
			nRet2 = db.execDML(ASCII2UTF_8(strSql).c_str());
			nRet2 = db.execDML("commit transaction;");

			m_bDataChange = true;
			db.close();
		}
		catch (...)
		{
			return FALSE;
		}

		return TRUE;
	}

	const map<HANDLE/*resource*/, IPCResourceDataPacket *>& MediaManager::getAllResource() const
	{
		if (m_bDataChange)
		{
			Instance()->syncDbData();
		}

		return m_DeviceResource;
	}

}