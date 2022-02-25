#pragma once
#include "DEngine/EngineClasses/IEngine.h"

namespace DogFW:: inline engine
{
	class EngineSimple:public IEngine
	{
	public:
		EngineSimple();
		~EngineSimple();
	 
		static EngineSimple* get();

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

