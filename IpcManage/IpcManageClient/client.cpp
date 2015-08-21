#include <iostream>

#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TTransportUtils.h>

#include "IpcManageServer.h"

#pragma comment(lib,"libthrift.lib")

using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;

using namespace ipcms;
using namespace std;

int main() {
	boost::shared_ptr<TTransport> socket(new TSocket("localhost", 9090));
	boost::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
	boost::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));
	IpcManageServerClient ipcClient(protocol);

	try {
		transport->open();

		try {
			UserLoginReturnStruct stulogin;
			std::string name = "test";
			ipcClient.UserLogin(stulogin,name);
			std::cout << "Whoa? We can divide by zero!" << std::endl;
			std::cout <<"SessionId:" << stulogin.SessionID <<" userid: " << stulogin.UserID << endl;

			std::cout <<"hahahha"<< std::endl;
		} catch (...) {
			std::cout << "InvalidOperation: " << std::endl;
			// or using generated operator<<: cout << io << endl;
		}

		transport->close();
	} catch (TException& tx) {
		std::cout << "ERROR: " << tx.what() << std::endl;
	}
}