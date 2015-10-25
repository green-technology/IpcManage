/**
 * Autogenerated by Thrift Compiler (0.9.2)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef ReturnStruct_TYPES_H
#define ReturnStruct_TYPES_H

#include <iosfwd>

#include <thrift/Thrift.h>
#include <thrift/TApplicationException.h>
#include <thrift/protocol/TProtocol.h>
#include <thrift/transport/TTransport.h>

#include <thrift/cxxfunctional.h>


namespace ipcms {

struct ResourceType {
  enum type {
    ResourceTypeALL = 0,
    ResourceTypeReplay = 1,
    ResourceTypeIPC = 2
  };
};

extern const std::map<int, const char*> _ResourceType_VALUES_TO_NAMES;

struct PTZControlReturnType {
  enum type {
    PTZControlReturnTypeInvalidHandle = 0,
    PTZControlReturnTypeSuccess = 1,
    PTZControlReturnTypeError = 2
  };
};

extern const std::map<int, const char*> _PTZControlReturnType_VALUES_TO_NAMES;

struct ReturnType {
  enum type {
    Success = 0,
    InvalidUser = 1,
    InvalidHandle = 2,
    FailUnspecified = 3
  };
};

extern const std::map<int, const char*> _ReturnType_VALUES_TO_NAMES;

class UserLoginReturnStruct;

class ResourceInfoReturnStruct;

class RequestPTZControlReturnStruct;

class PTZControlReturnStruct;

typedef struct _UserLoginReturnStruct__isset {
  _UserLoginReturnStruct__isset() : ErrorNum(false), UserID(false), SessionID(false) {}
  bool ErrorNum :1;
  bool UserID :1;
  bool SessionID :1;
} _UserLoginReturnStruct__isset;

class UserLoginReturnStruct {
 public:

  static const char* ascii_fingerprint; // = "15B1A498AD6EEF5345D267BE66D87AFD";
  static const uint8_t binary_fingerprint[16]; // = {0x15,0xB1,0xA4,0x98,0xAD,0x6E,0xEF,0x53,0x45,0xD2,0x67,0xBE,0x66,0xD8,0x7A,0xFD};

  UserLoginReturnStruct(const UserLoginReturnStruct&);
  UserLoginReturnStruct& operator=(const UserLoginReturnStruct&);
  UserLoginReturnStruct() : ErrorNum(0), UserID(), SessionID() {
  }

  virtual ~UserLoginReturnStruct() throw();
  int8_t ErrorNum;
  std::string UserID;
  std::string SessionID;

  _UserLoginReturnStruct__isset __isset;

  void __set_ErrorNum(const int8_t val);

  void __set_UserID(const std::string& val);

  void __set_SessionID(const std::string& val);

  bool operator == (const UserLoginReturnStruct & rhs) const
  {
    if (!(ErrorNum == rhs.ErrorNum))
      return false;
    if (!(UserID == rhs.UserID))
      return false;
    if (!(SessionID == rhs.SessionID))
      return false;
    return true;
  }
  bool operator != (const UserLoginReturnStruct &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const UserLoginReturnStruct & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const UserLoginReturnStruct& obj);
};

void swap(UserLoginReturnStruct &a, UserLoginReturnStruct &b);

typedef struct _ResourceInfoReturnStruct__isset {
  _ResourceInfoReturnStruct__isset() : resourceType(false), IP(false), deviceName(false), hResource(false), hasPLZ(false), timeStart(false), timeEnd(false), rtspUrl(false), ID(false) {}
  bool resourceType :1;
  bool IP :1;
  bool deviceName :1;
  bool hResource :1;
  bool hasPLZ :1;
  bool timeStart :1;
  bool timeEnd :1;
  bool rtspUrl :1;
  bool ID :1;
} _ResourceInfoReturnStruct__isset;

class ResourceInfoReturnStruct {
 public:

  static const char* ascii_fingerprint; // = "439EFE098509EA5CE1F9607BA6B2E18C";
  static const uint8_t binary_fingerprint[16]; // = {0x43,0x9E,0xFE,0x09,0x85,0x09,0xEA,0x5C,0xE1,0xF9,0x60,0x7B,0xA6,0xB2,0xE1,0x8C};

  ResourceInfoReturnStruct(const ResourceInfoReturnStruct&);
  ResourceInfoReturnStruct& operator=(const ResourceInfoReturnStruct&);
  ResourceInfoReturnStruct() : resourceType((ResourceType::type)0), IP(), deviceName(), hResource(0), hasPLZ(0), timeStart(0), timeEnd(0), rtspUrl(), ID(0) {
  }

  virtual ~ResourceInfoReturnStruct() throw();
  ResourceType::type resourceType;
  std::string IP;
  std::string deviceName;
  int64_t hResource;
  bool hasPLZ;
  int64_t timeStart;
  int64_t timeEnd;
  std::string rtspUrl;
  int64_t ID;

  _ResourceInfoReturnStruct__isset __isset;

  void __set_resourceType(const ResourceType::type val);

  void __set_IP(const std::string& val);

  void __set_deviceName(const std::string& val);

  void __set_hResource(const int64_t val);

  void __set_hasPLZ(const bool val);

  void __set_timeStart(const int64_t val);

  void __set_timeEnd(const int64_t val);

  void __set_rtspUrl(const std::string& val);

  void __set_ID(const int64_t val);

  bool operator == (const ResourceInfoReturnStruct & rhs) const
  {
    if (!(resourceType == rhs.resourceType))
      return false;
    if (!(IP == rhs.IP))
      return false;
    if (!(deviceName == rhs.deviceName))
      return false;
    if (!(hResource == rhs.hResource))
      return false;
    if (!(hasPLZ == rhs.hasPLZ))
      return false;
    if (!(timeStart == rhs.timeStart))
      return false;
    if (!(timeEnd == rhs.timeEnd))
      return false;
    if (!(rtspUrl == rhs.rtspUrl))
      return false;
    if (!(ID == rhs.ID))
      return false;
    return true;
  }
  bool operator != (const ResourceInfoReturnStruct &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ResourceInfoReturnStruct & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const ResourceInfoReturnStruct& obj);
};

void swap(ResourceInfoReturnStruct &a, ResourceInfoReturnStruct &b);

typedef struct _RequestPTZControlReturnStruct__isset {
  _RequestPTZControlReturnStruct__isset() : hPTZ(false), result(false), userName(false) {}
  bool hPTZ :1;
  bool result :1;
  bool userName :1;
} _RequestPTZControlReturnStruct__isset;

class RequestPTZControlReturnStruct {
 public:

  static const char* ascii_fingerprint; // = "6B0CD68886A371B59CE1B9EDCF067801";
  static const uint8_t binary_fingerprint[16]; // = {0x6B,0x0C,0xD6,0x88,0x86,0xA3,0x71,0xB5,0x9C,0xE1,0xB9,0xED,0xCF,0x06,0x78,0x01};

  RequestPTZControlReturnStruct(const RequestPTZControlReturnStruct&);
  RequestPTZControlReturnStruct& operator=(const RequestPTZControlReturnStruct&);
  RequestPTZControlReturnStruct() : hPTZ(0), result(0), userName() {
  }

  virtual ~RequestPTZControlReturnStruct() throw();
  int64_t hPTZ;
  int64_t result;
  std::string userName;

  _RequestPTZControlReturnStruct__isset __isset;

  void __set_hPTZ(const int64_t val);

  void __set_result(const int64_t val);

  void __set_userName(const std::string& val);

  bool operator == (const RequestPTZControlReturnStruct & rhs) const
  {
    if (!(hPTZ == rhs.hPTZ))
      return false;
    if (!(result == rhs.result))
      return false;
    if (!(userName == rhs.userName))
      return false;
    return true;
  }
  bool operator != (const RequestPTZControlReturnStruct &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const RequestPTZControlReturnStruct & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const RequestPTZControlReturnStruct& obj);
};

void swap(RequestPTZControlReturnStruct &a, RequestPTZControlReturnStruct &b);

typedef struct _PTZControlReturnStruct__isset {
  _PTZControlReturnStruct__isset() : result(false) {}
  bool result :1;
} _PTZControlReturnStruct__isset;

class PTZControlReturnStruct {
 public:

  static const char* ascii_fingerprint; // = "8C1740BBF54FD399631A4549952454DB";
  static const uint8_t binary_fingerprint[16]; // = {0x8C,0x17,0x40,0xBB,0xF5,0x4F,0xD3,0x99,0x63,0x1A,0x45,0x49,0x95,0x24,0x54,0xDB};

  PTZControlReturnStruct(const PTZControlReturnStruct&);
  PTZControlReturnStruct& operator=(const PTZControlReturnStruct&);
  PTZControlReturnStruct() : result((PTZControlReturnType::type)0) {
  }

  virtual ~PTZControlReturnStruct() throw();
  PTZControlReturnType::type result;

  _PTZControlReturnStruct__isset __isset;

  void __set_result(const PTZControlReturnType::type val);

  bool operator == (const PTZControlReturnStruct & rhs) const
  {
    if (__isset.result != rhs.__isset.result)
      return false;
    else if (__isset.result && !(result == rhs.result))
      return false;
    return true;
  }
  bool operator != (const PTZControlReturnStruct &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const PTZControlReturnStruct & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const PTZControlReturnStruct& obj);
};

void swap(PTZControlReturnStruct &a, PTZControlReturnStruct &b);

} // namespace

#endif
