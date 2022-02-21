#include "DFW/External/Windows/DWMessageBox.h"

#include <comdef.h>

namespace DogFW:: win :: msgbox
{
	void info(WString wstr)
	{
		MessageBoxW(NULL, wstr.c_str(), L"Message Window", MB_OK | MB_ICONINFORMATION);
	}

	void infoHResult(HRESULT hr, WString wstr)
	{
		_com_error error(hr);
		WString i = L"J";
		WString error_message = L"Error:" + wstr + L"\n" + error.ErrorMessage();

		MessageBoxW(NULL, error_message.c_str(), L"DebugTextWindow", MB_OK | MB_ICONINFORMATION);
	}

	void warning(WString wstr)
	{
		MessageBoxW(NULL, wstr.c_str(), L"Message Window", MB_OK | MB_ICONWARNING);
	}

	void warningHResult(HRESULT hr, WString wstr)
	{
		_com_error error(hr);
		WString i = L"J";
		WString error_message = L"Error:" + wstr + L"\n" + error.ErrorMessage();

		MessageBoxW(NULL, error_message.c_str(), L"DebugTextWindow", MB_OK | MB_ICONWARNING);
	}

	void infoLastError()
	{
		_com_error error(GetLastError());
		WString error_message = L"Error:\n" + WString(error.ErrorMessage());

		MessageBoxW(NULL, error_message.c_str(), L"Last Error", MB_OK | MB_ICONINFORMATION);
	}

	void critError(WString wstr)
	{
		MessageBoxW(NULL, wstr.c_str(), L"Critical Error", MB_OK | MB_ICONERROR);
		exit(-1);
		//abort();
	}
}