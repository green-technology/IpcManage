#include <Windows.h>
#include <string>
#include <assert.h>
#include "openssl/md4.h"
#include "openssl/md5.h"

#pragma comment(lib, "libeay32MT.lib")
#pragma comment(lib, "ssleay32MT.lib")

using namespace std;

string IntToString(int value);
wstring IntToWString(int value);

std::string wstring2string(const std::wstring& ws);
wstring string2wstring(string str)  ;

std::wstring GetCurrWorkingDir();

//wstring GetCurrentTimeString();

string GetCurrentTimeString();

wchar_t* chr2wch(const char *buffer);
wstring chr2wstring(const char *buffer);

char* wch2chr(LPCTSTR lpString);

string getMD5(string instr);
string getMD4(string instr);
string getMD4(unsigned char* instr, unsigned length);

bool isEmail(std::string strEmail);

string getSalt();

// for debug
void __cdecl odprintf(const char *format, ...);
string utf2string(const char* buffer);
wstring utf2wstring(const char *buffer);


string gbk2utf(const string &strSource);
string utf2gbk(const string &strSource);

void debugOut(string info);

//从字节转为kb/mb/gb
wstring getFriendlyRate(UINT64 inNum );
std::wstring getFriendlyTraffic(UINT64 inNum);

// 间隔时间转换 输入为ms 转为可以天时分秒
std::wstring getFriendlyIntervalTime(UINT64 inNum );
