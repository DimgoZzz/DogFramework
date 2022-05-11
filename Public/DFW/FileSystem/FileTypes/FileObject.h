#pragma once
#include "DFW/DCore.h"

#include "DFW/FileSystem/Path.h"

namespace DogFW :: filesystem
{
	class FileObject
	{
	public:
		enum class ObjType : UInt8
		{
			None = 0,
			Directory = 1,
			File = 2
		};

	public:
		FileObject(const Path& path);

		Path getPath();
		WString getName();
		ObjType getType();

		
	private:
		Path path_;
	};
}

