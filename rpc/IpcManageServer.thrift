namespace cpp ipcms

include "ReturnStruct.thrift"
include "OperateStruct.thrift"


service IpcManageServer {

	//用户登录
	ReturnStruct.UserLoginReturnStruct UserLogin(1: string userName);

	// 获取资源信息列表
	list<ReturnStruct.ResourceInfoReturnStruct> GetResInfoList(1: OperateStruct.UserVerificationDataPacket userVerify,2: ReturnStruct.ResourceType resType);


	// 播放
 	byte PlayVideo(1: OperateStruct.UserVerificationDataPacket userVerify,2: OperateStruct.PlayVideoDataPacket playVideo);

 	//申请云台控制
 	ReturnStruct.RequestPTZControlReturnStruct RequestPTZControl(1: OperateStruct.UserVerificationDataPacket userVerify,2: OperateStruct.RequestPTZControlDataPacket requestPTZ);

 	ReturnStruct.PTZControlReturnStruct PTZControl(1: OperateStruct.UserVerificationDataPacket userVerify, 2: OperateStruct.PTZControlDataPacket command);

	//登出
	bool UserLogout(1: OperateStruct.UserVerificationDataPacket userVerify);


}