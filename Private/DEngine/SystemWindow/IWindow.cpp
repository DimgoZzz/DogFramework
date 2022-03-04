#include "DEngine/Systems/Window/IWindow.h"

namespace DogFW :: inline engine
{
	IWindow::WindowClass::WindowClass(	WString className,
										UINT        cbSize,
										UINT        style,
										WNDPROC     lpfnWndProc,
										int         cbClsExtra,
										int         cbWndExtra,
										HINSTANCE   hInstance,
										HICON       hIcon,
										HCURSOR     hCursor,
										HBRUSH      hbrBackground,
										LPCWSTR     lpszMenuName,
										LPCWSTR     lpszClassName,
										HICON       hIconSm)
	{
	}
	IWindow::WindowClass::~WindowClass()
	{
		//UnregisterClassW(className_.c_str(),engine::);
	}
	WString IWindow::WindowClass::getName()
	{
		return className_;
	}
	void IWindow::WindowClass::rgstr()
	{
		//RegisterClassExW();
	}



	IWindow::IWindow() {};
	IWindow::~IWindow() {};
}
