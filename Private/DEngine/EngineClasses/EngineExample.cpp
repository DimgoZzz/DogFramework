#include "DEngine/EngineClasses/EngineExample.h"

namespace DogFW::engine
{
#pragma region Constructors
	EngineExample::EngineExample()
	{

	}
	EngineExample::~EngineExample()
	{

	}

#pragma endregion Constructors


#pragma region Public Api
	EngineExample* EngineExample::get()
	{
		return static_cast<EngineExample*>(engptr_);
	}

	SystemFile* EngineExample::getSystemFile() { return static_cast<SystemFile*>(sysFile_.get());}
	SystemLog* EngineExample::getSystemLog() { return static_cast<SystemLog*>(sysLog_.get()); }
	SystemApp* EngineExample::getSystemApp() { return static_cast<SystemApp*>(sysApp_.get()); }
	SystemWindow* EngineExample::getSystemWindow() { return static_cast<SystemWindow*>(sysWindow_.get()); };

#pragma endregion Public Api


#pragma region SystemInit
	void EngineExample::initSystemFile()
	{
		sysFile_ = new SystemFile;
	}
	void EngineExample::initSystemLog()
	{
		
	}
	void EngineExample::initSystemApp()
	{

	}
	void EngineExample::initSystemWindow()
	{

	}
#pragma endregion SystemInit

}