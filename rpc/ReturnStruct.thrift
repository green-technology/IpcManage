namespace cpp ipcms

//用户登录返回结构类
struct UserLoginReturnStruct {
        1: byte     ErrorNum;
        2: string UserID;
        3: string SessionID;
}


//资源信息结构
struct ResourceInfoReturnStruct
{
    1: i64 length;
    2: i64 hResource;
    3: bool hasPLZ;//云台控制
    4: i64 timeStart;//录像时间段
    5: i64 timeEnd;
    6: i64 nameLength;//资源描述信息长度
}


struct ApplyPTZControlReturnStruct
{
    1:i64 hPLZ;
    2:i64 result;
    3:string userName;//抢占用户
}

struct RequestPTZControlReturnStruct
{
    1:i64 hPTZ;
    2:i64 result;
    3:string userName;//失败时,返回正在使用用户的名字
}
