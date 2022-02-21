#pragma once
#include "DogFW/Text/Char/DogChar.h"
#include <string>

namespace DogFW::inline basictypes
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

