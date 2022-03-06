#pragma once

namespace DogFW::memory
{
	//
	//
	//	{MemChunk}[AllocatedMemory]
	//
	template<class T>
	class AllocPoolLocal
	{
	private:
		struct MemChunk
		{
			MemChunk* next;
			MemChunk* prev;
		};
	public:

	private:
		
	};
}