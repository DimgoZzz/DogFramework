#pragma once
#include "DFW/DWin.h"
#include "DFW/LibResources/Icons/IconMainDFW.h"

namespace DogFW::libres
{
	enum class EnLibIcons
	{
		IconMainDFW = 0
	};
	HICON getIcon(EnLibIcons icon,Int32 iconSize = 0);
}