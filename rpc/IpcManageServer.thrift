namespace cpp ipcms

include "ReturnStruct.thrift"
include "OperateStruct.thrift"
include "MediaManagerStruct.thrift"

service IpcManageServer {

	//用户登录
	ReturnStruct.UserLoginReturnStruct UserLogin(1: string userName);

	//登出
	bool UserLogout(1: OperateStruct.UserVerificationDataPacket userVerify);

	// 获取资源信息列表
	list<ReturnStruct.ResourceInfoReturnStruct> GetResInfoList(1: OperateStruct.UserVerificationDataPacket userVerify,2: ReturnStruct.ResourceType resType);

	// 播放
 	byte PlayVideo(1: OperateStruct.UserVerificationDataPacket userVerify,2: OperateStruct.PlayVideoDataPacket playVideo);

 	//申请云台控制
 	ReturnStruct.RequestPTZControlReturnStruct RequestPTZControl(1: OperateStruct.UserVerificationDataPacket userVerify,2: OperateStruct.RequestPTZControlDataPacket requestPTZ);

	// 云台控制
 	ReturnStruct.PTZControlReturnStruct PTZControl(1: OperateStruct.UserVerificationDataPacket userVerify, 2: OperateStruct.PTZControlDataPacket command);

 	ReturnStruct.ReturnType ReleasePTZControl(1: OperateStruct.UserVerificationDataPacket userVerify, 2:i64 hPTZ);

	// 新增接口 //20150923 add by frankz
	// 新增用户 删除用户 系统内保留一个管理员用户，可以进行用户管理

	// 新增资源 删除资源
	ReturnStruct.ReturnType addResource(1: OperateStruct.UserVerificationDataPacket userVerify, 2: MediaManagerStruct.IPCResourceDataPacket ipc);
	ReturnStruct.ReturnType addResourceRecord(1: OperateStruct.UserVerificationDataPacket userVerify, 2: MediaManagerStruct.RecordResource record, 3: string file);
	ReturnStruct.ReturnType deleteResource(1: OperateStruct.UserVerificationDataPacket userVerify, 2: i64 handle);
	ReturnStruct.ReturnType deleteAllResources(1: OperateStruct.UserVerificationDataPacket userVerify);
}