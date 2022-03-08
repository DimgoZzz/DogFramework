#pragma once
#include "DFW/DBase.h"
#include <vector>

namespace DogFW
{
	//Thread unSafe, one file logger
	class LoggerSimple
	{
	public:
		LoggerSimple ();
		LoggerSimple (WString name,WString path);
		~LoggerSimple();
	public:
		//Log to local String, call saveToFile for saving 
		void log(const WChar* fmt, ...);
		//Log and Save
		void logS(const WChar* fmt, ...);
		void setNewPath(const WString path);
		void saveToFile();
	private:
		WString filePath_ = L"Log/";
		WString fileName_ = L"SimpleLog.log";
		std::vector<WString> messages_;
	};
}