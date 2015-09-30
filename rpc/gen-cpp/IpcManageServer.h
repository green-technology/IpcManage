/**
 * Autogenerated by Thrift Compiler (0.9.2)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef IpcManageServer_H
#define IpcManageServer_H

#include <thrift/TDispatchProcessor.h>
#include "IpcManageServer_types.h"

namespace ipcms {

class IpcManageServerIf {
 public:
  virtual ~IpcManageServerIf() {}
  virtual void UserLogin( ::ipcms::UserLoginReturnStruct& _return, const std::string& userName) = 0;
  virtual bool UserLogout(const  ::ipcms::UserVerificationDataPacket& userVerify) = 0;
  virtual void GetResInfoList(std::vector< ::ipcms::ResourceInfoReturnStruct> & _return, const  ::ipcms::UserVerificationDataPacket& userVerify, const  ::ipcms::ResourceType::type resType) = 0;
  virtual int8_t PlayVideo(const  ::ipcms::UserVerificationDataPacket& userVerify, const  ::ipcms::PlayVideoDataPacket& playVideo) = 0;
  virtual void RequestPTZControl( ::ipcms::RequestPTZControlReturnStruct& _return, const  ::ipcms::UserVerificationDataPacket& userVerify, const  ::ipcms::RequestPTZControlDataPacket& requestPTZ) = 0;
  virtual void PTZControl( ::ipcms::PTZControlReturnStruct& _return, const  ::ipcms::UserVerificationDataPacket& userVerify, const  ::ipcms::PTZControlDataPacket& command) = 0;
};

class IpcManageServerIfFactory {
 public:
  typedef IpcManageServerIf Handler;

  virtual ~IpcManageServerIfFactory() {}

  virtual IpcManageServerIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(IpcManageServerIf* /* handler */) = 0;
};

class IpcManageServerIfSingletonFactory : virtual public IpcManageServerIfFactory {
 public:
  IpcManageServerIfSingletonFactory(const boost::shared_ptr<IpcManageServerIf>& iface) : iface_(iface) {}
  virtual ~IpcManageServerIfSingletonFactory() {}

  virtual IpcManageServerIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(IpcManageServerIf* /* handler */) {}

 protected:
  boost::shared_ptr<IpcManageServerIf> iface_;
};

class IpcManageServerNull : virtual public IpcManageServerIf {
 public:
  virtual ~IpcManageServerNull() {}
  void UserLogin( ::ipcms::UserLoginReturnStruct& /* _return */, const std::string& /* userName */) {
    return;
  }
  bool UserLogout(const  ::ipcms::UserVerificationDataPacket& /* userVerify */) {
    bool _return = false;
    return _return;
  }
  void GetResInfoList(std::vector< ::ipcms::ResourceInfoReturnStruct> & /* _return */, const  ::ipcms::UserVerificationDataPacket& /* userVerify */, const  ::ipcms::ResourceType::type /* resType */) {
    return;
  }
  int8_t PlayVideo(const  ::ipcms::UserVerificationDataPacket& /* userVerify */, const  ::ipcms::PlayVideoDataPacket& /* playVideo */) {
    int8_t _return = 0;
    return _return;
  }
  void RequestPTZControl( ::ipcms::RequestPTZControlReturnStruct& /* _return */, const  ::ipcms::UserVerificationDataPacket& /* userVerify */, const  ::ipcms::RequestPTZControlDataPacket& /* requestPTZ */) {
    return;
  }
  void PTZControl( ::ipcms::PTZControlReturnStruct& /* _return */, const  ::ipcms::UserVerificationDataPacket& /* userVerify */, const  ::ipcms::PTZControlDataPacket& /* command */) {
    return;
  }
};

typedef struct _IpcManageServer_UserLogin_args__isset {
  _IpcManageServer_UserLogin_args__isset() : userName(false) {}
  bool userName :1;
} _IpcManageServer_UserLogin_args__isset;

class IpcManageServer_UserLogin_args {
 public:

  static const char* ascii_fingerprint; // = "EFB929595D312AC8F305D5A794CFEDA1";
  static const uint8_t binary_fingerprint[16]; // = {0xEF,0xB9,0x29,0x59,0x5D,0x31,0x2A,0xC8,0xF3,0x05,0xD5,0xA7,0x94,0xCF,0xED,0xA1};

  IpcManageServer_UserLogin_args(const IpcManageServer_UserLogin_args&);
  IpcManageServer_UserLogin_args& operator=(const IpcManageServer_UserLogin_args&);
  IpcManageServer_UserLogin_args() : userName() {
  }

  virtual ~IpcManageServer_UserLogin_args() throw();
  std::string userName;

