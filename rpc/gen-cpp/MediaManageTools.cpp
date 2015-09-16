#include "MediaManageTools.h"
#include "CppSQLite3.h"
#include <string>

using namespace std;

namespace ipcTools
{
	const char* g_szFile = "rfserv.db";

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


	void MediaManager::initFromLocal()
	{
		CppSQLite3DB database;
		database.open(g_szFile);

		string		strCameraType;			// 摄像头类型
		string		strCameraName;			// 摄像头名称
		string		strMode;				// 摄像头类型(DVR、NVR、IPC，，，)
		string		strProvider;			// 设备厂家(大华、海康、海思，，，)
		string		strCodec;				// 编码格式
		string		strLogin;				// 连接到设备时登录的用户名
		string		strPassword;			// 登录密码
		string		strIp;					// 设备的IP地址
		string		strPort;				// 设备连接端口号
		string		strCnlId;				// 设备连接通道号
		string		IsMultiCast;			// 是否广播数据
		string		strMultiCastAddress;	// 广播地址
		string		strMultiCastPort;		// 广播端口
		string		strRecordType;			// 录像类型

		string strSql = "SELECT * FROM [CAMERA]";
		EnterCriticalSection(&m_CriticalSectionDevice);

		try
		{
			CppSQLite3DB database;
			database.open(g_szFile);

			//int result = database.setKey( "pwd", 3 );		// 添加密码
			//result = database.resetKey( "sqlite3", 7 );	// 修改密码

			IPCResourceDataPacket *lpCamera = NULL;
			CppSQLite3Query query = database.execQuery(strSql.c_str());
			while (!query.eof())
			{
				strCameraType			= query.getStringField(2);
				strCameraName			= query.getStringField(3);
				strMode					= query.getStringField(4);
				strProvider				= query.getStringField(5);
				strCodec				= query.getStringField(6);
				strLogin				= query.getStringField(7);
				strPassword				= query.getStringField(8);
				strIp					= query.getStringField(9);
				strPort					= query.getStringField(10);
				strCnlId				= query.getStringField(11);
				string strMul			= query.getStringField(12);
				strMultiCastAddress		= query.getStringField(13);
				strMultiCastPort		= query.getStringField(14);
				strRecordType			= query.getStringField(15);

				lpCamera				= new IPCResourceDataPacket();

				//lpCamera->deviceType			= UTF_82ASCII(strCameraType);
				//lpCamera->strCameraName			= UTF_82ASCII(strCameraName);
				///lpCamera->strMode				= UTF_82ASCII(strMode);
				//lpCamera->strProvider			= UTF_82ASCII(strProvider);
				lpCamera->userName				= UTF_82ASCII(strLogin);
				lpCamera->password			= UTF_82ASCII(strPassword);
				lpCamera->IP					= UTF_82ASCII(strIp);
				//lpCamera->port				= UTF_82ASCII(strPort);
				//lpCamera->strCnlId				= UTF_82ASCII(strCnlId);
				HANDLE hRes = NULL;

				query.nextRow();
				m_DeviceResource.insert(map<HANDLE/*resource*/, IPCResourceDataPacket*>::value_type(hRes, lpCamera));
			}
		}
		catch(...)
		{
			// 
		}

		LeaveCriticalSection(&m_CriticalSectionDevice);
	}

}