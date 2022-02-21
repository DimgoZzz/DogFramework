#pragma once
#include "DogFW/DogWin.h"
#include "DogFW/DogVector.h"

namespace DogFW:: inline engine
{
	class IWindow
	{
	public:
		class WindowClass
		{
		public:
			WindowClass(WString className,
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
						HICON       hIconSm);
			~WindowClass();
		public:
			WString getName();
		private:
			void rgstr();
		private:
			Bool isRegistered_ {false};

			const WString className_;

			WNDCLASSEX wcex_{};
		};
	protected:
		IWindow();
		virtual ~IWindow();// = 0;

		IWindow(IWindow const&)				= delete;
		IWindow(IWindow&&)					= delete;
		IWindow& operator=(IWindow const&)	= delete;
		IWindow& operator=(IWindow&&)		= delete;

	public:
		WString getTitle() const;
		void setTitle(WString inV);

		Vector2IP getSize();
		void setSize(Vector2IP inV);

		HWND& getHandle();

		protected:
		static WindowClass winClass_;
		Vector2IP size_{ 480,480 };
		WString title_{ L"Unnamed Window" };
		HWND handle_{ NULL };

	};
}