  _IpcManageServer_UserLogin_args__isset __isset;

  void __set_userName(const std::string& val);

  bool operator == (const IpcManageServer_UserLogin_args & rhs) const
  {
    if (!(userName == rhs.userName))
      return false;
    return true;
  }
  bool operator != (const IpcManageServer_UserLogin_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const IpcManageServer_UserLogin_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const IpcManageServer_UserLogin_args& obj);
};


class IpcManageServer_UserLogin_pargs {
 public:

  static const char* ascii_fingerprint; // = "EFB929595D312AC8F305D5A794CFEDA1";
  static const uint8_t binary_fingerprint[16]; // = {0xEF,0xB9,0x29,0x59,0x5D,0x31,0x2A,0xC8,0xF3,0x05,0xD5,0xA7,0x94,0xCF,0xED,0xA1};


  virtual ~IpcManageServer_UserLogin_pargs() throw();
  const std::string* userName;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const IpcManageServer_UserLogin_pargs& obj);
};

typedef struct _IpcManageServer_UserLogin_result__isset {
  _IpcManageServer_UserLogin_result__isset() : success(false) {}
  bool success :1;
} _IpcManageServer_UserLogin_result__isset;

class IpcManageServer_UserLogin_result {
 public:

  static const char* ascii_fingerprint; // = "8A4883805B430A4F66D977E3EC99E200";
  static const uint8_t binary_fingerprint[16]; // = {0x8A,0x48,0x83,0x80,0x5B,0x43,0x0A,0x4F,0x66,0xD9,0x77,0xE3,0xEC,0x99,0xE2,0x00};

  IpcManageServer_UserLogin_result(const IpcManageServer_UserLogin_result&);
  IpcManageServer_UserLogin_result& operator=(const IpcManageServer_UserLogin_result&);
  IpcManageServer_UserLogin_result() {
  }

  virtual ~IpcManageServer_UserLogin_result() throw();
   ::ipcms::UserLoginReturnStruct success;

  _IpcManageServer_UserLogin_result__isset __isset;

  void __set_success(const  ::ipcms::UserLoginReturnStruct& val);

  bool operator == (const IpcManageServer_UserLogin_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const IpcManageServer_UserLogin_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const IpcManageServer_UserLogin_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const IpcManageServer_UserLogin_result& obj);
};

typedef struct _IpcManageServer_UserLogin_presult__isset {
  _IpcManageServer_UserLogin_presult__isset() : success(false) {}
  bool success :1;
} _IpcManageServer_UserLogin_presult__isset;

class IpcManageServer_UserLogin_presult {
 public:

  static const char* ascii_fingerprint; // = "8A4883805B430A4F66D977E3EC99E200";
  static const uint8_t binary_fingerprint[16]; // = {0x8A,0x48,0x83,0x80,0x5B,0x43,0x0A,0x4F,0x66,0xD9,0x77,0xE3,0xEC,0x99,0xE2,0x00};


  virtual ~IpcManageServer_UserLogin_presult() throw();
   ::ipcms::UserLoginReturnStruct* success;

  _IpcManageServer_UserLogin_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

  friend std::ostream& operator<<(std::ostream& out, const IpcManageServer_UserLogin_presult& obj);
};

typedef struct _IpcManageServer_UserLogout_args__isset {
  _IpcManageServer_UserLogout_args__isset() : userVerify(false) {}
  bool userVerify :1;
} _IpcManageServer_UserLogout_args__isset;

class IpcManageServer_UserLogout_args {
 public:

  static const char* ascii_fingerprint; // = "A756D3DBE614FB13F70BF7F7B6EB3D73";
  static const uint8_t binary_fingerprint[16]; // = {0xA7,0x56,0xD3,0xDB,0xE6,0x14,0xFB,0x13,0xF7,0x0B,0xF7,0xF7,0xB6,0xEB,0x3D,0x73};

  IpcManageServer_UserLogout_args(const IpcManageServer_UserLogout_args&);
  IpcManageServer_UserLogout_args& operator=(const IpcManageServer_UserLogout_args&);
  IpcManageServer_UserLogout_args() {
  }

  virtual ~IpcManageServer_UserLogout_args() throw();
   ::ipcms::UserVerificationDataPacket userVerify;

  _IpcManageServer_UserLogout_args__isset __isset;

  void __set_userVerify(const  ::ipcms::UserVerificationDataPacket& val);

  bool operator == (const IpcManageServer_UserLogout_args & rhs) const
  {
    if (!(userVerify == rhs.userVerify))
      return false;
    return true;
  }
  bool operator != (const IpcManageServer_UserLogout_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const IpcManageServer_UserLogout_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const IpcManageServer_UserLogout_args& obj);
};


