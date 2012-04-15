
#ifndef DATA__DataManager_H
#define DATA__DataManager_H

#include "ACore.h"
#include "DataTypes.h"

namespace Data {

//TODO: Currently DataManager gets passed around as a ptr - change this so that DataManager is a auto reference counted ptr
//      and objects don't need to worry about the lifecycle of DataManager
class ACORE_DLL_EXPORT DataManager {

	public:

		DataManager();
		~DataManager();

	//Direct Memory Access
		static void * const getMemory(const I4  &numBytes);
		static void * const getMemory(const I4u &numBytes);
		static void * const getMemory(const I8u &numBytes);
		static void release(const void * const dataPtr);

	//Memory Pool
		void * const getMemoryFromPool(const I4  &numBytes);
		void * const getMemoryFromPool(const I4u &numBytes);
		void * const getMemoryFromPool(const I8u &numBytes);
		bool releaseFromPool(const void * const dataPtr);
		bool releaseFromPool(const void * const dataPtr,const I4  &numBytes);
		bool releaseFromPool(const void * const dataPtr,const I4u &numBytes);
		bool releaseFromPool(const void * const dataPtr,const I8u &numBytes);
		
		//TODO: Add a method to reduce Pool size

	private:

		class DataManager_d;
		DataManager_d * _this;

};

}

#endif
