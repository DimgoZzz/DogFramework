#pragma once
#include "DFW/DCore.h"
#include "DFW/External/Windows/DogWindows.h"

namespace DogFW::win::error
{
	WString getErrorDesc(DWORD errorMessageID);
}

