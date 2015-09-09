namespace cpp ipcms

//多媒体资源管理数据包
struct IPCResourceDataPacket {
        1: string IP;
        2: i64 port;
        3: i64 DeviceType;
        4: string userName;
        5: string password;
        6: i64 channel;
        7: i64 hPTZ;
}
