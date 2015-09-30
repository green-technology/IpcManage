#include "IpcManageServerHandler.h"
#include "IpcManageTools.h"
#include "MediaManageTools.h"

#include "assert.h"

IpcManageServerHandler::IpcManageServerHandler()
{
	initMediaResource();
}

void IpcManageServerHandler::UserLogin( ::ipcms::UserLoginReturnStruct& _return, const std::string& userName) {
	// Your implementation goes here
	printf("UserLogin\n");

	LOG(userName.c_str());

	//用户验证，以用户名作为KEY
	for (map<string, string>::iterator iter = m_userLoginList.begin();iter != m_userLoginList.end();iter++)
	{
		if (iter->second == userName)
		{
			_return.ErrorNum = FALSE;
			return;
		}
	}
	
	//分配资源
	string id;
	if (!getLoginResource(userName, id))
	{
		_return.ErrorNum = FALSE;
	}
	else
	{
		UserLoginInfoDataPacket info;
		info.UserID = id;
		info.SessionID = "test";

		_return.ErrorNum = TRUE;
		_return.UserID = info.UserID;
		_return.SessionID = info.SessionID;

		LOG(info.UserID.c_str());

	}
}

void IpcManageServerHandler::GetResInfoList(std::vector< ::ipcms::ResourceInfoReturnStruct> & _return, const  ::ipcms::UserVerificationDataPacket& userVerify, const  ::ipcms::ResourceType::type resType) {
	printf("GetResInfoList\n");

	if(!authentication(userVerify))
		return;

	switch(resType)
	{
	case ResourceType::ResourceTypeALL:
	case ResourceType::ResourceTypeIPC:
		{
			const map<HANDLE/*resource*/, IPCResourceDataPacket *> resMap = ipcTools::MediaManager::Instance()->getAllResource();
			for (map<HANDLE/*resource*/, IPCResourceDataPacket *>::const_iterator iter = resMap.begin(); iter != resMap.end(); iter++)
			{
				ResourceInfoReturnStruct item;
				item.resourceType = ResourceType::ResourceTypeIPC;
				item.hResource = (int64_t)iter->first;
				item.hasPLZ = true;
				item.timeStart = 0;
				item.timeEnd = 0;

				_return.push_back(item);
				
			}
		}
		if(resType != ResourceType::ResourceTypeALL)
			break;
	case ResourceType::ResourceTypeReplay:
		{

		}
		break;
	default:
		assert(FALSE);
		break;
	}

}

int8_t IpcManageServerHandler::PlayVideo(const  ::ipcms::UserVerificationDataPacket& userVerify, const  ::ipcms::PlayVideoDataPacket& playVideo) {
	// Your implementation goes here
	printf("PlayVideo\n");
	return 0;
}

void IpcManageServerHandler::RequestPTZControl( ::ipcms::RequestPTZControlReturnStruct&  _return, const  ::ipcms::UserVerificationDataPacket& /* userVerify */, const  ::ipcms::RequestPTZControlDataPacket&  requestPTZ) {
	printf("RequestPTZControl\n");

	HANDLE hRes = (HANDLE)requestPTZ.hResource;
	LONG hPTZ = NULL;
	if (getPTZResource(hRes, hPTZ) == FALSE)
	{
		_return.hPTZ = NULL;
		_return.result = -1;
	}
	else
	{
		map<LONG, string>::iterator iterUser = m_PTZUserList.find(hPTZ);
		if (iterUser != m_PTZUserList.end())
		{
			_return.hPTZ = NULL;
			_return.result = FALSE;
			_return.userName = iterUser->second;
		}
		else
		{
			_return.hPTZ = (int64_t)hPTZ;
			_return.result = TRUE;
		}
	}
}

void IpcManageServerHandler::PTZControl(::ipcms::PTZControlReturnStruct&  _return , const ::ipcms::UserVerificationDataPacket&  userVerify , const ::ipcms::PTZControlDataPacket&  command )
{
	// Your implementation goes here
	printf("PTZControl\n");

	if(!authentication(userVerify))
		return;

	LONG hPTZ = (LONG)command.hPTZ;
	map<LONG, HANDLE>::iterator iter = m_PTZHandler.find(hPTZ);
	if (iter == m_PTZHandler.end())
	{
		_return.result = PTZControlReturnType::PTZControlReturnTypeInvalidHandle;
		return;
	}

	if(ipcTools::ConnectManager::Instance()->PTZControl(command) == TRUE)
		_return.result = PTZControlReturnType::PTZControlReturnTypeSuccess;
	else
		_return.result = PTZControlReturnType::PTZControlReturnTypeError;
}

bool IpcManageServerHandler::UserLogout(const  ::ipcms::UserVerificationDataPacket& userVerify) {
	// Your implementation goes here
	printf("UserLogout\n");

	if (!authentication(userVerify))
		return false;
	releaseLoginResource(userVerify.UserID);

	return true;
}

bool IpcManageServerHandler::getLoginResource(const string userName, string& id)
{
	SYSTEMTIME loctime;
	GetLocalTime(&loctime);
	char szTime[128]={0};
	sprintf_s(szTime, "%.4d%.2d%.2d%.2d%.2d%.2d", loctime.wYear, loctime.wMonth, loctime.wDay, loctime.wHour, loctime.wMinute, loctime.wSecond);

	id = userName + szTime;

	m_userLoginList[id] = userName;

	return true;
}

void IpcManageServerHandler::releaseLoginResource(const string id)
{
	map<string, string>::iterator iter = m_userLoginList.find(id);
	if (iter != m_userLoginList.end())
	{
		m_userLoginList.erase(iter);
	}
}

void IpcManageServerHandler::confirmPTZControl(HANDLE hUser, HANDLE hIPC)
{

}

BOOL IpcManageServerHandler::getPTZResource(HANDLE hRes, LONG &hPTZ)
{
	BOOL ret = FALSE;

	const IPCResourceDataPacket* ipc = ipcTools::MediaManager::Instance()->getResource(hRes);
	if (ipc != NULL)
	{
		//通过SDK建立连接
		if(ipcTools::ConnectManager::Instance()->connectDVR(ipc) != FALSE)
		{
			hPTZ = ipc->hPTZ;
			m_PTZHandler[hPTZ] = hRes;
			ret = TRUE;
		}
	}

	return ret;
}

void IpcManageServerHandler::releasePTZResource(HANDLE handle)
{

}

bool IpcManageServerHandler::authentication(const UserVerificationDataPacket &data) const
{
	map<string, string>::const_iterator iter = m_userLoginList.find(data.UserID);
	if (iter != m_userLoginList.end())
	{
		return true;
	}
	return false;
}

void IpcManageServerHandler::initMediaResource()
{
#ifdef _DEBUG
	HANDLE hRes = 0;
	IPCResourceDataPacket res;
	res.IP = "14.23.115.10";
	res.port = 8000;
	res.userName = "admin";
	res.password = "12345";

	m_mediaResource[hRes] = res;
#endif
	//在这里添加资源管理的代码
	
}

