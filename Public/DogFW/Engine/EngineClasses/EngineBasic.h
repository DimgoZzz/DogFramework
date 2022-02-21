#pragma once
#include "DogFW/Engine/EngineClasses/IEngine.h"

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

