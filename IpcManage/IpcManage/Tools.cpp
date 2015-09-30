#include "Tools.h"
#include <time.h>


std::string IntToString( int value )
{
	char temp[64];
	string str;
	sprintf(temp, "%d", value);
	string s(temp);
	return s;
}


wstring string2wstring( string &str )
{
	wstring result;  
	//获取缓冲区大小，并申请空间，缓冲区大小按字符计算  
	int len = MultiByteToWideChar(CP_ACP, 0, str.c_str(), str.size(), NULL, 0);  
	WCHAR* buffer = new WCHAR[len + 1];  
	//多字节编码转换成宽字节编码  
	MultiByteToWideChar(CP_ACP, 0, str.c_str(), str.size(), buffer, len);  
	buffer[len] = '\0';             //添加字符串结尾  
	//删除缓冲区并返回值  
	result.append(buffer);  
	delete[] buffer;  
	return result;  
}

string wstring2string(const wstring &wstr)
{
	unsigned nLen = ::WideCharToMultiByte(CP_ACP, NULL, wstr.c_str(), -1, NULL, NULL, NULL, NULL);
	char* tmpstr = new char[nLen+1];
	tmpstr[nLen] = L'\0';

	WideCharToMultiByte(CP_UTF8, 0, wstr.c_str(), -1, tmpstr, nLen, NULL, NULL);
	string res(tmpstr);
	delete[] tmpstr;
	return res;
}

std::wstring IntToWString( int value )
{
	wchar_t temp[64];
	wstring str;
	swprintf(temp, L"%d", value);
	wstring s(temp);
	return s;
}

//std::wstring GetCurrWorkingDir()
//{
//	std::wstring strPath;
//	wchar_t _szPath[MAX_PATH + 1]={0};
//	GetModuleFileName(NULL, _szPath, MAX_PATH);
//	(wcsrchr(_szPath, L'\\'))[1] = 0;//删除文件名，只获得路径 字串
//	for (int n=0;_szPath[n];n++)
//	{
//		if (_szPath[n]!=L'\\')
//		{
//			strPath +=_szPath[n] ;
//		}
//		else
//		{
//			strPath += L"\\\\";
//		}
//	}
//	return strPath;
//}



string GetCurrentTimeString()
{
	time_t t = time(0);
	struct tm *p;
	p=gmtime(&t);

	char* chtmp = new char[80];
	strftime(chtmp, 80, "%m%d %X", p);

	string curTime(chtmp);
	delete[] chtmp;
	
	return curTime;
}


//char* wch2chr(LPCTSTR lpString)
//{
//	UINT len = wcslen(lpString)*2;
//	char *buf = (char *)malloc(len);
//	UINT i = wcstombs(buf,lpString,len);
//	return buf;
//}

std::string getMD5(string instr)
{
	unsigned char buf2[16];

	MD5((const unsigned char*)instr.c_str(),instr.length(),buf2);

	char buf[33] = {0};
	for(int i = 0; i < 16; i++ )
	{
		sprintf(buf+2*i,"%02X", buf2[i]);
	}

	string outstr;
	outstr.assign(buf);
	return outstr;
}

std::string getMD4(unsigned char* buffer, unsigned length)
{
	unsigned char buf2[16];

	MD4(buffer,length,buf2);

	char buf[33] = {0};
	for(int i = 0; i < 16; i++ )
	{
		sprintf(buf+2*i,"%02X", buf2[i]);
	}
	return string(buf);
}
std::string getMD4(string instr)
{
	return getMD4((unsigned char*)instr.c_str(), instr.length());
}

bool isEmail(std::string strEmail)
{
	char *p;
	p=strstr((char*)strEmail.c_str(),"@");
	if(!p){
		return false;
	}
	if (!(p-strEmail.c_str())){
		return false;
	}
	if(!(strstr(p,".")-p))
	{
		return false;
	}
	p=strstr(p,".");
	if(*(p+1)=='\0')
	{
		return false;
	}
	return true;
}


