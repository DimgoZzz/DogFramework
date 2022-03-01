#pragma once
#include "DFW/DString.h"

namespace DogFW::systemfile
{
	class Path
	{
	public:
		Path(WString const& path);
	public:
		WString toWString();
	private:
		WString path_;
	};
}

