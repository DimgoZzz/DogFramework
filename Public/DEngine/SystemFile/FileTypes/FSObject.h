#pragma once
#include "DFW/DBasicTypes.h"

#include "DEngine/SystemFile/Path.h"

namespace DogFW :: systemfile
{
	class FSObject
	{
	public:
		enum class ObjType : UInt8
		{
			None = 0,
			Directory = 1,
			File = 2
		};

	public:
		FSObject(const Path& path);

		Path getPath();
		WString getName();
		ObjType getType();

		
	private:
		Path path_;
	};
}

