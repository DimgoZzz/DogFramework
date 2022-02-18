#pragma once
#include "DogFW/External/Windows/DogWindows.h"
#include "DogFW/DogBasicTypes.h"

#pragma region Macros

#define D_CRITERR(x) DogFW::win::critError(DogFW::string::format(L"Error: %s \n%s",x,D_FILELINEW_))

#pragma endregion Macros

namespace DogFW::win
{
	WString GetErrorDesc(DWORD errorMessageID);

	void msgWindow(String str);
	void msgWindow(WString wstr);
	void msgWindow(HRESULT hr, String str);
	void msgWindow(HRESULT hr, WString wstr);

	void msgLastError();

	void critError(String str);
	void critError(WString str);
	//void critError(HRESULT hr, String str);
	//void critError(HRESULT hr, WString str);
}

