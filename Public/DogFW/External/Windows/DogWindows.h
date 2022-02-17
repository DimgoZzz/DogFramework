#pragma once
#define WIN32_LEAN_AND_MEAN // Exclude rarely-used stuff from Windows headers
#include <Windows.h>

#include "DogFW/DogBasicTypes.h"

#include "DogFW/Resources/DogResources.h"

#pragma region Macros

//Path of current file
#define D_FILEW_ (std::wcsrchr(__FILEW__, L'\\') ? std::wcsrchr(__FILEW__, L'\\') + 1 : __FILEW__)

//Patn and number of current line
#define D_FILELINEW_ ((DogFW::basictypes::string::format(L"%s Line %i",D_FILEW_,__LINE__)).c_str())

//
#define D_CRITERR(x) DogFW::win::critError(DogFW::basictypes::string::format(L"Error: %s \n%s",x,D_FILELINEW_))
//#define D_DEFCRITERRCODE -1
#pragma endregion Macros

namespace DogFW::win
{
	WString GetErrorDesc(DWORD errorMessageID);

	void msgWindow(String str);
	void msgWindow(WString wstr);
	void msgWindow(HRESULT hr, String str);
	void msgWindow(HRESULT hr, WString wstr);

	void critError(String str);
	void critError(WString str);
	//void critError(HRESULT hr, String str);
	//void critError(HRESULT hr, WString str);
}