class IpcManageServer_UserLogout_pargs {
 public:

  static const char* ascii_fingerprint; // = "A756D3DBE614FB13F70BF7F7B6EB3D73";
  static const uint8_t binary_fingerprint[16]; // = {0xA7,0x56,0xD3,0xDB,0xE6,0x14,0xFB,0x13,0xF7,0x0B,0xF7,0xF7,0xB6,0xEB,0x3D,0x73};


  virtual ~IpcManageServer_UserLogout_pargs() throw();
  const  ::ipcms::UserVerificationDataPacket* userVerify;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const IpcManageServer_UserLogout_pargs& obj);
};

typedef struct _IpcManageServer_UserLogout_result__isset {
  _IpcManageServer_UserLogout_result__isset() : success(false) {}
  bool success :1;
} _IpcManageServer_UserLogout_result__isset;

class IpcManageServer_UserLogout_result {
 public:

  static const char* ascii_fingerprint; // = "D9D3B4421B1F23CB4063C80B484E7909";
  static const uint8_t binary_fingerprint[16]; // = {0xD9,0xD3,0xB4,0x42,0x1B,0x1F,0x23,0xCB,0x40,0x63,0xC8,0x0B,0x48,0x4E,0x79,0x09};

  IpcManageServer_UserLogout_result(const IpcManageServer_UserLogout_result&);
  IpcManageServer_UserLogout_result& operator=(const IpcManageServer_UserLogout_result&);
  IpcManageServer_UserLogout_result() : success(0) {
  }

  virtual ~IpcManageServer_UserLogout_result() throw();
  bool success;

  _IpcManageServer_UserLogout_result__isset __isset;

  void __set_success(const bool val);

  bool operator == (const IpcManageServer_UserLogout_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const IpcManageServer_UserLogout_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const IpcManageServer_UserLogout_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const IpcManageServer_UserLogout_result& obj);
};

typedef struct _IpcManageServer_UserLogout_presult__isset {
  _IpcManageServer_UserLogout_presult__isset() : success(false) {}
  bool success :1;
} _IpcManageServer_UserLogout_presult__isset;

class IpcManageServer_UserLogout_presult {
 public:

  static const char* ascii_fingerprint; // = "D9D3B4421B1F23CB4063C80B484E7909";
  static const uint8_t binary_fingerprint[16]; // = {0xD9,0xD3,0xB4,0x42,0x1B,0x1F,0x23,0xCB,0x40,0x63,0xC8,0x0B,0x48,0x4E,0x79,0x09};


  virtual ~IpcManageServer_UserLogout_presult() throw();
  bool* success;

  _IpcManageServer_UserLogout_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

  friend std::ostream& operator<<(std::ostream& out, const IpcManageServer_UserLogout_presult& obj);
};

typedef struct _IpcManageServer_GetResInfoList_args__isset {
  _IpcManageServer_GetResInfoList_args__isset() : userVerify(false), resType(false) {}
  bool userVerify :1;
  bool resType :1;
} _IpcManageServer_GetResInfoList_args__isset;

class IpcManageServer_GetResInfoList_args {
 public:

  static const char* ascii_fingerprint; // = "96624C6E05E36D9504ECD1592045D03B";
  static const uint8_t binary_fingerprint[16]; // = {0x96,0x62,0x4C,0x6E,0x05,0xE3,0x6D,0x95,0x04,0xEC,0xD1,0x59,0x20,0x45,0xD0,0x3B};

  IpcManageServer_GetResInfoList_args(const IpcManageServer_GetResInfoList_args&);
  IpcManageServer_GetResInfoList_args& operator=(const IpcManageServer_GetResInfoList_args&);
  IpcManageServer_GetResInfoList_args() : resType(( ::ipcms::ResourceType::type)0) {
  }

  virtual ~IpcManageServer_GetResInfoList_args() throw();
   ::ipcms::UserVerificationDataPacket userVerify;
   ::ipcms::ResourceType::type resType;

  _IpcManageServer_GetResInfoList_args__isset __isset;

  void __set_userVerify(const  ::ipcms::UserVerificationDataPacket& val);

  void __set_resType(const  ::ipcms::ResourceType::type val);

  bool operator == (const IpcManageServer_GetResInfoList_args & rhs) const
  {
    if (!(userVerify == rhs.userVerify))
      return false;
    if (!(resType == rhs.resType))
      return false;
    return true;
  }
  bool operator != (const IpcManageServer_GetResInfoList_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const IpcManageServer_GetResInfoList_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const IpcManageServer_GetResInfoList_args& obj);
};


