#include "IpcManageServerHandler.h"
#include "assert.h"

void IpcManageServerHandler::UserLogin( ::ipcms::UserLoginReturnStruct& _return, const std::string& userName) {
	// Your implementation goes here
	printf("UserLogin\n");
	_return.SessionID = "11";
	_return.UserID = "22";

	//用户验证，以用户名作为KEY
	map<string, HANDLE>::iterator iter = m_userLoginList.find(userName);
	if(iter == m_userLoginList.end())
		return;

	//分配资源
	HANDLE hLogin;
	if (!getLoginResource(hLogin))
		return;
	m_userLoginList[userName] = hLogin;
}

void IpcManageServerHandler::GetResInfoList(std::vector< ::ipcms::ResourceInfoReturnStruct> & _return, const  ::ipcms::UserVerificationDataPacket& userVerify, const int32_t resType) {
}

int8_t IpcManageServerHandler::PlayVideo(const  ::ipcms::UserVerificationDataPacket& userVerify, const  ::ipcms::PlayVideoDataPacket& playVideo) {
	// Your implementation goes here
	printf("PlayVideo\n");
	return 0;
}

void IpcManageServerHandler::requestPTZControl()
{
	char* cIPC = "";
	HANDLE hIPC = NULL;
	HANDLE currentUserID = getPTZResource(cIPC, hIPC);
	if (hIPC == NULL)
	{
	}
	else
	{

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

HANDLE IpcManageServerHandler::getPTZResource(const char *ipc, HANDLE &handle)
{
	map<string, HANDLE>::iterator iter = m_PTZResource.find(ipc);
	if (iter == m_PTZResource.end())
	{
		//通过SDK建立连接
		handle = 0;
		m_PTZResource[ipc] = handle;
	}
	else
	{
		HANDLE hIPC = iter->second;
		map<HANDLE, HANDLE>::iterator iterUser = m_PTZUserList.find(hIPC);
		assert(iterUser != m_PTZUserList.end());
		HANDLE userID = iterUser->second;
		confirmPTZControl(userID, hIPC);
	}
	return false;
}

void IpcManageServerHandler::releasePTZResource(HANDLE handle)
{

}

