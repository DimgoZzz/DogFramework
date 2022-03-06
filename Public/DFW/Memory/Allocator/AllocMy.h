#pragma once
#include "DFW/DBasicTypes.h"

namespace DogFW::memory::stringalloc
{
	template<class T>
	class MemoryChunk
	{
	public:
		T* begin_;
		T* end_;
	};

	template<class T, UInt32 ChCnt>
	class IAllocator
	{
	public:
		MemoryChunk* freeChunkListHead;
		MemoryChunk* freeChunkListTail;
		MemoryChunk* busyChunkListHead;
		MemoryChunk* busyChunkListTail;
	};

	//template<class Type>
	//class IAllocator
	//{

	//public:
	//	UInt32 chunkSize_;
	//	UInt32 chunkCount_;
	//	UInt32 freeChunks_;
	//};

	//template<class Type, UInt32 ChSz>
	//class AllocatorUnit : IAllocator
	//{
	//public:
	//	AllocatorUnit* getActual();
	//};

	//template<class Type>
	//Type* getMem(IAllocator<Type>*& allocRef, IAllocator<Type>*& allocRefOld, UInt32 count)
	//{
	//	if (allocRef->chunksize_ != count)
	//	{
	//		allocRefOld = allocRef;
	//		allocRef = AllocatorUnit<Type, count>::getActual();
	//	}

	//	if (allocRef->freeChunks == 0)
	//	{

	//	}
	//	
	//	return allocRef->allocNewChunk();
	//}

	//template<class T, UInt32 N>
	//class AllocMy
	//{
	//private:
	//	struct ChunkHead
	//	{
	//		UInt32 size {0};
	//		T* begin{ nullptr };
	//		ChunkHead* next {nullptr};
	//	};

	//private:
	//	AllocMy();
	//	~AllocMy();
	//public:
	//	static AllocMy* getMem(AllocMy<T>*& ref, size_t count)
	//	{
	//		////////////////
	//		//Init Pointers
	//		if (actualBuffer_ nullptr)
	//		{
	//			//To do - add allocator
	//			actualBuffer_ = new AllocMy();
	//		}
	//		if (ref == nullptr)
	//		{
	//			ref = actualBuffer_;
	//		}
	//		////////////////


	//		
	//	}






	//	static void freeMem(AllocMy<T>*& ptrRef, size_t size);




	//private:
	//	static AllocMy* actualBuffer_ {nullptr};
	//	Bool isActual{ false };

	//	UInt32 capacity_ {N};
	//	UInt32 used_{ 0 };

	//	ChunkHead* begin_	{nullptr};
	//	ChunkHead* end_		{nullptr};

	//	
	//};
}