class IpcManageServer_GetResInfoList_pargs {
 public:

  static const char* ascii_fingerprint; // = "96624C6E05E36D9504ECD1592045D03B";
  static const uint8_t binary_fingerprint[16]; // = {0x96,0x62,0x4C,0x6E,0x05,0xE3,0x6D,0x95,0x04,0xEC,0xD1,0x59,0x20,0x45,0xD0,0x3B};


  virtual ~IpcManageServer_GetResInfoList_pargs() throw();
  const  ::ipcms::UserVerificationDataPacket* userVerify;
  const  ::ipcms::ResourceType::type* resType;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const IpcManageServer_GetResInfoList_pargs& obj);
};

typedef struct _IpcManageServer_GetResInfoList_result__isset {
  _IpcManageServer_GetResInfoList_result__isset() : success(false) {}
  bool success :1;
} _IpcManageServer_GetResInfoList_result__isset;

class IpcManageServer_GetResInfoList_result {
 public:

  static const char* ascii_fingerprint; // = "F0424A1243C148C47B03D0C5C069753A";
  static const uint8_t binary_fingerprint[16]; // = {0xF0,0x42,0x4A,0x12,0x43,0xC1,0x48,0xC4,0x7B,0x03,0xD0,0xC5,0xC0,0x69,0x75,0x3A};

  IpcManageServer_GetResInfoList_result(const IpcManageServer_GetResInfoList_result&);
  IpcManageServer_GetResInfoList_result& operator=(const IpcManageServer_GetResInfoList_result&);
  IpcManageServer_GetResInfoList_result() {
  }

  virtual ~IpcManageServer_GetResInfoList_result() throw();
  std::vector< ::ipcms::ResourceInfoReturnStruct>  success;

  _IpcManageServer_GetResInfoList_result__isset __isset;

  void __set_success(const std::vector< ::ipcms::ResourceInfoReturnStruct> & val);

  bool operator == (const IpcManageServer_GetResInfoList_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const IpcManageServer_GetResInfoList_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const IpcManageServer_GetResInfoList_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const IpcManageServer_GetResInfoList_result& obj);
};

typedef struct _IpcManageServer_GetResInfoList_presult__isset {
  _IpcManageServer_GetResInfoList_presult__isset() : success(false) {}
  bool success :1;
} _IpcManageServer_GetResInfoList_presult__isset;

class IpcManageServer_GetResInfoList_presult {
 public:

  static const char* ascii_fingerprint; // = "F0424A1243C148C47B03D0C5C069753A";
  static const uint8_t binary_fingerprint[16]; // = {0xF0,0x42,0x4A,0x12,0x43,0xC1,0x48,0xC4,0x7B,0x03,0xD0,0xC5,0xC0,0x69,0x75,0x3A};


  virtual ~IpcManageServer_GetResInfoList_presult() throw();
  std::vector< ::ipcms::ResourceInfoReturnStruct> * success;

  _IpcManageServer_GetResInfoList_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

  friend std::ostream& operator<<(std::ostream& out, const IpcManageServer_GetResInfoList_presult& obj);
};

typedef struct _IpcManageServer_PlayVideo_args__isset {
  _IpcManageServer_PlayVideo_args__isset() : userVerify(false), playVideo(false) {}
  bool userVerify :1;
  bool playVideo :1;
} _IpcManageServer_PlayVideo_args__isset;

class IpcManageServer_PlayVideo_args {
 public:

  static const char* ascii_fingerprint; // = "FA604883F8FA2BC2718FE18D475E02E8";
  static const uint8_t binary_fingerprint[16]; // = {0xFA,0x60,0x48,0x83,0xF8,0xFA,0x2B,0xC2,0x71,0x8F,0xE1,0x8D,0x47,0x5E,0x02,0xE8};

  IpcManageServer_PlayVideo_args(const IpcManageServer_PlayVideo_args&);
  IpcManageServer_PlayVideo_args& operator=(const IpcManageServer_PlayVideo_args&);
  IpcManageServer_PlayVideo_args() {
  }

  virtual ~IpcManageServer_PlayVideo_args() throw();
   ::ipcms::UserVerificationDataPacket userVerify;
   ::ipcms::PlayVideoDataPacket playVideo;

  _IpcManageServer_PlayVideo_args__isset __isset;

  void __set_userVerify(const  ::ipcms::UserVerificationDataPacket& val);

  void __set_playVideo(const  ::ipcms::PlayVideoDataPacket& val);

