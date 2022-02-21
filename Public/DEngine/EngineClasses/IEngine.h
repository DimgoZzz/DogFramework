#pragma once
#include "DFW/DWin.h"

namespace DogFW:: inline engine
{
	class IEngine
	{
	public:
		IEngine();
		virtual ~IEngine() = 0;

		IEngine(IEngine const&) = delete;
		IEngine(IEngine&&) = delete;
		IEngine& operator=(IEngine const&) = delete;
		IEngine& operator=(IEngine&&) = delete;

		static IEngine* get();
	
	public:
		HINSTANCE getHInst();
	
	protected:
		static IEngine* engptr;
		HINSTANCE hInst;
	};
}

