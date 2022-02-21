#pragma once
#include "DEngine/EngineClasses/IEngine.h"

namespace DogFW:: inline engine
{
	class Engine:public IEngine
	{
	public:
		Engine() {};
		~Engine() {};
	public: 
		static Engine* get();
	};
}

