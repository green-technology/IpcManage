#ifndef LOG_H
#define LOG_H

void InitLogging(const char* argv0);
//LogMessage(const char* file, int line, LogSeverity severity, int ctr)
//#define GLOG(severity) COMPACT_GOOGLE_LOG_ ## severity.stream()

#endif