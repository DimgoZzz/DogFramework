#include "DogFW/Text/String/DogString.h"
#include "DogFW/DogWin.h"

#include <vector>

namespace DogFW::inline basictypes :: string
{
	//String Convertion
	String toString(const WString& wstr)
	{
		//////////Get Size for buffer//////////
		int buffSizeNeed = WideCharToMultiByte (
							CP_ACP, 0,										// Code Page and flags
							wstr.c_str(), static_cast<int>(wstr.length()),	// In String and Size
							NULL, 0,											// Out String and Size
							NULL, NULL);										// Default Char And Used 

		if (buffSizeNeed <= 0)
		{
			return String();
		}
			
		String result(buffSizeNeed, L'0');
		WideCharToMultiByte(CP_ACP, 0, wstr.c_str(), (int)wstr.length(), result.data(), buffSizeNeed, NULL, NULL);
			
		return result;
	}

	WString toWString(const String& str)
	{
		//////////Get Size for buffer//////////
		int buffSizeNeed = MultiByteToWideChar(
							CP_ACP, 0,									// Code Page and flags
							str.c_str(), static_cast<int>(str.length()),	// In String and Size 
							NULL, 0);									// Out String and Size
																									
		if (buffSizeNeed <= 0)
		{
			return WString();
		}
			
		WString result(buffSizeNeed, L'0');
		MultiByteToWideChar(CP_ACP, 0, str.c_str(), static_cast<int>(str.length()), result.data(), buffSizeNeed);
			
		return result;
	}
		

	//String Format
	String format(const Char* fmt, ...)
	{	
		/////////////////////////////////////
		//https://habr.com/ru/post/318962/
		/////////////////////////////////////
		va_list args;
		va_start(args, fmt);
		std::vector<Char> v(1024);
		while (true)
		{
			va_list args2;
			va_copy(args2, args);
			int res = vsnprintf(v.data(), v.size(), fmt, args2);
			if ((res >= 0) && (res < static_cast<int>(v.size())))
			{
				va_end(args);
				va_end(args2);
				return String(v.data());
			}
			size_t size;
			if (res < 0)
				size = v.size() * 2;
			else
				size = static_cast<size_t>(res) + 1;
			v.clear();
			v.resize(size);
			va_end(args2);
		}
	}

	WString format(const WChar* fmt, ...)
	{
		//Faster???
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//https://docs.microsoft.com/en-us/cpp/c-runtime-library/reference/vsnprintf-s-vsnprintf-s-vsnprintf-s-l-vsnwprintf-s-vsnwprintf-s-l?view=msvc-170
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		int nSize = 0;
		WChar buff[100];
		memset(buff, 0, sizeof(buff));
		va_list args;
		va_start(args, fmt);
		nSize = _vsnwprintf_s(buff, _countof(buff), _TRUNCATE, fmt, args);
		wprintf(L"nSize: %d, buff: %s\n", nSize, buff);
		va_end(args);
		return WString(buff);
	}
}


