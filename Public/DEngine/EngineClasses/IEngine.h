#pragma once
#include "DFW/DBase.h"
#include "DFW/DWin.h"
#include "DFW/DPointer.h"

#include "DEngine/DSystems.h"


namespace DogFW::engine
{
	class IEngine : private patterns::NonCopyable ,
					private patterns::NonMoveable
	{
#pragma region Class_bases
	public:
		IEngine();
		virtual ~IEngine() = 0;


		void init();
		static IEngine * get();
	protected:
		static IEngine* engptr_;

#pragma endregion Class_bases
	
#pragma region Systems
	//Systems Access
	public:
		SystemFile*		getSystemFile();
		SystemLog*		getSystemLog();
		SystemApp*		getSystemApp();
		SystemWindow*	getSystemWindow();

	//Systems init
	private:
		void initSystems();
	protected:
		virtual void initSystemFile() = 0;
		virtual void initSystemLog() = 0;
		virtual void initSystemApp() = 0;
		virtual void initSystemWindow() = 0;
		
	protected:
		UniquePtr<SystemFile> sysFile_;
		UniquePtr<SystemLog> sysLog_;
		UniquePtr<SystemApp> sysApp_;
		UniquePtr<SystemWindow> sysWindow_;
#pragma endregion Systems

#pragma region Public_api
	//Public Api
	public:
		HINSTANCE getHInst();
	
	protected:
		HINSTANCE hInst_;
#pragma endregion Public_api

	};
}

