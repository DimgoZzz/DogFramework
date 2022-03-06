#pragma once
#include "DFW/DBase.h"
#include "DFW/DFileSystem.h"
#include "DFW/DPointer.h"
#include "DFW/DWin.h"

#include "DEngine/DSettings.h"
#include "DEngine/DSystems.h"


namespace DogFW::engine
{
	class IEngine : private patterns::NonCopyable ,
					private patterns::NonMoveable
	{
////////////////////////////////////////
#pragma region Class_bases
////////////////////////////////////////

	public:
		IEngine();
		virtual ~IEngine() = 0;

		void init();

	//Static acces
	public:
		static IEngine * get();
	protected:
		static IEngine* engptr_;

////////////////////////////////////////
#pragma endregion Class_bases
////////////////////////////////////////

////////////////////////////////////////
#pragma region Settings
////////////////////////////////////////

	//Project Settings
	public:
		ProjectSettings* getProjectSettings();
	protected:
		void initSettings();
		UniquePtr<ProjectSettings> projSettings_;
////////////////////////////////////////
#pragma endregion Settings
////////////////////////////////////////

////////////////////////////////////////
#pragma region Systems
////////////////////////////////////////
	//Systems Access
	public:
		FileSystem*		getSystemFile();
		LogSystem*		getSystemLog();
		AppSystem*		getSystemApp();
		WindowSystem*	getSystemWindow();

	//Systems init
	private:
		void initSystems();
	protected:
		virtual void initSystemFile() = 0;
		virtual void initSystemLog() = 0;
		virtual void initSystemApp() = 0;
		virtual void initSystemWindow() = 0;
		
	protected:
		UniquePtr<FileSystem> fileSys_;
		UniquePtr<LogSystem> logSys_;
		UniquePtr<AppSystem> appSys_;
		UniquePtr<WindowSystem> windowSys_;
////////////////////////////////////////
#pragma endregion Systems
////////////////////////////////////////

////////////////////////////////////////
#pragma region Public_api
////////////////////////////////////////

	//Public Api
	public:
		HINSTANCE getHInst();
	
	protected:
		HINSTANCE hInst_;

////////////////////////////////////////
#pragma endregion Public_api
////////////////////////////////////////
	};
}

