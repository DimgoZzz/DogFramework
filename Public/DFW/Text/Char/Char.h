#pragma once

namespace DogFW :: inline basictypes
{
	namespace chars
	{
		using Char = char;
		using WChar = wchar_t;

		const Char* srchLast(const Char* cArr, Char value);
		const WChar* srchLast(const WChar* wArr, WChar value);
	}
	using chars::Char;
	using chars::WChar;
}

