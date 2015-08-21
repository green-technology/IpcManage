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

struct ApplyPTZControlDataPacket
{
    1:i64 hPLZ;
    2:i32 type;
}