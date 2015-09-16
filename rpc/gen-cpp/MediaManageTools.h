#ifndef MediaManageTools_H
#define MediaManageTools_H

#include "MediaManagerStruct_types.h"
#include <map>

using namespace std;
using namespace  ::ipcms;

namespace ipcTools
{
	class MediaManager
	{
	public:
		void initFromLocal();

	protected:
	private:
		CRITICAL_SECTION m_CriticalSectionDevice;

		map<HANDLE/*resource*/, IPCResourceDataPacket *> m_DeviceResource;
	};


}


#endif