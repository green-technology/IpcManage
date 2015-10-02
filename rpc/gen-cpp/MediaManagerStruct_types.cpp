/**
 * Autogenerated by Thrift Compiler (0.9.2)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "MediaManagerStruct_types.h"

#include <algorithm>
#include <ostream>

#include <thrift/TToString.h>

namespace ipcms {

int _kDeviceTypeValues[] = {
  DeviceType::DeviceTypeNone,
  DeviceType::DeviceTypeHC,
  DeviceType::DeviceTypeDH,
  DeviceType::DeviceTypeUnSupported
};
const char* _kDeviceTypeNames[] = {
  "DeviceTypeNone",
  "DeviceTypeHC",
  "DeviceTypeDH",
  "DeviceTypeUnSupported"
};
const std::map<int, const char*> _DeviceType_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(4, _kDeviceTypeValues, _kDeviceTypeNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

int _kHIK_PTZ_CommandTypeValues[] = {
  HIK_PTZ_CommandType::HIK_LIGHT_PWRON,
  HIK_PTZ_CommandType::HIK_WIPER_PWRON,
  HIK_PTZ_CommandType::HIK_FAN_PWRON,
  HIK_PTZ_CommandType::HIK_HEATER_PWRON,
  HIK_PTZ_CommandType::HIK_AUX_PWRON1,
  HIK_PTZ_CommandType::HIK_AUX_PWRON2,
  HIK_PTZ_CommandType::HIK_ZOOM_IN,
  HIK_PTZ_CommandType::HIK_ZOOM_OUT,
  HIK_PTZ_CommandType::HIK_FOCUS_NEAR,
  HIK_PTZ_CommandType::HIK_FOCUS_FAR,
  HIK_PTZ_CommandType::HIK_IRIS_OPEN,
  HIK_PTZ_CommandType::HIK_IRIS_CLOSE,
  HIK_PTZ_CommandType::HIK_TILT_UP,
  HIK_PTZ_CommandType::HIK_TILT_DOWN,
  HIK_PTZ_CommandType::HIK_PAN_LEFT,
  HIK_PTZ_CommandType::HIK_PAN_RIGHT,
  HIK_PTZ_CommandType::HIK_UP_LEFT,
  HIK_PTZ_CommandType::HIK_UP_RIGHT,
  HIK_PTZ_CommandType::HIK_DOWN_LEFT,
  HIK_PTZ_CommandType::HIK_DOWN_RIGHT,
  HIK_PTZ_CommandType::HIK_PAN_AUTO,
  HIK_PTZ_CommandType::HIK_SET_PRESET,
  HIK_PTZ_CommandType::HIK_CLE_PRESET,
  HIK_PTZ_CommandType::HIK_GOTO_PRESET
};
const char* _kHIK_PTZ_CommandTypeNames[] = {
  "HIK_LIGHT_PWRON",
  "HIK_WIPER_PWRON",
  "HIK_FAN_PWRON",
  "HIK_HEATER_PWRON",
  "HIK_AUX_PWRON1",
  "HIK_AUX_PWRON2",
  "HIK_ZOOM_IN",
  "HIK_ZOOM_OUT",
  "HIK_FOCUS_NEAR",
  "HIK_FOCUS_FAR",
  "HIK_IRIS_OPEN",
  "HIK_IRIS_CLOSE",
  "HIK_TILT_UP",
  "HIK_TILT_DOWN",
  "HIK_PAN_LEFT",
  "HIK_PAN_RIGHT",
  "HIK_UP_LEFT",
  "HIK_UP_RIGHT",
  "HIK_DOWN_LEFT",
  "HIK_DOWN_RIGHT",
  "HIK_PAN_AUTO",
  "HIK_SET_PRESET",
  "HIK_CLE_PRESET",
  "HIK_GOTO_PRESET"
};
const std::map<int, const char*> _HIK_PTZ_CommandType_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(24, _kHIK_PTZ_CommandTypeValues, _kHIK_PTZ_CommandTypeNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));


IPCResourceDataPacket::~IPCResourceDataPacket() throw() {
}


void IPCResourceDataPacket::__set_IP(const std::string& val) {
  this->IP = val;
}

void IPCResourceDataPacket::__set_port(const int64_t val) {
  this->port = val;
}

void IPCResourceDataPacket::__set_deviceType(const DeviceType::type val) {
  this->deviceType = val;
__isset.deviceType = true;
}

void IPCResourceDataPacket::__set_userName(const std::string& val) {
  this->userName = val;
}

void IPCResourceDataPacket::__set_password(const std::string& val) {
  this->password = val;
}

void IPCResourceDataPacket::__set_channel(const int64_t val) {
  this->channel = val;
}

void IPCResourceDataPacket::__set_hPTZ(const int64_t val) {
  this->hPTZ = val;
}

void IPCResourceDataPacket::__set_deviceName(const std::string& val) {
  this->deviceName = val;
}

void IPCResourceDataPacket::__set_rtspUrl(const std::string& val) {
  this->rtspUrl = val;
}

const char* IPCResourceDataPacket::ascii_fingerprint = "04C60CC0FEAB1A399AD4C95F224660B5";
const uint8_t IPCResourceDataPacket::binary_fingerprint[16] = {0x04,0xC6,0x0C,0xC0,0xFE,0xAB,0x1A,0x39,0x9A,0xD4,0xC9,0x5F,0x22,0x46,0x60,0xB5};

uint32_t IPCResourceDataPacket::read(::apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->IP);
          this->__isset.IP = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->port);
          this->__isset.port = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast0;
          xfer += iprot->readI32(ecast0);
          this->deviceType = (DeviceType::type)ecast0;
          this->__isset.deviceType = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->userName);
          this->__isset.userName = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->password);
          this->__isset.password = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 6:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->channel);
          this->__isset.channel = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 7:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->hPTZ);
          this->__isset.hPTZ = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 8:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->deviceName);
          this->__isset.deviceName = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 9:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->rtspUrl);
          this->__isset.rtspUrl = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t IPCResourceDataPacket::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  oprot->incrementRecursionDepth();
  xfer += oprot->writeStructBegin("IPCResourceDataPacket");

  xfer += oprot->writeFieldBegin("IP", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->IP);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("port", ::apache::thrift::protocol::T_I64, 2);
  xfer += oprot->writeI64(this->port);
  xfer += oprot->writeFieldEnd();

  if (this->__isset.deviceType) {
    xfer += oprot->writeFieldBegin("deviceType", ::apache::thrift::protocol::T_I32, 3);
    xfer += oprot->writeI32((int32_t)this->deviceType);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldBegin("userName", ::apache::thrift::protocol::T_STRING, 4);
  xfer += oprot->writeString(this->userName);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("password", ::apache::thrift::protocol::T_STRING, 5);
  xfer += oprot->writeString(this->password);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("channel", ::apache::thrift::protocol::T_I64, 6);
  xfer += oprot->writeI64(this->channel);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("hPTZ", ::apache::thrift::protocol::T_I64, 7);
  xfer += oprot->writeI64(this->hPTZ);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("deviceName", ::apache::thrift::protocol::T_STRING, 8);
  xfer += oprot->writeString(this->deviceName);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("rtspUrl", ::apache::thrift::protocol::T_STRING, 9);
  xfer += oprot->writeString(this->rtspUrl);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  oprot->decrementRecursionDepth();
  return xfer;
}

void swap(IPCResourceDataPacket &a, IPCResourceDataPacket &b) {
  using ::std::swap;
  swap(a.IP, b.IP);
  swap(a.port, b.port);
  swap(a.deviceType, b.deviceType);
  swap(a.userName, b.userName);
  swap(a.password, b.password);
  swap(a.channel, b.channel);
  swap(a.hPTZ, b.hPTZ);
  swap(a.deviceName, b.deviceName);
  swap(a.rtspUrl, b.rtspUrl);
  swap(a.__isset, b.__isset);
}

IPCResourceDataPacket::IPCResourceDataPacket(const IPCResourceDataPacket& other1) {
  IP = other1.IP;
  port = other1.port;
  deviceType = other1.deviceType;
  userName = other1.userName;
  password = other1.password;
  channel = other1.channel;
  hPTZ = other1.hPTZ;
  deviceName = other1.deviceName;
  rtspUrl = other1.rtspUrl;
  __isset = other1.__isset;
}
IPCResourceDataPacket& IPCResourceDataPacket::operator=(const IPCResourceDataPacket& other2) {
  IP = other2.IP;
  port = other2.port;
  deviceType = other2.deviceType;
  userName = other2.userName;
  password = other2.password;
  channel = other2.channel;
  hPTZ = other2.hPTZ;
  deviceName = other2.deviceName;
  rtspUrl = other2.rtspUrl;
  __isset = other2.__isset;
  return *this;
}
std::ostream& operator<<(std::ostream& out, const IPCResourceDataPacket& obj) {
  using apache::thrift::to_string;
  out << "IPCResourceDataPacket(";
  out << "IP=" << to_string(obj.IP);
  out << ", " << "port=" << to_string(obj.port);
  out << ", " << "deviceType="; (obj.__isset.deviceType ? (out << to_string(obj.deviceType)) : (out << "<null>"));
  out << ", " << "userName=" << to_string(obj.userName);
  out << ", " << "password=" << to_string(obj.password);
  out << ", " << "channel=" << to_string(obj.channel);
  out << ", " << "hPTZ=" << to_string(obj.hPTZ);
  out << ", " << "deviceName=" << to_string(obj.deviceName);
  out << ", " << "rtspUrl=" << to_string(obj.rtspUrl);
  out << ")";
  return out;
}


UserLoginInfoDataPacket::~UserLoginInfoDataPacket() throw() {
}


void UserLoginInfoDataPacket::__set_hLogin(const int64_t val) {
  this->hLogin = val;
}

void UserLoginInfoDataPacket::__set_userName(const std::string& val) {
  this->userName = val;
}

void UserLoginInfoDataPacket::__set_UserID(const std::string& val) {
  this->UserID = val;
}

void UserLoginInfoDataPacket::__set_SessionID(const std::string& val) {
  this->SessionID = val;
}

const char* UserLoginInfoDataPacket::ascii_fingerprint = "8FE3619AA429E25B23663D48541BA661";
const uint8_t UserLoginInfoDataPacket::binary_fingerprint[16] = {0x8F,0xE3,0x61,0x9A,0xA4,0x29,0xE2,0x5B,0x23,0x66,0x3D,0x48,0x54,0x1B,0xA6,0x61};

uint32_t UserLoginInfoDataPacket::read(::apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->hLogin);
          this->__isset.hLogin = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->userName);
          this->__isset.userName = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->UserID);
          this->__isset.UserID = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->SessionID);
          this->__isset.SessionID = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t UserLoginInfoDataPacket::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  oprot->incrementRecursionDepth();
  xfer += oprot->writeStructBegin("UserLoginInfoDataPacket");

  xfer += oprot->writeFieldBegin("hLogin", ::apache::thrift::protocol::T_I64, 1);
  xfer += oprot->writeI64(this->hLogin);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("userName", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeString(this->userName);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("UserID", ::apache::thrift::protocol::T_STRING, 3);
  xfer += oprot->writeString(this->UserID);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("SessionID", ::apache::thrift::protocol::T_STRING, 4);
  xfer += oprot->writeString(this->SessionID);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  oprot->decrementRecursionDepth();
  return xfer;
}

void swap(UserLoginInfoDataPacket &a, UserLoginInfoDataPacket &b) {
  using ::std::swap;
  swap(a.hLogin, b.hLogin);
  swap(a.userName, b.userName);
  swap(a.UserID, b.UserID);
  swap(a.SessionID, b.SessionID);
  swap(a.__isset, b.__isset);
}

UserLoginInfoDataPacket::UserLoginInfoDataPacket(const UserLoginInfoDataPacket& other3) {
  hLogin = other3.hLogin;
  userName = other3.userName;
  UserID = other3.UserID;
  SessionID = other3.SessionID;
  __isset = other3.__isset;
}
UserLoginInfoDataPacket& UserLoginInfoDataPacket::operator=(const UserLoginInfoDataPacket& other4) {
  hLogin = other4.hLogin;
  userName = other4.userName;
  UserID = other4.UserID;
  SessionID = other4.SessionID;
  __isset = other4.__isset;
  return *this;
}
std::ostream& operator<<(std::ostream& out, const UserLoginInfoDataPacket& obj) {
  using apache::thrift::to_string;
  out << "UserLoginInfoDataPacket(";
  out << "hLogin=" << to_string(obj.hLogin);
  out << ", " << "userName=" << to_string(obj.userName);
  out << ", " << "UserID=" << to_string(obj.UserID);
  out << ", " << "SessionID=" << to_string(obj.SessionID);
  out << ")";
  return out;
}


PTZCommandDataPacket::~PTZCommandDataPacket() throw() {
}


void PTZCommandDataPacket::__set_hLogin(const int64_t val) {
  this->hLogin = val;
}

void PTZCommandDataPacket::__set_channel(const int64_t val) {
  this->channel = val;
}

void PTZCommandDataPacket::__set_command(const int64_t val) {
  this->command = val;
}

void PTZCommandDataPacket::__set_param1(const int64_t val) {
  this->param1 = val;
}

void PTZCommandDataPacket::__set_param2(const int64_t val) {
  this->param2 = val;
}

void PTZCommandDataPacket::__set_param3(const int64_t val) {
  this->param3 = val;
}

void PTZCommandDataPacket::__set_dwStop(const bool val) {
  this->dwStop = val;
}

const char* PTZCommandDataPacket::ascii_fingerprint = "801176B717A95EFA7A95E978F35737AC";
const uint8_t PTZCommandDataPacket::binary_fingerprint[16] = {0x80,0x11,0x76,0xB7,0x17,0xA9,0x5E,0xFA,0x7A,0x95,0xE9,0x78,0xF3,0x57,0x37,0xAC};

uint32_t PTZCommandDataPacket::read(::apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->hLogin);
          this->__isset.hLogin = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->channel);
          this->__isset.channel = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->command);
          this->__isset.command = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->param1);
          this->__isset.param1 = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->param2);
          this->__isset.param2 = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 6:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->param3);
          this->__isset.param3 = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 7:
        if (ftype == ::apache::thrift::protocol::T_BOOL) {
          xfer += iprot->readBool(this->dwStop);
          this->__isset.dwStop = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t PTZCommandDataPacket::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  oprot->incrementRecursionDepth();
  xfer += oprot->writeStructBegin("PTZCommandDataPacket");

  xfer += oprot->writeFieldBegin("hLogin", ::apache::thrift::protocol::T_I64, 1);
  xfer += oprot->writeI64(this->hLogin);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("channel", ::apache::thrift::protocol::T_I64, 2);
  xfer += oprot->writeI64(this->channel);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("command", ::apache::thrift::protocol::T_I64, 3);
  xfer += oprot->writeI64(this->command);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("param1", ::apache::thrift::protocol::T_I64, 4);
  xfer += oprot->writeI64(this->param1);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("param2", ::apache::thrift::protocol::T_I64, 5);
  xfer += oprot->writeI64(this->param2);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("param3", ::apache::thrift::protocol::T_I64, 6);
  xfer += oprot->writeI64(this->param3);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("dwStop", ::apache::thrift::protocol::T_BOOL, 7);
  xfer += oprot->writeBool(this->dwStop);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  oprot->decrementRecursionDepth();
  return xfer;
}

void swap(PTZCommandDataPacket &a, PTZCommandDataPacket &b) {
  using ::std::swap;
  swap(a.hLogin, b.hLogin);
  swap(a.channel, b.channel);
  swap(a.command, b.command);
  swap(a.param1, b.param1);
  swap(a.param2, b.param2);
  swap(a.param3, b.param3);
  swap(a.dwStop, b.dwStop);
  swap(a.__isset, b.__isset);
}

PTZCommandDataPacket::PTZCommandDataPacket(const PTZCommandDataPacket& other5) {
  hLogin = other5.hLogin;
  channel = other5.channel;
  command = other5.command;
  param1 = other5.param1;
  param2 = other5.param2;
  param3 = other5.param3;
  dwStop = other5.dwStop;
  __isset = other5.__isset;
}
PTZCommandDataPacket& PTZCommandDataPacket::operator=(const PTZCommandDataPacket& other6) {
  hLogin = other6.hLogin;
  channel = other6.channel;
  command = other6.command;
  param1 = other6.param1;
  param2 = other6.param2;
  param3 = other6.param3;
  dwStop = other6.dwStop;
  __isset = other6.__isset;
  return *this;
}
std::ostream& operator<<(std::ostream& out, const PTZCommandDataPacket& obj) {
  using apache::thrift::to_string;
  out << "PTZCommandDataPacket(";
  out << "hLogin=" << to_string(obj.hLogin);
  out << ", " << "channel=" << to_string(obj.channel);
  out << ", " << "command=" << to_string(obj.command);
  out << ", " << "param1=" << to_string(obj.param1);
  out << ", " << "param2=" << to_string(obj.param2);
  out << ", " << "param3=" << to_string(obj.param3);
  out << ", " << "dwStop=" << to_string(obj.dwStop);
  out << ")";
  return out;
}


RecordResource::~RecordResource() throw() {
}


void RecordResource::__set_name(const std::string& val) {
  this->name = val;
}

void RecordResource::__set_path(const std::string& val) {
  this->path = val;
}

void RecordResource::__set_startTime(const int64_t val) {
  this->startTime = val;
}

void RecordResource::__set_timeLength(const int64_t val) {
  this->timeLength = val;
}

const char* RecordResource::ascii_fingerprint = "50272E49E7C02012722B8F62131C940B";
const uint8_t RecordResource::binary_fingerprint[16] = {0x50,0x27,0x2E,0x49,0xE7,0xC0,0x20,0x12,0x72,0x2B,0x8F,0x62,0x13,0x1C,0x94,0x0B};

uint32_t RecordResource::read(::apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->name);
          this->__isset.name = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->path);
          this->__isset.path = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->startTime);
          this->__isset.startTime = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->timeLength);
          this->__isset.timeLength = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t RecordResource::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  oprot->incrementRecursionDepth();
  xfer += oprot->writeStructBegin("RecordResource");

  xfer += oprot->writeFieldBegin("name", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->name);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("path", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeString(this->path);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("startTime", ::apache::thrift::protocol::T_I64, 3);
  xfer += oprot->writeI64(this->startTime);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("timeLength", ::apache::thrift::protocol::T_I64, 4);
  xfer += oprot->writeI64(this->timeLength);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  oprot->decrementRecursionDepth();
  return xfer;
}

void swap(RecordResource &a, RecordResource &b) {
  using ::std::swap;
  swap(a.name, b.name);
  swap(a.path, b.path);
  swap(a.startTime, b.startTime);
  swap(a.timeLength, b.timeLength);
  swap(a.__isset, b.__isset);
}

RecordResource::RecordResource(const RecordResource& other7) {
  name = other7.name;
  path = other7.path;
  startTime = other7.startTime;
  timeLength = other7.timeLength;
  __isset = other7.__isset;
}
RecordResource& RecordResource::operator=(const RecordResource& other8) {
  name = other8.name;
  path = other8.path;
  startTime = other8.startTime;
  timeLength = other8.timeLength;
  __isset = other8.__isset;
  return *this;
}
std::ostream& operator<<(std::ostream& out, const RecordResource& obj) {
  using apache::thrift::to_string;
  out << "RecordResource(";
  out << "name=" << to_string(obj.name);
  out << ", " << "path=" << to_string(obj.path);
  out << ", " << "startTime=" << to_string(obj.startTime);
  out << ", " << "timeLength=" << to_string(obj.timeLength);
  out << ")";
  return out;
}

} // namespace
