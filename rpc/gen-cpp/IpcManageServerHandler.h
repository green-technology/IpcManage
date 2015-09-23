#ifndef IpcManageServerHandler_H
#define IpcManageServerHandler_H

#include <map>
#include "IpcManageServer.h"
#include "MediaManagerStruct_types.h"



#ifdef _DEBUG
#define LOG(msg) printf(msg)
#else
#define LOG(msg)
#endif

using namespace std;
using namespace  ::ipcms;

class IpcManageServerHandler : virtual public IpcManageServerIf {
 public:
  IpcManageServerHandler();

  void UserLogin( ::ipcms::UserLoginReturnStruct& _return, const std::string& userName);

   void GetResInfoList(std::vector< ::ipcms::ResourceInfoReturnStruct> & _return, const  ::ipcms::UserVerificationDataPacket& userVerify, const  ::ipcms::ResourceType::type resType);

  int8_t PlayVideo(const  ::ipcms::UserVerificationDataPacket& userVerify, const  ::ipcms::PlayVideoDataPacket& playVideo);

  //申请云台控制权限
  void RequestPTZControl( ::ipcms::RequestPTZControlReturnStruct& /* _return */, const  ::ipcms::UserVerificationDataPacket& /* userVerify */, const  ::ipcms::RequestPTZControlDataPacket& /* requestPTZ */);

   void PTZControl( ::ipcms::PTZControlReturnStruct& /* _return */, const  ::ipcms::UserVerificationDataPacket& /* userVerify */, const  ::ipcms::PTZControlDataPacket& /* command */);

  bool UserLogout(const  ::ipcms::UserVerificationDataPacket& userVerify);

private:
	bool getLoginResource(HANDLE &handle);
	void releaseLoginResource(HANDLE handle);
	
	void confirmPTZControl(HANDLE hUser, HANDLE hIPC);

	void getPTZResource(HANDLE hRes, LONG &hPTZ);
	void releasePTZResource(HANDLE handle);
	
	bool authentication(const UserVerificationDataPacket &data);
	
	void initMediaResource();

	map<string, UserLoginInfoDataPacket> m_userLoginList;

	vector<HANDLE> m_userResource;

	map<LONG, string> m_PTZUserList;
	map<HANDLE, HANDLE/*resource*/> m_PTZHandler;
	map<HANDLE/*resource*/, IPCResourceDataPacket> m_mediaResource;

};

#endif