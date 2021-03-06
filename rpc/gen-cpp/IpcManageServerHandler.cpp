#include "IpcManageServerHandler.h"
#include "IpcManageTools.h"
#include "MediaManageTools.h"
#include "Tools.h"
#include "glog\logging.h"

IpcManageServerHandler::IpcManageServerHandler()
{
	initMediaResource();
}

void IpcManageServerHandler::UserLogin( ::ipcms::UserLoginReturnStruct& _return, const std::string& userName) {
	// Your implementation goes here
	LOG(INFO)<<"UserLogin:"<<userName;

	//用户验证，以用户名作为KEY
	for (map<string, string>::iterator iter = m_userLoginList.begin();iter != m_userLoginList.end();iter++)
	{
		if (iter->second == userName)
		{
			_return.ErrorNum = FALSE;
			return;
		}
	}
	
	//分配资源
	string id;
	if (!getLoginResource(userName, id))
	{
		_return.ErrorNum = FALSE;
	}
	else
	{
		UserLoginInfoDataPacket info;
		info.UserID = id;
		info.SessionID = getMD5(id);

		_return.ErrorNum = TRUE;
		_return.UserID = info.UserID;
		_return.SessionID = info.SessionID;

		//LOG(INFO)<<info.UserID;

	}
}

void IpcManageServerHandler::GetResInfoList(std::vector< ::ipcms::ResourceInfoReturnStruct> & _return, const  ::ipcms::UserVerificationDataPacket& userVerify, const  ::ipcms::ResourceType::type resType) {
	LOG(INFO)<<"GetResInfoList:"<<userVerify.UserID;

	if(!authentication(userVerify))
		return;


	IPCResourceDataPacket * pRpcRes=nullptr;
	switch(resType)
	{
	case ResourceType::ResourceTypeALL:
	case ResourceType::ResourceTypeIPC:
		{
			const map<HANDLE/*resource*/, IPCResourceDataPacket *> resMap = ipcTools::MediaManager::Instance()->getAllResource();
			for (map<HANDLE/*resource*/, IPCResourceDataPacket *>::const_iterator iter = resMap.begin(); iter != resMap.end(); iter++)
			{
				pRpcRes = iter->second;

				ResourceInfoReturnStruct item;
				item.resourceType = ResourceType::ResourceTypeIPC;
				item.hResource = (int64_t)iter->first;
				item.IP = pRpcRes->IP;
				item.deviceName = pRpcRes->deviceName;
				item.hasPLZ = true;
				item.timeStart = 0;
				item.timeEnd = 0;
				item.ID = pRpcRes->ID;
				item.rtspUrl = pRpcRes->rtspUrl;

				_return.push_back(item);
				
			}
		}
		if(resType != ResourceType::ResourceTypeALL)
			break;
	case ResourceType::ResourceTypeReplay:
		{

		}
		break;
	default:
		LOG(INFO)<<"GetResInfoList:"<< "不识别的资源类型"<<resType;
		break;
	}

}

int8_t IpcManageServerHandler::PlayVideo(const  ::ipcms::UserVerificationDataPacket& userVerify, const  ::ipcms::PlayVideoDataPacket& playVideo) {
	// Your implementation goes here
	LOG(INFO)<<"PlayVideo:" <<userVerify.UserID;
	LOG(WARNING)<<"没有实现";
	return 0;
}

void IpcManageServerHandler::RequestPTZControl( ::ipcms::RequestPTZControlReturnStruct&  _return, const  ::ipcms::UserVerificationDataPacket& userVerify, const  ::ipcms::RequestPTZControlDataPacket&  requestPTZ) {
	LOG(INFO)<<"RequestPTZControl:" <<userVerify.UserID;

	if(!authentication(userVerify))
		return;

	HANDLE hRes = (HANDLE)requestPTZ.hResource;
	LONG hPTZ = NULL;
	if (getPTZResource(hRes, hPTZ) == FALSE)
	{
		_return.hPTZ = NULL;
		_return.result = -1;
	}
	else
	{
		map<LONG, string>::iterator iterUser = m_PTZUserList.find(hPTZ);
		if (iterUser != m_PTZUserList.end())
		{
			_return.hPTZ = NULL;
			_return.result = FALSE;
			_return.userName = iterUser->second;
		}
		else
		{
			m_PTZUserList[hPTZ] = userVerify.UserID;

			_return.hPTZ = (int64_t)hPTZ;
			_return.result = TRUE;
		}
	}
}

void IpcManageServerHandler::PTZControl(::ipcms::PTZControlReturnStruct&  _return , const ::ipcms::UserVerificationDataPacket&  userVerify , const ::ipcms::PTZControlDataPacket&  command )
{
	// Your implementation goes here
	LOG(INFO)<<"PTZControl:" <<userVerify.UserID;

	if(!authentication(userVerify))
		return;

	LONG hPTZ = (LONG)command.hPTZ;
	map<LONG, HANDLE>::iterator iter = m_PTZHandler.find(hPTZ);
	if (iter == m_PTZHandler.end())
	{
		_return.result = PTZControlReturnType::PTZControlReturnTypeInvalidHandle;
		return;
	}

	if(ipcTools::ConnectManager::Instance()->PTZControl(command) == TRUE)
		_return.result = PTZControlReturnType::PTZControlReturnTypeSuccess;
	else
		_return.result = PTZControlReturnType::PTZControlReturnTypeError;
}

