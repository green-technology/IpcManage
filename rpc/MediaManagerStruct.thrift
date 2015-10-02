namespace cpp ipcms

enum DeviceType {
		DeviceTypeNone,
		DeviceTypeHC,
		DeviceTypeDH,
		DeviceTypeUnSupported
}

//多媒体资源管理数据包
struct IPCResourceDataPacket {
        1: string IP;
        2: i64 port;
        3: optional DeviceType deviceType;
        4: string userName;
        5: string password;
        6: i64 channel;
        7: i64 hPTZ;
        8: string deviceName;
		9: string rtspUrl;
}

struct UserLoginInfoDataPacket {
		1: i64 hLogin;
		2: string userName;
		3: string UserID;
		4: string SessionID;
}

struct PTZCommandDataPacket {
	1: i64					hLogin;
	2: i64					channel;
	3: i64					command;
	4: i64					param1;
	5: i64					param2;
	6: i64					param3;
	7: bool					dwStop;
}

// 海康通用云台控制命令
enum HIK_PTZ_CommandType
{
	// 通用云台操作
	HIK_LIGHT_PWRON		= 2,					// 接通灯光电源 
	HIK_WIPER_PWRON		= 3,					// 接通雨刷开关 
	HIK_FAN_PWRON		= 4,					// 接通风扇开关 
	HIK_HEATER_PWRON	= 5,					// 接通加热器开关 
	HIK_AUX_PWRON1		= 6,					// 接通辅助设备开关 
	HIK_AUX_PWRON2		= 7,					// 接通辅助设备开关 
	HIK_ZOOM_IN			= 11,					// 焦距变大(倍率变大) 
	HIK_ZOOM_OUT		= 12,					// 焦距变小(倍率变小) 
	HIK_FOCUS_NEAR		= 13,					// 焦点前调 
	HIK_FOCUS_FAR		= 14,					// 焦点后调 
	HIK_IRIS_OPEN		= 15,					// 光圈扩大 
	HIK_IRIS_CLOSE		= 16,					// 光圈缩小 
	HIK_TILT_UP			= 21,					// 云台上仰 
	HIK_TILT_DOWN		= 22,					// 云台下俯 
	HIK_PAN_LEFT		= 23,					// 云台左转 
	HIK_PAN_RIGHT		= 24,					// 云台右转
	HIK_UP_LEFT			= 25,					// 云台上仰和左转 
	HIK_UP_RIGHT		= 26,					// 云台上仰和右转 
	HIK_DOWN_LEFT		= 27,					// 云台下俯和左转 
	HIK_DOWN_RIGHT		= 28,					// 云台下俯和右转 
	HIK_PAN_AUTO		= 29,					// 云台左右自动扫描

	// 预置点设置
	HIK_SET_PRESET			= 8,				// 设置预置点 
	HIK_CLE_PRESET			= 9,				// 清除预置点 
	HIK_GOTO_PRESET			= 39,				// 转到预置点 

}

struct RecordResource
{
	1: string 	name;
	2: string	path;
	3: i64 		startTime;
	4: i64		timeLength;
}
