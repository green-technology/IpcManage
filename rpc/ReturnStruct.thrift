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
    1: optional ResourceType resourceType;
    2: i64 hResource;
    3: bool hasPLZ;//云台控制
    4: i64 timeStart;//录像时间段
    5: i64 timeEnd;
    6: i64 nameLength;	//资源描述信息长度
	7: string rtspUrl;  //rtsp视频串 add by frankz
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