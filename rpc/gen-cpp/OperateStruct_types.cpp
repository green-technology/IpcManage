/**
 * Autogenerated by Thrift Compiler (0.9.2)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "OperateStruct_types.h"

#include <algorithm>
#include <ostream>

#include <thrift/TToString.h>

namespace ipcms {


UserVerificationDataPacket::~UserVerificationDataPacket() throw() {
}


void UserVerificationDataPacket::__set_UserID(const std::string& val) {
  this->UserID = val;
}

void UserVerificationDataPacket::__set_SessionID(const std::string& val) {
  this->SessionID = val;
}

const char* UserVerificationDataPacket::ascii_fingerprint = "07A9615F837F7D0A952B595DD3020972";
const uint8_t UserVerificationDataPacket::binary_fingerprint[16] = {0x07,0xA9,0x61,0x5F,0x83,0x7F,0x7D,0x0A,0x95,0x2B,0x59,0x5D,0xD3,0x02,0x09,0x72};

uint32_t UserVerificationDataPacket::read(::apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;

  bool isset_UserID = false;
  bool isset_SessionID = false;

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
          xfer += iprot->readString(this->UserID);
          isset_UserID = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->SessionID);
          isset_SessionID = true;
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

  if (!isset_UserID)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  if (!isset_SessionID)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  return xfer;
}

uint32_t UserVerificationDataPacket::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  oprot->incrementRecursionDepth();
  xfer += oprot->writeStructBegin("UserVerificationDataPacket");

  xfer += oprot->writeFieldBegin("UserID", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->UserID);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("SessionID", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeString(this->SessionID);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  oprot->decrementRecursionDepth();
  return xfer;
}

void swap(UserVerificationDataPacket &a, UserVerificationDataPacket &b) {
  using ::std::swap;
  swap(a.UserID, b.UserID);
  swap(a.SessionID, b.SessionID);
}

UserVerificationDataPacket::UserVerificationDataPacket(const UserVerificationDataPacket& other0) {
  UserID = other0.UserID;
  SessionID = other0.SessionID;
}
UserVerificationDataPacket& UserVerificationDataPacket::operator=(const UserVerificationDataPacket& other1) {
  UserID = other1.UserID;
  SessionID = other1.SessionID;
  return *this;
}
std::ostream& operator<<(std::ostream& out, const UserVerificationDataPacket& obj) {
  using apache::thrift::to_string;
  out << "UserVerificationDataPacket(";
  out << "UserID=" << to_string(obj.UserID);
  out << ", " << "SessionID=" << to_string(obj.SessionID);
  out << ")";
  return out;
}


PlayVideoDataPacket::~PlayVideoDataPacket() throw() {
}


void PlayVideoDataPacket::__set_hResource(const int64_t val) {
  this->hResource = val;
}

void PlayVideoDataPacket::__set_time(const int64_t val) {
  this->time = val;
}

void PlayVideoDataPacket::__set_speed(const int32_t val) {
  this->speed = val;
}

const char* PlayVideoDataPacket::ascii_fingerprint = "9763B9D124C8339490EA9AA9EB582188";
const uint8_t PlayVideoDataPacket::binary_fingerprint[16] = {0x97,0x63,0xB9,0xD1,0x24,0xC8,0x33,0x94,0x90,0xEA,0x9A,0xA9,0xEB,0x58,0x21,0x88};

uint32_t PlayVideoDataPacket::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          xfer += iprot->readI64(this->hResource);
          this->__isset.hResource = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->time);
          this->__isset.time = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->speed);
          this->__isset.speed = true;
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

uint32_t PlayVideoDataPacket::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  oprot->incrementRecursionDepth();
  xfer += oprot->writeStructBegin("PlayVideoDataPacket");

  xfer += oprot->writeFieldBegin("hResource", ::apache::thrift::protocol::T_I64, 1);
  xfer += oprot->writeI64(this->hResource);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("time", ::apache::thrift::protocol::T_I64, 2);
  xfer += oprot->writeI64(this->time);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("speed", ::apache::thrift::protocol::T_I32, 3);
  xfer += oprot->writeI32(this->speed);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  oprot->decrementRecursionDepth();
  return xfer;
}

void swap(PlayVideoDataPacket &a, PlayVideoDataPacket &b) {
  using ::std::swap;
  swap(a.hResource, b.hResource);
  swap(a.time, b.time);
  swap(a.speed, b.speed);
  swap(a.__isset, b.__isset);
}

PlayVideoDataPacket::PlayVideoDataPacket(const PlayVideoDataPacket& other2) {
  hResource = other2.hResource;
  time = other2.time;
  speed = other2.speed;
  __isset = other2.__isset;
}
PlayVideoDataPacket& PlayVideoDataPacket::operator=(const PlayVideoDataPacket& other3) {
  hResource = other3.hResource;
  time = other3.time;
  speed = other3.speed;
  __isset = other3.__isset;
  return *this;
}
std::ostream& operator<<(std::ostream& out, const PlayVideoDataPacket& obj) {
  using apache::thrift::to_string;
  out << "PlayVideoDataPacket(";
  out << "hResource=" << to_string(obj.hResource);
  out << ", " << "time=" << to_string(obj.time);
  out << ", " << "speed=" << to_string(obj.speed);
  out << ")";
  return out;
}


ApplyPTZControlDataPacket::~ApplyPTZControlDataPacket() throw() {
}


void ApplyPTZControlDataPacket::__set_hPLZ(const int64_t val) {
  this->hPLZ = val;
}

void ApplyPTZControlDataPacket::__set_type(const int32_t val) {
  this->type = val;
}

const char* ApplyPTZControlDataPacket::ascii_fingerprint = "AFAFBCDB9822F9D1AA4E44188E720B47";
const uint8_t ApplyPTZControlDataPacket::binary_fingerprint[16] = {0xAF,0xAF,0xBC,0xDB,0x98,0x22,0xF9,0xD1,0xAA,0x4E,0x44,0x18,0x8E,0x72,0x0B,0x47};

uint32_t ApplyPTZControlDataPacket::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          xfer += iprot->readI64(this->hPLZ);
          this->__isset.hPLZ = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->type);
          this->__isset.type = true;
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

uint32_t ApplyPTZControlDataPacket::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  oprot->incrementRecursionDepth();
  xfer += oprot->writeStructBegin("ApplyPTZControlDataPacket");

  xfer += oprot->writeFieldBegin("hPLZ", ::apache::thrift::protocol::T_I64, 1);
  xfer += oprot->writeI64(this->hPLZ);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("type", ::apache::thrift::protocol::T_I32, 2);
  xfer += oprot->writeI32(this->type);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  oprot->decrementRecursionDepth();
  return xfer;
}

void swap(ApplyPTZControlDataPacket &a, ApplyPTZControlDataPacket &b) {
  using ::std::swap;
  swap(a.hPLZ, b.hPLZ);
  swap(a.type, b.type);
  swap(a.__isset, b.__isset);
}

ApplyPTZControlDataPacket::ApplyPTZControlDataPacket(const ApplyPTZControlDataPacket& other4) {
  hPLZ = other4.hPLZ;
  type = other4.type;
  __isset = other4.__isset;
}
ApplyPTZControlDataPacket& ApplyPTZControlDataPacket::operator=(const ApplyPTZControlDataPacket& other5) {
  hPLZ = other5.hPLZ;
  type = other5.type;
  __isset = other5.__isset;
  return *this;
}
std::ostream& operator<<(std::ostream& out, const ApplyPTZControlDataPacket& obj) {
  using apache::thrift::to_string;
  out << "ApplyPTZControlDataPacket(";
  out << "hPLZ=" << to_string(obj.hPLZ);
  out << ", " << "type=" << to_string(obj.type);
  out << ")";
  return out;
}

} // namespace
