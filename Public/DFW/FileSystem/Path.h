#pragma once
#include "DFW/DCore.h"

namespace DogFW::filesystem
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

