#pragma once
#include "DFW/DString.h"

namespace DogFW::file
{
	class Path
	{
	public:
		Path(WString const& path) { path_ = path; };
	public:
		WString toWString() { return path_; };
	private:
		WString path_;
	};
}