ReturnType::type IpcManageServerHandler::ReleasePTZControl(const  ::ipcms::UserVerificationDataPacket& userVerify, const int64_t hPTZ)
{
	if(!authentication(userVerify))
		return ReturnType::InvalidUser;

	map<LONG, string>::iterator iterUser = m_PTZUserList.find(hPTZ);
	if (iterUser != m_PTZUserList.end())
	{
		if (iterUser->second == userVerify.UserID)
		{
			ipcTools::ConnectManager::Instance()->closeConnect((LONG)hPTZ);
			return ReturnType::Success;
		}
	}

	return ReturnType::InvalidHandle;
}

bool IpcManageServerHandler::UserLogout(const  ::ipcms::UserVerificationDataPacket& userVerify) {
	// Your implementation goes here
	LOG(INFO)<<"UserLogout:" <<userVerify.UserID;

	if (!authentication(userVerify))
		return false;
	releaseLoginResource(userVerify.UserID);

	return true;
}

ReturnType::type IpcManageServerHandler::addResource(const  ::ipcms::UserVerificationDataPacket& userVerify, const ::ipcms::IPCResourceDataPacket& ipc)
{
	LOG(INFO)<<"addResource:" <<userVerify.UserID;

	if(!authentication(userVerify))
		return ReturnType::InvalidUser;

	if (ipcTools::MediaManager::Instance()->addDeviceResource(&ipc))
		return ReturnType::Success;

	return ReturnType::FailUnspecified;
}

ReturnType::type IpcManageServerHandler::addResourceRecord(const  ::ipcms::UserVerificationDataPacket& userVerify, const ::ipcms::RecordResource& record, const std::string& file)
{
	if(!authentication(userVerify))
		return ReturnType::InvalidUser;

	return ReturnType::FailUnspecified;
}

ReturnType::type IpcManageServerHandler::deleteResource(const  ::ipcms::UserVerificationDataPacket& userVerify, const int64_t handle)
{
	LOG(INFO)<<"deleteResource:" <<userVerify.UserID;

	if(!authentication(userVerify))
		return ReturnType::InvalidUser;

	if (ipcTools::MediaManager::Instance()->deleteDeviceResource((HANDLE)handle))
		return ReturnType::Success;

	return ReturnType::FailUnspecified;
}


ReturnType::type IpcManageServerHandler::deleteAllResources(const  ::ipcms::UserVerificationDataPacket& userVerify) {
	if(!authentication(userVerify))
		return ReturnType::InvalidUser;

	if (ipcTools::MediaManager::Instance()->deleteAllDeviceResource())
		return ReturnType::Success;

	return ReturnType::FailUnspecified;
}

bool IpcManageServerHandler::getLoginResource(const string userName, string& id)
{
	SYSTEMTIME loctime;
	GetLocalTime(&loctime);
	char szTime[128]={0};
	sprintf_s(szTime, "%.4d%.2d%.2d%.2d%.2d%.2d", loctime.wYear, loctime.wMonth, loctime.wDay, loctime.wHour, loctime.wMinute, loctime.wSecond);

	id = userName + szTime;

	m_userLoginList[id] = userName;

	return true;
}

void IpcManageServerHandler::releaseLoginResource(const string id)
{
	map<string, string>::iterator iter = m_userLoginList.find(id);
	if (iter != m_userLoginList.end())
	{
		m_userLoginList.erase(iter);
	}
}

void IpcManageServerHandler::confirmPTZControl(HANDLE hUser, HANDLE hIPC)
{

}

BOOL IpcManageServerHandler::getPTZResource(HANDLE hRes, LONG &hPTZ)
{
	BOOL ret = FALSE;

	const IPCResourceDataPacket* ipc = ipcTools::MediaManager::Instance()->getResource(hRes);
	if (ipc != NULL)
	{
		//通过SDK建立连接
		if(ipcTools::ConnectManager::Instance()->connectDVR(ipc) != FALSE)
		{
			hPTZ = ipc->hPTZ;
			m_PTZHandler[hPTZ] = hRes;
			ret = TRUE;
		}
	}

	return ret;
}

bool IpcManageServerHandler::authentication(const UserVerificationDataPacket &data) const
{
	map<string, string>::const_iterator iter = m_userLoginList.find(data.UserID);
	if (iter != m_userLoginList.end())
	{
		return true;
	}
	LOG(INFO)<<"authentication fail";
	return false;
}

void IpcManageServerHandler::initMediaResource()
{
	
}

