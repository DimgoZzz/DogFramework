#pragma once
#include "DFW/DBasicTypes.h"
#include "DFW/DString.h"
#include "DFW/External/Windows/DogWindows.h"

#pragma region Macros

#define D_CRITERR(x) DogFW::win::msgbox::showCritError(DogFW::string::format(L"Error: %s \n%s",x,D_FILELINEW_))
#define D_WARNING(x) DogFW::win::msgbox::showWarning(DogFW::string::format(L"Error: %s \n%s",x,D_FILELINEW_))

#pragma endregion Macros

namespace DogFW::win::msgbox 
{
	void info(WString wstr = L"");
	void infoHResult(HRESULT hr, WString wstr);
	void warning(WString wstr = L"");
	void warningHResult(HRESULT hr, WString wstr);
	void infoLastError();

	void critError(WString str = L"");

	//void critError(HRESULT hr, WString str);
}
