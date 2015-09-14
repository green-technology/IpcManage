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
			if (stulogin.ErrorNum != TRUE)
			{
				std::cout <<"LOGIN:" << name<<" return: " << stulogin.ErrorNum << endl;
				goto finish;
			} 
			std::cout <<"SessionId:" << stulogin.SessionID <<" userid: " << stulogin.UserID << endl;

			std::vector<ResourceInfoReturnStruct> resList;
			UserVerificationDataPacket data;
			data.UserID = stulogin.UserID;
			data.SessionID = stulogin.SessionID;
			ipcClient.GetResInfoList(resList, data, ResourceType::ResourceTypeIPC);
			
			std::cout<< resList.size()<<endl;
			if (resList.size() == 0)
			{
				goto finish;
			}

			RequestPTZControlReturnStruct ptz;
			RequestPTZControlDataPacket rqPTZ;
			rqPTZ.hResource = resList[0].hResource;
			ipcClient.RequestPTZControl(ptz, data, rqPTZ);
			std::cout<<ptz.result<< endl;

			PTZControlDataPacket cmd;
			cmd.hPTZ = ptz.hPTZ;
			cmd.command = PTZCommand::PTZ_ZOOM_ADD;
			cmd.param1 = 0;
			cmd.param2 = 0;
			cmd.param3 = 0;
			cmd.dwStop = false;
			PTZControlReturnStruct rtn_cmd;
			ipcClient.PTZControl(rtn_cmd, data, cmd);

			std::cout<<rtn_cmd.result<<"press to continue."<< endl;
			char e;
			std::cin>>e;

			cmd.command = PTZCommand::PTZ_ZOOM_DEC;
			cmd.param1 = 0;
			cmd.param2 = 0;
			cmd.param3 = 0;
			cmd.dwStop = true;
			PTZControlReturnStruct rtn_cmd1;
			ipcClient.PTZControl(rtn_cmd1, data, cmd);
			std::cout<<rtn_cmd1.result<< endl;
		} catch (...) {
			std::cout << "InvalidOperation: " << std::endl;
			// or using generated operator<<: cout << io << endl;
		}

		transport->close();
	} catch (TException& tx) {
		std::cout << "ERROR: " << tx.what() << std::endl;
	}

finish:
	std::cout<<"client login out"<< endl;
	char e;
	std::cin>>e;
}