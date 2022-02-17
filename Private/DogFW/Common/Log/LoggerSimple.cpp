#include "DogFW/Common/Log/LoggerSimple.h"
#include "DogFW/External/Windows/DogWindows.h"
#include <stdarg.h>
#include <fstream>

namespace DogFW
{
	LoggerSimple::LoggerSimple()
	{

	}

	LoggerSimple::LoggerSimple(WString path, WString name)
		:filePath_(path), fileName_(name)
	{
	}
	


	LoggerSimple::~LoggerSimple()
	{
		saveToFile();
	}



	void LoggerSimple::log(const WChar* fmt, ...)
	{
		WChar buf[4096];
		va_list args;

		va_start(args, fmt);
		vswprintf_s(buf, fmt, args);
		va_end(args);

		messages_.push_back(WString(buf));
	}



	void LoggerSimple::logs(const WChar* fmt, ...)
	{
		WChar buf[1024];
		va_list args;

		va_start(args, fmt);
		vswprintf_s(buf, fmt, args);
		va_end(args);
		messages_.push_back(WString(buf));
		saveToFile();
	}



	void LoggerSimple::setNewPath(const WString path)
	{
		filePath_ = path;
	}



	void LoggerSimple::saveToFile()
	{
		std::wfstream outfile;
		CreateDirectory(filePath_.c_str(), NULL);
		outfile.open((filePath_+fileName_).c_str(), std::ios_base::app);
		if (!outfile.is_open())
		{
			//D_CRITERR(L"Cant open log file");
		}

		for (int i=0;i<messages_.size();++i)
		{
			outfile << messages_[i] << std::endl;

		}
		outfile.close();
		messages_.clear();
	}
}