//////////////////////////////////////////////////////////////////////////
std::string getSalt()
{
	LARGE_INTEGER fc;
	if (!QueryPerformanceCounter(&fc))
	{
		assert(FALSE);
	}	
	LONGLONG i64_t = fc.QuadPart;  //计时器的频率

	char* strtime= new char[20];
	sprintf(strtime,"%llu",i64_t);
	return (string)strtime;
}

void __cdecl odprintf(const char *format, ...)
{
	char buf[4096], *p = buf;
	va_list args;
	int n;

	va_start(args, format);
	n = _vsnprintf_s(p, sizeof buf, sizeof buf - 3, format, args); // buf-3 is room for CR/LF/NUL
	va_end(args);

	p += (n < 0) ? sizeof buf - 3 : n;

	while ( p > buf  &&  isspace(p[-1]) )
		*--p = '\0';

	*p++ = '\r';
	*p++ = '\n';
	*p   = '\0';

	OutputDebugStringA(buf);
	//OutputDebugString(chr2wch(buf));
}

wchar_t* chr2wch(const char *buffer)
{
	size_t len = strlen(buffer);
	size_t wlen = MultiByteToWideChar(CP_ACP, 0, (const char*)buffer, int(len), NULL, 0);
	wchar_t *wBuf = new wchar_t[wlen + 1];
	MultiByteToWideChar(CP_ACP, 0, (const char*)buffer, int(len), wBuf, int(wlen));
	wBuf[wlen] = 0;
	return wBuf;
}

wstring chr2wstring(const char *buffer)
{
	size_t len = strlen(buffer);
	size_t wlen = MultiByteToWideChar(CP_ACP, 0, (const char*)buffer, int(len), NULL, 0);
	wchar_t *wBuf = new wchar_t[wlen + 1];
	MultiByteToWideChar(CP_ACP, 0, (const char*)buffer, int(len), wBuf, int(wlen));
	wBuf[wlen] = 0;
	wstring result(wBuf);
	//result.append(wBuf);
	delete[] wBuf;
	return result;
}

wstring utf2wstring(const char *buffer)
{
	size_t len = strlen(buffer);
	size_t wlen = MultiByteToWideChar(CP_UTF8, 0, (const char*)buffer, int(len), NULL, 0);
	wchar_t *wBuf = new wchar_t[wlen + 1];

	MultiByteToWideChar(CP_UTF8, 0, (const char*)buffer, int(len), wBuf, int(wlen));
	wBuf[wlen] = 0;

	wstring result(wBuf);
	delete [] wBuf;
	return result;
}

string utf2string(const char* buffer)
{
	size_t len = strlen(buffer);
	size_t wlen = MultiByteToWideChar(CP_UTF8, 0, (const char*)buffer, int(len), NULL, 0);
	wchar_t *wBuf = new wchar_t[wlen + 1];

	MultiByteToWideChar(CP_UTF8, 0, (const char*)buffer, int(len), wBuf, int(wlen));
	wBuf[wlen] = 0;

	UINT ulen = wcslen(wBuf)*2;
	char *buf = (char *)malloc(ulen);
	UINT i = wcstombs(buf,wBuf,ulen);
	string result = buf;
	delete []wBuf;
	delete []buf;

	return result;
}

std::string utf2gbk(const string &str) 
{
	unsigned long nLen = ::MultiByteToWideChar(CP_UTF8, NULL, str.c_str(), -1, NULL, NULL);
	wchar_t* tmpstr = new wchar_t[nLen+1];
	tmpstr[nLen] = L'\0';

	MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, tmpstr, nLen);


	nLen = ::WideCharToMultiByte(CP_ACP, NULL, tmpstr, -1, NULL, NULL, NULL, NULL);
	char* tmpstr2 = new char[nLen+1];
	tmpstr2[nLen] = L'\0';

	WideCharToMultiByte(CP_ACP, 0, tmpstr, -1, tmpstr2, nLen, NULL, NULL);

	string res(tmpstr2);
	delete[] tmpstr2;
	delete[] tmpstr;
	return res;
}

