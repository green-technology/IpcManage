#include "log.h"
#include "glog\logging.h"

void InitLogging(const char* argv0)
{
	google::InitGoogleLogging(argv0);
}

//google::LogMessage(__FILE__, __LINE__, google::GLOG_INFO, counter, &google::LogMessage::SendToLog);