  bool operator == (const IpcManageServer_PlayVideo_args & rhs) const
  {
    if (!(userVerify == rhs.userVerify))
      return false;
    if (!(playVideo == rhs.playVideo))
      return false;
    return true;
  }
  bool operator != (const IpcManageServer_PlayVideo_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const IpcManageServer_PlayVideo_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const IpcManageServer_PlayVideo_args& obj);
};


class IpcManageServer_PlayVideo_pargs {
 public:

  static const char* ascii_fingerprint; // = "FA604883F8FA2BC2718FE18D475E02E8";
  static const uint8_t binary_fingerprint[16]; // = {0xFA,0x60,0x48,0x83,0xF8,0xFA,0x2B,0xC2,0x71,0x8F,0xE1,0x8D,0x47,0x5E,0x02,0xE8};


  virtual ~IpcManageServer_PlayVideo_pargs() throw();
  const  ::ipcms::UserVerificationDataPacket* userVerify;
  const  ::ipcms::PlayVideoDataPacket* playVideo;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const IpcManageServer_PlayVideo_pargs& obj);
};

typedef struct _IpcManageServer_PlayVideo_result__isset {
  _IpcManageServer_PlayVideo_result__isset() : success(false) {}
  bool success :1;
} _IpcManageServer_PlayVideo_result__isset;

class IpcManageServer_PlayVideo_result {
 public:

  static const char* ascii_fingerprint; // = "508A6EF1C84BD28CDBD0D21C132C2613";
  static const uint8_t binary_fingerprint[16]; // = {0x50,0x8A,0x6E,0xF1,0xC8,0x4B,0xD2,0x8C,0xDB,0xD0,0xD2,0x1C,0x13,0x2C,0x26,0x13};

  IpcManageServer_PlayVideo_result(const IpcManageServer_PlayVideo_result&);
  IpcManageServer_PlayVideo_result& operator=(const IpcManageServer_PlayVideo_result&);
  IpcManageServer_PlayVideo_result() : success(0) {
  }

  virtual ~IpcManageServer_PlayVideo_result() throw();
  int8_t success;

  _IpcManageServer_PlayVideo_result__isset __isset;

  void __set_success(const int8_t val);

  bool operator == (const IpcManageServer_PlayVideo_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const IpcManageServer_PlayVideo_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const IpcManageServer_PlayVideo_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const IpcManageServer_PlayVideo_result& obj);
};

typedef struct _IpcManageServer_PlayVideo_presult__isset {
  _IpcManageServer_PlayVideo_presult__isset() : success(false) {}
  bool success :1;
} _IpcManageServer_PlayVideo_presult__isset;

class IpcManageServer_PlayVideo_presult {
 public:

  static const char* ascii_fingerprint; // = "508A6EF1C84BD28CDBD0D21C132C2613";
  static const uint8_t binary_fingerprint[16]; // = {0x50,0x8A,0x6E,0xF1,0xC8,0x4B,0xD2,0x8C,0xDB,0xD0,0xD2,0x1C,0x13,0x2C,0x26,0x13};


  virtual ~IpcManageServer_PlayVideo_presult() throw();
  int8_t* success;

  _IpcManageServer_PlayVideo_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

  friend std::ostream& operator<<(std::ostream& out, const IpcManageServer_PlayVideo_presult& obj);
};

typedef struct _IpcManageServer_RequestPTZControl_args__isset {
  _IpcManageServer_RequestPTZControl_args__isset() : userVerify(false), requestPTZ(false) {}
  bool userVerify :1;
  bool requestPTZ :1;
} _IpcManageServer_RequestPTZControl_args__isset;

class IpcManageServer_RequestPTZControl_args {
 public:

  static const char* ascii_fingerprint; // = "10AC6157B68C15728017838351E447E2";
  static const uint8_t binary_fingerprint[16]; // = {0x10,0xAC,0x61,0x57,0xB6,0x8C,0x15,0x72,0x80,0x17,0x83,0x83,0x51,0xE4,0x47,0xE2};

  IpcManageServer_RequestPTZControl_args(const IpcManageServer_RequestPTZControl_args&);
  IpcManageServer_RequestPTZControl_args& operator=(const IpcManageServer_RequestPTZControl_args&);
  IpcManageServer_RequestPTZControl_args() {
  }

  virtual ~IpcManageServer_RequestPTZControl_args() throw();
   ::ipcms::UserVerificationDataPacket userVerify;
   ::ipcms::RequestPTZControlDataPacket requestPTZ;

  _IpcManageServer_RequestPTZControl_args__isset __isset;

  void __set_userVerify(const  ::ipcms::UserVerificationDataPacket& val);

  void __set_requestPTZ(const  ::ipcms::RequestPTZControlDataPacket& val);

