
struct THEAD
{
	long confirmation;//消息验证
	long type;//消息类型
	long bufferLength;//消息长度
	void *buffer;//消息体
};

struct THEAD_RESPONSE
{
	long confirmation;
	long type;
	long bufferLength;
	void *buffer;
};

//登录
//type:0
struct TLOGIN{
	char* userName;
};

struct TLOGIN_RESPONSE{
	int result;//登录状态返回
	long hLogin;//连接句柄
};

//type:1
//获取资源列表
//获取资源截图
//cmd:0
struct TCMD
{
	long hLogin;
	int cmd;//命令类型
	void *buffer;//命令结构体
};

struct TRESOURCELIST_RESPONSE
{
	unsigned int count;//资源个数
	void* resourceList;
};

struct TRESOURCE
{
	long length;
	long hResource;
	bool hasPLZ;//云台控制
	long timeStart;//录像时间段
	long timeEnd;
	long nameLength;//资源描述信息长度
	void *buffer;
};

//播放
//播放设置
//cmd:1
struct TPLAY_CMD
{
	long hResource;
	long time;
	int speed;
};
struct TPLAY_RESPONSE
{
	long result;
};
//

//获取云台控制
//cmd:2
struct TGETPLZ_CMD
{
	long hResource;
};
struct TGETPLZ_RESPONSE
{
	long result;
	long hPLZ;
};

//云台控制命令
//云台控制权限切换处理
//cmd:3
struct TPLZ_CMD
{
	long hPLZ;
	int type;
};
//可以主动发送
struct TPLZ_RESPONSE
{
	long hPLZ;
	long result;
	void* userName;//抢占用户
};

//登出
//cmd:4
struct TLOGIN_OUT{
	long hLogin;
};
//