#ifndef IpcManageServerHandler_H
#define IpcManageServerHandler_H

#include <map>
#include "IpcManageServer.h"
#include "MediaManagerStruct_types.h"

using namespace std;
using namespace  ::ipcms;

class IpcManageServerHandler : virtual public IpcManageServerIf {
 public:
  IpcManageServerHandler() {
    // Your initialization goes here
  }

  void UserLogin( ::ipcms::UserLoginReturnStruct& _return, const std::string& userName);

  void GetResInfoList(std::vector< ::ipcms::ResourceInfoReturnStruct> & _return, const  ::ipcms::UserVerificationDataPacket& userVerify, const int32_t resType);

  int8_t PlayVideo(const  ::ipcms::UserVerificationDataPacket& userVerify, const  ::ipcms::PlayVideoDataPacket& playVideo);

  //申请云台控制权限
  void RequestPTZControl( ::ipcms::RequestPTZControlReturnStruct& /* _return */, const  ::ipcms::UserVerificationDataPacket& /* userVerify */, const  ::ipcms::RequestPTZControlDataPacket& /* requestPTZ */);

  void ApplyPTZControl( ::ipcms::ApplyPTZControlReturnStruct& _return, const  ::ipcms::UserVerificationDataPacket& userVerify, const  ::ipcms::ApplyPTZControlDataPacket& applyPtz);

  bool UserLogout(const  ::ipcms::UserVerificationDataPacket& userVerify);

private:
	bool getLoginResource(HANDLE &handle);
	void releaseLoginResource(HANDLE handle);
	
	void confirmPTZControl(HANDLE hUser, HANDLE hIPC);

	void getPTZResource(HANDLE hRes, HANDLE &hPTZ);
	void releasePTZResource(HANDLE handle);
	
	map<string, HANDLE> m_userLoginList;
	vector<HANDLE> m_userResource;
	map<HANDLE, string> m_PTZUserList;
	map<HANDLE, IPCResourceDataPacket> m_mediaResource;

};

#endif