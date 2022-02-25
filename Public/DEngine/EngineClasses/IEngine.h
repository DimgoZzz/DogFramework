#pragma once
#include "DFW/DBase.h"
#include "DFW/DWin.h"
#include "DEngine/DSystems.h"


namespace DogFW:: inline engine
{
	class IEngine : private NonCopyable , private NonMoveable
	{
	public:
		IEngine();
		virtual ~IEngine() = 0;


		void init();
		static IEngine* get();
	//Public Api
	public:
		HINSTANCE getHInst();
	
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
	
	//Members
	protected:
		static IEngine* engptr_;
		HINSTANCE hInst_;

		SystemFile* sysFile_;
		SystemLog* sysLog_;
		SystemApp* sysApp_;
		SystemWindow* sysWindow_;
	};
}