std::string gbk2utf(const string &strSource)
{
	unsigned long nLen = ::MultiByteToWideChar(CP_ACP, NULL, strSource.c_str(), -1, NULL, NULL);
	wchar_t* tmpstr = new wchar_t[nLen+1];
	tmpstr[nLen] = L'\0';

	MultiByteToWideChar(CP_ACP, 0, strSource.c_str(), -1, tmpstr, nLen);


	nLen = ::WideCharToMultiByte(CP_UTF8, NULL, tmpstr, -1, NULL, NULL, NULL, NULL);
	char* tmpstr2 = new char[nLen+1];
	tmpstr2[nLen] = L'\0';

	WideCharToMultiByte(CP_UTF8, 0, tmpstr, -1, tmpstr2, nLen, NULL, NULL);

	string res(tmpstr2);
	delete[] tmpstr2;
	delete[] tmpstr;
	return res;
}

void debugOut(string info)
{
#if _DEBUG
	printf(info.c_str());
	printf("\n");
#endif
}

#define INTERVALSECONDS 3.0
std::wstring getFriendlyRate(UINT64 inNum)
{
	int iStep = 0;
	double dOut = (double)inNum/INTERVALSECONDS;

	while(dOut >= 1024)
	{
		dOut /=(double)1024;
		++iStep;
	}

	wstring sUnit;
	if (iStep == 0)
	{
		sUnit = L"B/s";
	}
	else if (iStep == 1)
	{
		sUnit = L"K/s";
	}
	else if ( iStep == 2)
	{
		sUnit = L"M/s";
	}
	else if ( iStep == 3)
	{
		sUnit = L"G/s";
	}
	else if (iStep == 4)
	{
		sUnit = L"T/s";
	}
	else
	{
		sUnit = L"P/s";
	}

	wchar_t* tmpstr = new wchar_t[50];
	swprintf(tmpstr,50,L"%0.2f%s",dOut,sUnit.c_str());

	// cx = swprintf ( buffer, 100, L"The half of %d is %d", 80, 80/2 );
	wstring sRet(tmpstr);

	delete[] tmpstr;
	return sRet;
}

std::wstring getFriendlyTraffic(UINT64 inNum)
{
	int iStep = 0;
	double dOut = (double)inNum;

	while(dOut >= 1024)
	{
		dOut /=(double)1024;
		++iStep;
	}

	wstring sUnit;
	if (iStep == 0)
	{
		sUnit = L"B";
	}
	else if (iStep == 1)
	{
		sUnit = L"K";
	}
	else if ( iStep == 2)
	{
		sUnit = L"M";
	}
	else if ( iStep == 3)
	{
		sUnit = L"G";
	}
	else if (iStep == 4)
	{
		sUnit = L"T";
	}
	else
	{
		sUnit = L"P";
	}

	wchar_t* tmpstr = new wchar_t[50];
	swprintf(tmpstr,50,L"%0.2f%s",dOut,sUnit.c_str());

	// cx = swprintf ( buffer, 100, L"The half of %d is %d", 80, 80/2 );
	wstring sRet(tmpstr);

	delete[] tmpstr;
	return sRet;
}


std::wstring getFriendlyIntervalTime(UINT64 inNum )
{
	inNum /=1000;			//转为s
	int iDays = 0;
	int iHours = 0;
	int iMinutes = 0;
	int iSeconds = 0;

	wchar_t* tmpstr = new wchar_t[80];

	if (inNum >= 60)
	{
		iSeconds = inNum%60;
		iMinutes = 	inNum/60;	

		if (iMinutes >=60 )
		{
			iHours = iMinutes/60;
			iMinutes = iMinutes%60;

			if (iHours >= 24)
			{
				iDays = iHours/24;
				iHours = iHours%24;

				swprintf(tmpstr,80,L"%d天%d时%d分%d秒",iDays,iHours,iMinutes,iSeconds);
			}
			else
			{
				swprintf(tmpstr,80,L"%d时%d分%d秒",iHours,iMinutes,iSeconds);
			}
		}
		else
		{
			swprintf(tmpstr,80,L"%d分%d秒",iMinutes,iSeconds);
		}
	}
	else
	{
		iSeconds = inNum;
		swprintf(tmpstr,80,L"%d秒",iSeconds);
	}


	// cx = swprintf ( buffer, 100, L"The half of %d is %d", 80, 80/2 );
	wstring sRet(tmpstr);

	delete[] tmpstr;
	return sRet;
}