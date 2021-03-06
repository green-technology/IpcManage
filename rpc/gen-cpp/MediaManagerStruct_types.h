/**
 * Autogenerated by Thrift Compiler (0.9.2)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef MediaManagerStruct_TYPES_H
#define MediaManagerStruct_TYPES_H

#include <iosfwd>

#include <thrift/Thrift.h>
#include <thrift/TApplicationException.h>
#include <thrift/protocol/TProtocol.h>
#include <thrift/transport/TTransport.h>

#include <thrift/cxxfunctional.h>


namespace ipcms {

struct DeviceType {
  enum type {
    DeviceTypeNone = 0,
    DeviceTypeHC = 1,
    DeviceTypeDH = 2,
    DeviceTypeUnSupported = 3
  };
};

extern const std::map<int, const char*> _DeviceType_VALUES_TO_NAMES;

struct HIK_PTZ_CommandType {
  enum type {
    HIK_LIGHT_PWRON = 2,
    HIK_WIPER_PWRON = 3,
    HIK_FAN_PWRON = 4,
    HIK_HEATER_PWRON = 5,
    HIK_AUX_PWRON1 = 6,
    HIK_AUX_PWRON2 = 7,
    HIK_ZOOM_IN = 11,
    HIK_ZOOM_OUT = 12,
    HIK_FOCUS_NEAR = 13,
    HIK_FOCUS_FAR = 14,
    HIK_IRIS_OPEN = 15,
    HIK_IRIS_CLOSE = 16,
    HIK_TILT_UP = 21,
    HIK_TILT_DOWN = 22,
    HIK_PAN_LEFT = 23,
    HIK_PAN_RIGHT = 24,
    HIK_UP_LEFT = 25,
    HIK_UP_RIGHT = 26,
    HIK_DOWN_LEFT = 27,
    HIK_DOWN_RIGHT = 28,
    HIK_PAN_AUTO = 29,
    HIK_SET_PRESET = 8,
    HIK_CLE_PRESET = 9,
    HIK_GOTO_PRESET = 39
  };
};

extern const std::map<int, const char*> _HIK_PTZ_CommandType_VALUES_TO_NAMES;

class IPCResourceDataPacket;

class UserLoginInfoDataPacket;

class PTZCommandDataPacket;

class RecordResource;

typedef struct _IPCResourceDataPacket__isset {
  _IPCResourceDataPacket__isset() : IP(false), port(false), deviceType(false), userName(false), password(false), channel(false), hPTZ(false), deviceName(false), rtspUrl(false), ID(false) {}
  bool IP :1;
  bool port :1;
  bool deviceType :1;
  bool userName :1;
  bool password :1;
  bool channel :1;
  bool hPTZ :1;
  bool deviceName :1;
  bool rtspUrl :1;
  bool ID :1;
} _IPCResourceDataPacket__isset;

class IPCResourceDataPacket {
 public:

  static const char* ascii_fingerprint; // = "94BA8E62A2C9AE9619B86B6AA5DA8F9F";
  static const uint8_t binary_fingerprint[16]; // = {0x94,0xBA,0x8E,0x62,0xA2,0xC9,0xAE,0x96,0x19,0xB8,0x6B,0x6A,0xA5,0xDA,0x8F,0x9F};

  IPCResourceDataPacket(const IPCResourceDataPacket&);
  IPCResourceDataPacket& operator=(const IPCResourceDataPacket&);
  IPCResourceDataPacket() : IP(), port(0), deviceType((DeviceType::type)0), userName(), password(), channel(0), hPTZ(0), deviceName(), rtspUrl(), ID(0) {
  }

  virtual ~IPCResourceDataPacket() throw();
  std::string IP;
  int64_t port;
  DeviceType::type deviceType;
  std::string userName;
  std::string password;
  int64_t channel;
  int64_t hPTZ;
  std::string deviceName;
  std::string rtspUrl;
  int64_t ID;

  _IPCResourceDataPacket__isset __isset;

  void __set_IP(const std::string& val);

  void __set_port(const int64_t val);

  void __set_deviceType(const DeviceType::type val);

  void __set_userName(const std::string& val);

  void __set_password(const std::string& val);

  void __set_channel(const int64_t val);

  void __set_hPTZ(const int64_t val);

  void __set_deviceName(const std::string& val);

  void __set_rtspUrl(const std::string& val);

  void __set_ID(const int64_t val);

  bool operator == (const IPCResourceDataPacket & rhs) const
  {
    if (!(IP == rhs.IP))
      return false;
    if (!(port == rhs.port))
      return false;
    if (!(deviceType == rhs.deviceType))
      return false;
    if (!(userName == rhs.userName))
      return false;
    if (!(password == rhs.password))
      return false;
    if (!(channel == rhs.channel))
      return false;
    if (!(hPTZ == rhs.hPTZ))
      return false;
    if (!(deviceName == rhs.deviceName))
      return false;
    if (!(rtspUrl == rhs.rtspUrl))
      return false;
    if (!(ID == rhs.ID))
      return false;
    return true;
  }
  bool operator != (const IPCResourceDataPacket &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const IPCResourceDataPacket & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const IPCResourceDataPacket& obj);
};

void swap(IPCResourceDataPacket &a, IPCResourceDataPacket &b);

typedef struct _UserLoginInfoDataPacket__isset {
  _UserLoginInfoDataPacket__isset() : hLogin(false), userName(false), UserID(false), SessionID(false) {}
  bool hLogin :1;
  bool userName :1;
  bool UserID :1;
  bool SessionID :1;
} _UserLoginInfoDataPacket__isset;

class UserLoginInfoDataPacket {
 public:

  static const char* ascii_fingerprint; // = "8FE3619AA429E25B23663D48541BA661";
  static const uint8_t binary_fingerprint[16]; // = {0x8F,0xE3,0x61,0x9A,0xA4,0x29,0xE2,0x5B,0x23,0x66,0x3D,0x48,0x54,0x1B,0xA6,0x61};

  UserLoginInfoDataPacket(const UserLoginInfoDataPacket&);
  UserLoginInfoDataPacket& operator=(const UserLoginInfoDataPacket&);
  UserLoginInfoDataPacket() : hLogin(0), userName(), UserID(), SessionID() {
  }

  virtual ~UserLoginInfoDataPacket() throw();
  int64_t hLogin;
  std::string userName;
  std::string UserID;
  std::string SessionID;

  _UserLoginInfoDataPacket__isset __isset;

  void __set_hLogin(const int64_t val);

  void __set_userName(const std::string& val);

  void __set_UserID(const std::string& val);

  void __set_SessionID(const std::string& val);

  bool operator == (const UserLoginInfoDataPacket & rhs) const
  {
    if (!(hLogin == rhs.hLogin))
      return false;
    if (!(userName == rhs.userName))
      return false;
    if (!(UserID == rhs.UserID))
      return false;
    if (!(SessionID == rhs.SessionID))
      return false;
    return true;
  }
  bool operator != (const UserLoginInfoDataPacket &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const UserLoginInfoDataPacket & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const UserLoginInfoDataPacket& obj);
};

void swap(UserLoginInfoDataPacket &a, UserLoginInfoDataPacket &b);

typedef struct _PTZCommandDataPacket__isset {
  _PTZCommandDataPacket__isset() : hLogin(false), channel(false), command(false), param1(false), param2(false), param3(false), dwStop(false) {}
  bool hLogin :1;
  bool channel :1;
  bool command :1;
  bool param1 :1;
  bool param2 :1;
  bool param3 :1;
  bool dwStop :1;
} _PTZCommandDataPacket__isset;

class PTZCommandDataPacket {
 public:

  static const char* ascii_fingerprint; // = "801176B717A95EFA7A95E978F35737AC";
  static const uint8_t binary_fingerprint[16]; // = {0x80,0x11,0x76,0xB7,0x17,0xA9,0x5E,0xFA,0x7A,0x95,0xE9,0x78,0xF3,0x57,0x37,0xAC};

  PTZCommandDataPacket(const PTZCommandDataPacket&);
  PTZCommandDataPacket& operator=(const PTZCommandDataPacket&);
  PTZCommandDataPacket() : hLogin(0), channel(0), command(0), param1(0), param2(0), param3(0), dwStop(0) {
  }

  virtual ~PTZCommandDataPacket() throw();
  int64_t hLogin;
  int64_t channel;
  int64_t command;
  int64_t param1;
  int64_t param2;
  int64_t param3;
  bool dwStop;

  _PTZCommandDataPacket__isset __isset;

  void __set_hLogin(const int64_t val);

  void __set_channel(const int64_t val);

  void __set_command(const int64_t val);

  void __set_param1(const int64_t val);

  void __set_param2(const int64_t val);

  void __set_param3(const int64_t val);

  void __set_dwStop(const bool val);

  bool operator == (const PTZCommandDataPacket & rhs) const
  {
    if (!(hLogin == rhs.hLogin))
      return false;
    if (!(channel == rhs.channel))
      return false;
    if (!(command == rhs.command))
      return false;
    if (!(param1 == rhs.param1))
      return false;
    if (!(param2 == rhs.param2))
      return false;
    if (!(param3 == rhs.param3))
      return false;
    if (!(dwStop == rhs.dwStop))
      return false;
    return true;
  }
  bool operator != (const PTZCommandDataPacket &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const PTZCommandDataPacket & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const PTZCommandDataPacket& obj);
};

void swap(PTZCommandDataPacket &a, PTZCommandDataPacket &b);

typedef struct _RecordResource__isset {
  _RecordResource__isset() : name(false), path(false), startTime(false), timeLength(false) {}
  bool name :1;
  bool path :1;
  bool startTime :1;
  bool timeLength :1;
} _RecordResource__isset;

class RecordResource {
 public:

  static const char* ascii_fingerprint; // = "50272E49E7C02012722B8F62131C940B";
  static const uint8_t binary_fingerprint[16]; // = {0x50,0x27,0x2E,0x49,0xE7,0xC0,0x20,0x12,0x72,0x2B,0x8F,0x62,0x13,0x1C,0x94,0x0B};

  RecordResource(const RecordResource&);
  RecordResource& operator=(const RecordResource&);
  RecordResource() : name(), path(), startTime(0), timeLength(0) {
  }

  virtual ~RecordResource() throw();
  std::string name;
  std::string path;
  int64_t startTime;
  int64_t timeLength;

  _RecordResource__isset __isset;

  void __set_name(const std::string& val);

  void __set_path(const std::string& val);

  void __set_startTime(const int64_t val);

  void __set_timeLength(const int64_t val);

  bool operator == (const RecordResource & rhs) const
  {
    if (!(name == rhs.name))
      return false;
    if (!(path == rhs.path))
      return false;
    if (!(startTime == rhs.startTime))
      return false;
    if (!(timeLength == rhs.timeLength))
      return false;
    return true;
  }
  bool operator != (const RecordResource &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const RecordResource & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const RecordResource& obj);
};

void swap(RecordResource &a, RecordResource &b);

} // namespace

#endif
