#pragma once
#include "DEngine/SystemFile/FileTypes.h"

namespace DogFW::systemfile
{
	class SystemFile
	{
	public:
		Directory getDirExe();
		Directory getDirLog();
		Directory getDirCurrent();

		Directory getUpDir();

		Directory createDir();
		Directory deleteDir();

		auto listObjects();

	private:

	};
}