  bool operator == (const IpcManageServer_RequestPTZControl_args & rhs) const
  {
    if (!(userVerify == rhs.userVerify))
      return false;
    if (!(requestPTZ == rhs.requestPTZ))
      return false;
    return true;
  }
  bool operator != (const IpcManageServer_RequestPTZControl_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const IpcManageServer_RequestPTZControl_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const IpcManageServer_RequestPTZControl_args& obj);
};


class IpcManageServer_RequestPTZControl_pargs {
 public:

  static const char* ascii_fingerprint; // = "10AC6157B68C15728017838351E447E2";
  static const uint8_t binary_fingerprint[16]; // = {0x10,0xAC,0x61,0x57,0xB6,0x8C,0x15,0x72,0x80,0x17,0x83,0x83,0x51,0xE4,0x47,0xE2};


  virtual ~IpcManageServer_RequestPTZControl_pargs() throw();
  const  ::ipcms::UserVerificationDataPacket* userVerify;
  const  ::ipcms::RequestPTZControlDataPacket* requestPTZ;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const IpcManageServer_RequestPTZControl_pargs& obj);
};

typedef struct _IpcManageServer_RequestPTZControl_result__isset {
  _IpcManageServer_RequestPTZControl_result__isset() : success(false) {}
  bool success :1;
} _IpcManageServer_RequestPTZControl_result__isset;

class IpcManageServer_RequestPTZControl_result {
 public:

  static const char* ascii_fingerprint; // = "930EDC5F32BFCF7D1564DDC00CA79A91";
  static const uint8_t binary_fingerprint[16]; // = {0x93,0x0E,0xDC,0x5F,0x32,0xBF,0xCF,0x7D,0x15,0x64,0xDD,0xC0,0x0C,0xA7,0x9A,0x91};

  IpcManageServer_RequestPTZControl_result(const IpcManageServer_RequestPTZControl_result&);
  IpcManageServer_RequestPTZControl_result& operator=(const IpcManageServer_RequestPTZControl_result&);
  IpcManageServer_RequestPTZControl_result() {
  }

  virtual ~IpcManageServer_RequestPTZControl_result() throw();
   ::ipcms::RequestPTZControlReturnStruct success;

  _IpcManageServer_RequestPTZControl_result__isset __isset;

  void __set_success(const  ::ipcms::RequestPTZControlReturnStruct& val);

  bool operator == (const IpcManageServer_RequestPTZControl_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const IpcManageServer_RequestPTZControl_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const IpcManageServer_RequestPTZControl_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const IpcManageServer_RequestPTZControl_result& obj);
};

typedef struct _IpcManageServer_RequestPTZControl_presult__isset {
  _IpcManageServer_RequestPTZControl_presult__isset() : success(false) {}
  bool success :1;
} _IpcManageServer_RequestPTZControl_presult__isset;

class IpcManageServer_RequestPTZControl_presult {
 public:

  static const char* ascii_fingerprint; // = "930EDC5F32BFCF7D1564DDC00CA79A91";
  static const uint8_t binary_fingerprint[16]; // = {0x93,0x0E,0xDC,0x5F,0x32,0xBF,0xCF,0x7D,0x15,0x64,0xDD,0xC0,0x0C,0xA7,0x9A,0x91};


  virtual ~IpcManageServer_RequestPTZControl_presult() throw();
   ::ipcms::RequestPTZControlReturnStruct* success;

  _IpcManageServer_RequestPTZControl_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

  friend std::ostream& operator<<(std::ostream& out, const IpcManageServer_RequestPTZControl_presult& obj);
};

typedef struct _IpcManageServer_PTZControl_args__isset {
  _IpcManageServer_PTZControl_args__isset() : userVerify(false), command(false) {}
  bool userVerify :1;
  bool command :1;
} _IpcManageServer_PTZControl_args__isset;

class IpcManageServer_PTZControl_args {
 public:

  static const char* ascii_fingerprint; // = "59B81EF3997909A6AB828FEE1985912E";
  static const uint8_t binary_fingerprint[16]; // = {0x59,0xB8,0x1E,0xF3,0x99,0x79,0x09,0xA6,0xAB,0x82,0x8F,0xEE,0x19,0x85,0x91,0x2E};

  IpcManageServer_PTZControl_args(const IpcManageServer_PTZControl_args&);
  IpcManageServer_PTZControl_args& operator=(const IpcManageServer_PTZControl_args&);
  IpcManageServer_PTZControl_args() {
  }

  virtual ~IpcManageServer_PTZControl_args() throw();
   ::ipcms::UserVerificationDataPacket userVerify;
   ::ipcms::PTZControlDataPacket command;

  _IpcManageServer_PTZControl_args__isset __isset;

