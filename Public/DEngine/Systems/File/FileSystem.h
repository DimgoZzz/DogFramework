#pragma once
#include "DFW/DFileSystem.h"

namespace DogFW::filesystem
{
	class FileSystem
	{
	public:
		FileSystem() {};
		~FileSystem() {};

		void init() {};
	public:
		Directory getAppDir();
		Directory getLogDir();
		Directory getCurrentDir();

		Directory createDir(Path);
		UInt8  deleteDir(Path);

		//auto listObjects();

	private:

	};
}

