#pragma once
#include "DFW/DBasicTypes.h"
#include <string>

namespace DogFW::stdstring
{
	namespace string
	{
	using String = std::string;
	using WString = std::wstring;

	String toString(const WString& wstr);
	WString toWString(const String& str);
		
	String format(const Char* fmt, ...);
	WString format(const WChar* fmt, ...);
	}
	using string::String;
	using string::WString;
}