  void __set_userVerify(const  ::ipcms::UserVerificationDataPacket& val);

  void __set_command(const  ::ipcms::PTZControlDataPacket& val);

  bool operator == (const IpcManageServer_PTZControl_args & rhs) const
  {
    if (!(userVerify == rhs.userVerify))
      return false;
    if (!(command == rhs.command))
      return false;
    return true;
  }
  bool operator != (const IpcManageServer_PTZControl_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const IpcManageServer_PTZControl_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const IpcManageServer_PTZControl_args& obj);
};


class IpcManageServer_PTZControl_pargs {
 public:

  static const char* ascii_fingerprint; // = "59B81EF3997909A6AB828FEE1985912E";
  static const uint8_t binary_fingerprint[16]; // = {0x59,0xB8,0x1E,0xF3,0x99,0x79,0x09,0xA6,0xAB,0x82,0x8F,0xEE,0x19,0x85,0x91,0x2E};


  virtual ~IpcManageServer_PTZControl_pargs() throw();
  const  ::ipcms::UserVerificationDataPacket* userVerify;
  const  ::ipcms::PTZControlDataPacket* command;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const IpcManageServer_PTZControl_pargs& obj);
};

typedef struct _IpcManageServer_PTZControl_result__isset {
  _IpcManageServer_PTZControl_result__isset() : success(false) {}
  bool success :1;
} _IpcManageServer_PTZControl_result__isset;

class IpcManageServer_PTZControl_result {
 public:

  static const char* ascii_fingerprint; // = "8A8C184627B0E39FCFFA975E8A67D115";
  static const uint8_t binary_fingerprint[16]; // = {0x8A,0x8C,0x18,0x46,0x27,0xB0,0xE3,0x9F,0xCF,0xFA,0x97,0x5E,0x8A,0x67,0xD1,0x15};

  IpcManageServer_PTZControl_result(const IpcManageServer_PTZControl_result&);
  IpcManageServer_PTZControl_result& operator=(const IpcManageServer_PTZControl_result&);
  IpcManageServer_PTZControl_result() {
  }

  virtual ~IpcManageServer_PTZControl_result() throw();
   ::ipcms::PTZControlReturnStruct success;

  _IpcManageServer_PTZControl_result__isset __isset;

  void __set_success(const  ::ipcms::PTZControlReturnStruct& val);

  bool operator == (const IpcManageServer_PTZControl_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const IpcManageServer_PTZControl_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const IpcManageServer_PTZControl_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const IpcManageServer_PTZControl_result& obj);
};

typedef struct _IpcManageServer_PTZControl_presult__isset {
  _IpcManageServer_PTZControl_presult__isset() : success(false) {}
  bool success :1;
} _IpcManageServer_PTZControl_presult__isset;

class IpcManageServer_PTZControl_presult {
 public:

  static const char* ascii_fingerprint; // = "8A8C184627B0E39FCFFA975E8A67D115";
  static const uint8_t binary_fingerprint[16]; // = {0x8A,0x8C,0x18,0x46,0x27,0xB0,0xE3,0x9F,0xCF,0xFA,0x97,0x5E,0x8A,0x67,0xD1,0x15};


  virtual ~IpcManageServer_PTZControl_presult() throw();
   ::ipcms::PTZControlReturnStruct* success;

  _IpcManageServer_PTZControl_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

  friend std::ostream& operator<<(std::ostream& out, const IpcManageServer_PTZControl_presult& obj);
};

