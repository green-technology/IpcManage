#include "IpcManageServerHandler.h"
#include "IpcManageTools.h"

#include "assert.h"

void IpcManageServerHandler::UserLogin( ::ipcms::UserLoginReturnStruct& _return, const std::string& userName) {
	// Your implementation goes here
	printf("UserLogin\n");

	//用户验证，以用户名作为KEY
	map<string, HANDLE>::iterator iter = m_userLoginList.find(userName);
	if(iter == m_userLoginList.end())
		return;

	//分配资源
	HANDLE hLogin;
	if (!getLoginResource(hLogin))
	{
		_return.ErrorNum = FALSE;
	}
	else
	{
		m_userLoginList[userName] = hLogin;
		_return.ErrorNum = TRUE;
		//_return.UserID = hLogin;
		//_return.SessionID = ;
	}
}

void IpcManageServerHandler::GetResInfoList(std::vector< ::ipcms::ResourceInfoReturnStruct> & _return, const  ::ipcms::UserVerificationDataPacket& userVerify, const int32_t resType) {
}

int8_t IpcManageServerHandler::PlayVideo(const  ::ipcms::UserVerificationDataPacket& userVerify, const  ::ipcms::PlayVideoDataPacket& playVideo) {
	// Your implementation goes here
	printf("PlayVideo\n");
	return 0;
}

 void IpcManageServerHandler::RequestPTZControl( ::ipcms::RequestPTZControlReturnStruct&  _return, const  ::ipcms::UserVerificationDataPacket& /* userVerify */, const  ::ipcms::RequestPTZControlDataPacket&  requestPTZ) {
	HANDLE hRes = (HANDLE)requestPTZ.hResource;
	HANDLE hPTZ = NULL;
	getPTZResource(hRes, hPTZ);
	if (hPTZ == NULL)
	{
		_return.hPTZ = NULL;
		_return.result = -1;
	}
	else
	{
		map<HANDLE, string>::iterator iterUser = m_PTZUserList.find(hPTZ);
		if (iterUser == m_PTZUserList.end())
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

void IpcManageServerHandler::ApplyPTZControl( ::ipcms::ApplyPTZControlReturnStruct& _return, const  ::ipcms::UserVerificationDataPacket& userVerify, const  ::ipcms::ApplyPTZControlDataPacket& applyPtz) {
	// Your implementation goes here
	printf("ApplyPTZControl\n");
	map<string, HANDLE>::iterator iter = m_userLoginList.find(userVerify.UserID);
	if (iter == m_userLoginList.end())
		return;
}

bool IpcManageServerHandler::UserLogout(const  ::ipcms::UserVerificationDataPacket& userVerify) {
	// Your implementation goes here
	printf("UserLogout\n");
	
	map<string, HANDLE>::iterator iter = m_userLoginList.find(userVerify.UserID);
	if (iter == m_userLoginList.end())
		return false;
	releaseLoginResource(iter->second);

	return true;
}

bool IpcManageServerHandler::getLoginResource(HANDLE &handle)
{
	return false;
}

void IpcManageServerHandler::releaseLoginResource(HANDLE handle)
{

}

void IpcManageServerHandler::confirmPTZControl(HANDLE hUser, HANDLE hIPC)
{

}

void IpcManageServerHandler::getPTZResource(HANDLE hRes, HANDLE &hPTZ)
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
		hPTZ = (HANDLE)iter->second.hPTZ;
	}
	return;
}

void IpcManageServerHandler::releasePTZResource(HANDLE handle)
{

}

