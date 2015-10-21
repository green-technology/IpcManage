#ifndef MediaManageTools_H
#define MediaManageTools_H

#include "MediaManagerStruct_types.h"
#include <map>
#include <vector>

using namespace std;
using namespace  ::ipcms;

namespace ipcTools
{
	class MediaManager
	{
	public:
		static MediaManager* Instance()
		{
			static MediaManager* instance = NULL;
			if(!instance)
			{
				instance = new MediaManager();
				instance->initFromLocal();
			}
			assert(instance);

			return instance;
		}

		const map<HANDLE/*resource*/, IPCResourceDataPacket *>& getAllResource() const {return m_DeviceResource;}
		const IPCResourceDataPacket* getResource(HANDLE hRes) const;		
		BOOL addDeviceResource(const IPCResourceDataPacket*);
		BOOL deleteDeviceResource(const HANDLE handle);
		BOOL deleteAllDeviceResource();
	protected:
	private:
		MediaManager() {}
		void initFromLocal();

		CRITICAL_SECTION m_CriticalSectionDevice;

		map<HANDLE/*resource*/, IPCResourceDataPacket *> m_DeviceResource;
	};


}


#endif