class IpcManageServerClient : virtual public IpcManageServerIf {
 public:
  IpcManageServerClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  IpcManageServerClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void UserLogin( ::ipcms::UserLoginReturnStruct& _return, const std::string& userName);
  void send_UserLogin(const std::string& userName);
  void recv_UserLogin( ::ipcms::UserLoginReturnStruct& _return);
  bool UserLogout(const  ::ipcms::UserVerificationDataPacket& userVerify);
  void send_UserLogout(const  ::ipcms::UserVerificationDataPacket& userVerify);
  bool recv_UserLogout();
  void GetResInfoList(std::vector< ::ipcms::ResourceInfoReturnStruct> & _return, const  ::ipcms::UserVerificationDataPacket& userVerify, const  ::ipcms::ResourceType::type resType);
  void send_GetResInfoList(const  ::ipcms::UserVerificationDataPacket& userVerify, const  ::ipcms::ResourceType::type resType);
  void recv_GetResInfoList(std::vector< ::ipcms::ResourceInfoReturnStruct> & _return);
  int8_t PlayVideo(const  ::ipcms::UserVerificationDataPacket& userVerify, const  ::ipcms::PlayVideoDataPacket& playVideo);
  void send_PlayVideo(const  ::ipcms::UserVerificationDataPacket& userVerify, const  ::ipcms::PlayVideoDataPacket& playVideo);
  int8_t recv_PlayVideo();
  void RequestPTZControl( ::ipcms::RequestPTZControlReturnStruct& _return, const  ::ipcms::UserVerificationDataPacket& userVerify, const  ::ipcms::RequestPTZControlDataPacket& requestPTZ);
  void send_RequestPTZControl(const  ::ipcms::UserVerificationDataPacket& userVerify, const  ::ipcms::RequestPTZControlDataPacket& requestPTZ);
  void recv_RequestPTZControl( ::ipcms::RequestPTZControlReturnStruct& _return);
  void PTZControl( ::ipcms::PTZControlReturnStruct& _return, const  ::ipcms::UserVerificationDataPacket& userVerify, const  ::ipcms::PTZControlDataPacket& command);
  void send_PTZControl(const  ::ipcms::UserVerificationDataPacket& userVerify, const  ::ipcms::PTZControlDataPacket& command);
  void recv_PTZControl( ::ipcms::PTZControlReturnStruct& _return);
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class IpcManageServerProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  boost::shared_ptr<IpcManageServerIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (IpcManageServerProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_UserLogin(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_UserLogout(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_GetResInfoList(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_PlayVideo(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_RequestPTZControl(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_PTZControl(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  IpcManageServerProcessor(boost::shared_ptr<IpcManageServerIf> iface) :
    iface_(iface) {
    processMap_["UserLogin"] = &IpcManageServerProcessor::process_UserLogin;
    processMap_["UserLogout"] = &IpcManageServerProcessor::process_UserLogout;
    processMap_["GetResInfoList"] = &IpcManageServerProcessor::process_GetResInfoList;
    processMap_["PlayVideo"] = &IpcManageServerProcessor::process_PlayVideo;
    processMap_["RequestPTZControl"] = &IpcManageServerProcessor::process_RequestPTZControl;
    processMap_["PTZControl"] = &IpcManageServerProcessor::process_PTZControl;
  }

  virtual ~IpcManageServerProcessor() {}
};

class IpcManageServerProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  IpcManageServerProcessorFactory(const ::boost::shared_ptr< IpcManageServerIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::boost::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::boost::shared_ptr< IpcManageServerIfFactory > handlerFactory_;
};

class IpcManageServerMultiface : virtual public IpcManageServerIf {
 public:
  IpcManageServerMultiface(std::vector<boost::shared_ptr<IpcManageServerIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~IpcManageServerMultiface() {}
 protected:
  std::vector<boost::shared_ptr<IpcManageServerIf> > ifaces_;
  IpcManageServerMultiface() {}
  void add(boost::shared_ptr<IpcManageServerIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  void UserLogin( ::ipcms::UserLoginReturnStruct& _return, const std::string& userName) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->UserLogin(_return, userName);
    }
    ifaces_[i]->UserLogin(_return, userName);
    return;
  }

  bool UserLogout(const  ::ipcms::UserVerificationDataPacket& userVerify) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->UserLogout(userVerify);
    }
    return ifaces_[i]->UserLogout(userVerify);
  }

  void GetResInfoList(std::vector< ::ipcms::ResourceInfoReturnStruct> & _return, const  ::ipcms::UserVerificationDataPacket& userVerify, const  ::ipcms::ResourceType::type resType) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->GetResInfoList(_return, userVerify, resType);
    }
    ifaces_[i]->GetResInfoList(_return, userVerify, resType);
    return;
  }

  int8_t PlayVideo(const  ::ipcms::UserVerificationDataPacket& userVerify, const  ::ipcms::PlayVideoDataPacket& playVideo) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->PlayVideo(userVerify, playVideo);
    }
    return ifaces_[i]->PlayVideo(userVerify, playVideo);
  }

  void RequestPTZControl( ::ipcms::RequestPTZControlReturnStruct& _return, const  ::ipcms::UserVerificationDataPacket& userVerify, const  ::ipcms::RequestPTZControlDataPacket& requestPTZ) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->RequestPTZControl(_return, userVerify, requestPTZ);
    }
    ifaces_[i]->RequestPTZControl(_return, userVerify, requestPTZ);
    return;
  }

  void PTZControl( ::ipcms::PTZControlReturnStruct& _return, const  ::ipcms::UserVerificationDataPacket& userVerify, const  ::ipcms::PTZControlDataPacket& command) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->PTZControl(_return, userVerify, command);
    }
    ifaces_[i]->PTZControl(_return, userVerify, command);
    return;
  }

};

} // namespace

#endif
