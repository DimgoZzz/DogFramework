#include "DEngine/EngineClasses/EngineSimple.h"

namespace DogFW::engine
{
#pragma region Constructors
	EngineSimple::EngineSimple()
	{

	}
	EngineSimple::~EngineSimple()
	{

	}

#pragma endregion Constructors


#pragma region Public Api
	EngineSimple* EngineSimple::get()
	{
		return static_cast<EngineSimple*>(engptr_);
	}

	SystemFile* EngineSimple::getSystemFile() { return sysFile_; }
	SystemLog* EngineSimple::getSystemLog() { return sysLog_; }
	SystemApp* EngineSimple::getSystemApp() { return sysApp_; }
	SystemWindow* EngineSimple::getSystemWindow() { return sysWindow_; };

#pragma endregion Public Api


#pragma region SystemInit
	void EngineSimple::initSystemFile()
	{
		sysFile_ = new SystemFile;
	}
	void EngineSimple::initSystemLog()
	{
		
	}
	void EngineSimple::initSystemApp()
	{

	}
	void EngineSimple::initSystemWindow()
	{

	}
#pragma endregion SystemInit

}