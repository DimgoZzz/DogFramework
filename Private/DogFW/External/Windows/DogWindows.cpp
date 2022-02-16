#include "DogFW/External/Windows/DogWindows.h"

#include <comdef.h>

namespace DogFW::win
{
	WString GetErrorDesc(DWORD errorMessageID)
	{
		_com_error error(errorMessageID);
		WString error_message = error.ErrorMessage();
		return error_message;
	}

	void msgWindow(String str)
	{
		MessageBoxA(NULL, str.c_str(), "Message Window", MB_OK | MB_ICONINFORMATION);
	}
	void msgWindow(WString wstr)
	{
		MessageBoxW(NULL, wstr.c_str(), L"Message Window", MB_OK| MB_ICONINFORMATION);
	}

	void msgWindow(HRESULT hr, String str)
	{
		_com_error error(hr);
		String error_message = "Error:" + str + "\n" + string::toString(error.ErrorMessage());
		
		MessageBoxA(NULL, error_message.c_str(), "DebugTextWindow", MB_OK | MB_ICONWARNING);
	}
	void msgWindow(HRESULT hr, WString wstr)
	{
		_com_error error(hr);
		WString i = L"J";
		WString error_message = L"Error:" + wstr + L"\n" + error.ErrorMessage();

		MessageBoxW(NULL, error_message.c_str(), L"DebugTextWindow", MB_OK | MB_ICONWARNING);
	}

	void critError(String str)
	{
		MessageBoxA(NULL, str.c_str(), "Critical Error", MB_OK | MB_ICONERROR);
		exit(-1);
		//abort();
	}
	void critError(WString wstr)
	{
		MessageBoxW(NULL, wstr.c_str(), L"Critical Error", MB_OK | MB_ICONERROR);
		exit(-1);
		//abort();
	}
}