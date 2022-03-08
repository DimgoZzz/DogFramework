#pragma once
#include "DFW/DBase.h"
#include "DFW/DWin.h"
#include "DFW/LibResources/Icons/IconDFWMain.h"

namespace DogFW::libres
{
	enum class EnLibIcons : UInt16
	{
		IconDFWMain = 0
	};

	HICON getIcon(EnLibIcons icon,Int32 iconSize = 0);
}