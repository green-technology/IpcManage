#include "IpcManageServerHandler.h"
#include "IpcManageTools.h"
#include "Tools.h"

#include "assert.h"

IpcManageServerHandler::IpcManageServerHandler()
{

}

void IpcManageServerHandler::UserLogin( ::ipcms::UserLoginReturnStruct& _return, const std::string& userName) {
	// Your implementation goes here
	printf("UserLogin\n");

	LOG(userName.c_str());

	//用户验证，以用户名作为KEY
	map<string, UserLoginInfoDataPacket>::iterator iter = m_userLoginList.find(userName);
	if(iter != m_userLoginList.end())
	{
		_return.ErrorNum = FALSE;
		return;
	}

	//分配资源
	HANDLE hLogin;
	if (!getLoginResource(hLogin))
	{
		_return.ErrorNum = FALSE;
	}
	else
	{
		UserLoginInfoDataPacket info;
		info.hLogin = (int64_t)hLogin;
		info.UserID = "test";

		string tmpStr= userName;
		tmpStr += GetCurrentTimeString();
		info.SessionID = getMD5(tmpStr);	// create sessionid

		m_userLoginList[userName] = info;
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

#ifdef _DEBUG
	ResourceInfoReturnStruct item;
	item.resourceType = ResourceType::ResourceTypeIPC;
	item.hResource = 0;
	item.hasPLZ = true;
	item.timeStart = 0;
	item.timeEnd = 0;

	_return.push_back(item);
#endif

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
	getPTZResource(hRes, hPTZ);
	if (hPTZ == NULL)
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

	HANDLE hPTZ = (HANDLE)command.hPTZ;
	map<HANDLE, HANDLE>::iterator iter = m_PTZHandler.find(hPTZ);
	if (iter == m_PTZHandler.end())
	{
		_return.result = PTZControlReturnType::PTZControlReturnTypeInvalidHandle;
		return;
	}

	ipcTools::ConnectManager::Instance();
}

bool IpcManageServerHandler::UserLogout(const  ::ipcms::UserVerificationDataPacket& userVerify) {
	// Your implementation goes here
	printf("UserLogout\n");

	if (!authentication(userVerify))
		return false;
	//releaseLoginResource(hLogin);

	return true;
}

bool IpcManageServerHandler::getLoginResource(HANDLE &handle)
{
	bool ret = false;
#ifdef _DEBUG
	handle = 0;
	ret = true;
#endif
	return ret;
}

void IpcManageServerHandler::releaseLoginResource(HANDLE handle)
{

}

void IpcManageServerHandler::confirmPTZControl(HANDLE hUser, HANDLE hIPC)
{

}

void IpcManageServerHandler::getPTZResource(HANDLE hRes, LONG &hPTZ)
{
	HANDLE currentUser = NULL;

	map<HANDLE, IPCResourceDataPacket>::iterator iter = m_mediaResource.find(hRes);
	if (iter == m_mediaResource.end())
	{
		return;
	}

	if (iter->second.hPTZ == NULL)
	{
		//通过SDK建立连接
		hPTZ = ipcTools::ConnectManager::Instance()->connectDVR("");
		if(hPTZ != NULL)
			iter->second.hPTZ = (int64_t)hPTZ;
	}
	else
	{
		hPTZ = (LONG)iter->second.hPTZ;
	}
	return;
}

void IpcManageServerHandler::releasePTZResource(HANDLE handle)
{

}

bool IpcManageServerHandler::authentication(const UserVerificationDataPacket &data)
{
	return true;
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

