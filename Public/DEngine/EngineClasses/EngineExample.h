#pragma once
#include "DEngine/EngineClasses/IEngine.h"

namespace DogFW::engine
{
	class EngineExample:public IEngine
	{
	public:
		EngineExample();
		~EngineExample();
	 
		static EngineExample* get();

	public:
		SystemFile* getSystemFile();
		SystemLog* getSystemLog();
		SystemApp* getSystemApp();
		SystemWindow* getSystemWindow();

	protected:
		void initSystemFile() override;
		void initSystemLog() override;
		void initSystemApp() override;
		void initSystemWindow() override;

	};
}

