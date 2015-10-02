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

	void UserLogin( ::ipcms::UserLoginReturnStruct& _return, const std::string& userName) override;

	void GetResInfoList(std::vector< ::ipcms::ResourceInfoReturnStruct> & _return, const  ::ipcms::UserVerificationDataPacket& userVerify, const  ::ipcms::ResourceType::type resType) override;

	int8_t PlayVideo(const  ::ipcms::UserVerificationDataPacket& userVerify, const  ::ipcms::PlayVideoDataPacket& playVideo) override;

	//申请云台控制权限
	void RequestPTZControl( ::ipcms::RequestPTZControlReturnStruct& /* _return */, const  ::ipcms::UserVerificationDataPacket& /* userVerify */, const  ::ipcms::RequestPTZControlDataPacket& /* requestPTZ */) override;

	void PTZControl( ::ipcms::PTZControlReturnStruct& /* _return */, const  ::ipcms::UserVerificationDataPacket& /* userVerify */, const  ::ipcms::PTZControlDataPacket& /* command */) override;
	
	ReturnType::type ReleasePTZControl(const  ::ipcms::UserVerificationDataPacket& userVerify, const int64_t hPTZ) override;

	bool UserLogout(const  ::ipcms::UserVerificationDataPacket& userVerify) override;

	ReturnType::type addResourceIPC(const  ::ipcms::UserVerificationDataPacket& userVerify, const  ::ipcms::IPCResourceDataPacket& ipc) override;
	ReturnType::type addResourceRecord(const  ::ipcms::UserVerificationDataPacket& userVerify, const  ::ipcms::RecordResource& record, const std::string& file) override;
	ReturnType::type deleteResource(const  ::ipcms::UserVerificationDataPacket& userVerify, const int64_t handle) override;

private:
	bool getLoginResource(const string userName, string& id);
	void releaseLoginResource(const string id);

	void confirmPTZControl(HANDLE hUser, HANDLE hIPC);

	BOOL getPTZResource(HANDLE hRes, LONG &hPTZ);

	bool authentication(const UserVerificationDataPacket &data) const;

	void initMediaResource();

	map<string/*id*/, string/*userName*/> m_userLoginList;

	vector<HANDLE> m_userResource;

	map<LONG, string> m_PTZUserList;
	map<LONG, HANDLE/*resource*/> m_PTZHandler;

};

#endif