// This autogenerated skeleton file illustrates how to build a server.
// You should copy it to another filename to avoid overwriting it.

#include "IpcManageServer.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using boost::shared_ptr;

using namespace  ::ipcms;

class IpcManageServerHandler : virtual public IpcManageServerIf {
 public:
  IpcManageServerHandler() {
    // Your initialization goes here
  }

  void UserLogin( ::ipcms::UserLoginReturnStruct& _return, const std::string& userName) {
    // Your implementation goes here
    printf("UserLogin\n");
  }

  bool UserLogout(const  ::ipcms::UserVerificationDataPacket& userVerify) {
    // Your implementation goes here
    printf("UserLogout\n");
  }

  void GetResInfoList(std::vector< ::ipcms::ResourceInfoReturnStruct> & _return, const  ::ipcms::UserVerificationDataPacket& userVerify, const  ::ipcms::ResourceType::type resType) {
    // Your implementation goes here
    printf("GetResInfoList\n");
  }

  int8_t PlayVideo(const  ::ipcms::UserVerificationDataPacket& userVerify, const  ::ipcms::PlayVideoDataPacket& playVideo) {
    // Your implementation goes here
    printf("PlayVideo\n");
  }

  void RequestPTZControl( ::ipcms::RequestPTZControlReturnStruct& _return, const  ::ipcms::UserVerificationDataPacket& userVerify, const  ::ipcms::RequestPTZControlDataPacket& requestPTZ) {
    // Your implementation goes here
    printf("RequestPTZControl\n");
  }

  void PTZControl( ::ipcms::PTZControlReturnStruct& _return, const  ::ipcms::UserVerificationDataPacket& userVerify, const  ::ipcms::PTZControlDataPacket& command) {
    // Your implementation goes here
    printf("PTZControl\n");
  }

   ::ipcms::ReturnType::type ReleasePTZControl(const  ::ipcms::UserVerificationDataPacket& userVerify, const int64_t hPTZ) {
    // Your implementation goes here
    printf("ReleasePTZControl\n");
  }

   ::ipcms::ReturnType::type addResource(const  ::ipcms::UserVerificationDataPacket& userVerify, const  ::ipcms::IPCResourceDataPacket& ipc) {
    // Your implementation goes here
    printf("addResource\n");
  }

   ::ipcms::ReturnType::type addResourceRecord(const  ::ipcms::UserVerificationDataPacket& userVerify, const  ::ipcms::RecordResource& record, const std::string& file) {
    // Your implementation goes here
    printf("addResourceRecord\n");
  }

   ::ipcms::ReturnType::type deleteResource(const  ::ipcms::UserVerificationDataPacket& userVerify, const int64_t handle) {
    // Your implementation goes here
    printf("deleteResource\n");
  }

   ::ipcms::ReturnType::type deleteAllResources(const  ::ipcms::UserVerificationDataPacket& userVerify) {
    // Your implementation goes here
    printf("deleteAllResources\n");
  }

};

int main(int argc, char **argv) {
  int port = 9090;
  shared_ptr<IpcManageServerHandler> handler(new IpcManageServerHandler());
  shared_ptr<TProcessor> processor(new IpcManageServerProcessor(handler));
  shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
  shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

  TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
  server.serve();
  return 0;
}

