namespace cpp ipcms

//用户登录返回结构类
struct UserLoginReturnStruct {
        1: byte     ErrorNum;
        2: string UserID;
        3: string SessionID;
}

enum ResourceType {
        ResourceTypeALL,
		ResourceTypeReplay,
		ResourceTypeIPC,
}

//资源信息结构
struct ResourceInfoReturnStruct
{
    1: ResourceType resourceType;
    2: string IP;
    3: string deviceName;
    4: i64 hResource;
    5: bool hasPLZ;     //云台控制
    6: i64 timeStart;   //录像时间段
    7: i64 timeEnd;
	8: string rtspUrl;  //rtsp视频串 add by frankz
    9: i64 ID;          //设备资源的唯一ID
}

struct RequestPTZControlReturnStruct
{
    1:i64 hPTZ;
    2:i64 result;
    3:string userName;//失败时,返回正在使用用户的名字
}

enum PTZControlReturnType
{
    PTZControlReturnTypeInvalidHandle,
    PTZControlReturnTypeSuccess,
    PTZControlReturnTypeError
}

struct PTZControlReturnStruct
{
    1:optional PTZControlReturnType result;
}

enum ReturnType
{
    Success,
    InvalidUser,
    InvalidHandle,
    FailUnspecified
}