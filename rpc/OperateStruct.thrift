namespace cpp ipcms


//用户验证数据包
struct UserVerificationDataPacket {
    1: required string UserID;
    2: required string SessionID;
}


struct PlayVideoDataPacket
{
    1:i64 hResource;
    2:i64 time;
    3:i32 speed;
}

struct RequestPTZControlDataPacket
{
	1:i64 hResource;
}

enum PTZCommand
{
    PTZ_UP = 0,						// 向上
    PTZ_DOWN,						// 向下
    PTZ_LEFT,						// 向左
    PTZ_RIGHT,						// 向右
    PTZ_ZOOM_ADD,					// 变倍+
    PTZ_ZOOM_DEC,					// 变倍-
    PTZ_FOCUS_ADD,					// 调焦+
    PTZ_FOCUS_DEC,					// 调焦-
    PTZ_APERTURE_ADD,				// 光圈+
    PTZ_APERTURE_DEC,				// 光圈-
    PTZ_POINT_MOVE,					// 转至预置点
    PTZ_POINT_SET,					// 设置预置点
    PTZ_LAMP_OPEN,					// 打开灯光
    PTZ_LAMP_CLOSE,					// 关闭灯光
    PTZ_WIPER_OPEN,					// 打开雨刷
    PTZ_WIPER_CLOSE,				// 关闭雨刷
    PTZ_THROUGHFOG_OPEN,			// 打开透雾
    PTZ_THROUGHFOG_CLOSE,			// 关闭透雾
    PTZ_DEV_OPEN,					// 打开辅助设备
    PTZ_DEV_CLOSE,					// 关闭辅助设备
    PTZ_LEFTUP,						// 左上
    PTZ_RIGHTUP,					// 右上
    PTZ_LEFTDOWN,					// 左下
    PTZ_RIGHTDOWN,					// 右下
	PTZ_MAX_COMMAND					// 最大值
}

struct PTZControlDataPacket
{
	1: i64					hPTZ;                   //PTZ control handle
	2: PTZCommand	        command;                //PTZ control cmd
	3: i64					param1;
	4: i64					param2;
	5: i64					param3;
	6: bool					dwStop;                  // is stop PTZ control
}