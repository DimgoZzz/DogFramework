#pragma once
#include "DFW/DBasicTypes.h"
#include "DFW/DString.h"
#include "DFW/External/Windows/DogWindows.h"

#pragma region Macros

#define D_CRITERR(x) DogFW::win::dmsgbox::showCritError(DogFW::string::format(L"Error: %s \n%s",x,D_FILELINEW_))
#define D_WARNING(x) DogFW::win::dmsgbox::showWarning(DogFW::string::format(L"Error: %s \n%s",x,D_FILELINEW_))

#pragma endregion Macros

namespace DogFW:: win :: msgbox 
{
	void info(WString wstr);
	void infoHResult(HRESULT hr, WString wstr);
	void warning(WString wstr);
	void warningHResult(HRESULT hr, WString wstr);
	void infoLastError();

	void critError(WString str);

	//void critError(HRESULT hr, WString str);
}
