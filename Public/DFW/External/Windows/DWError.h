#pragma once
#include "DFW/DBasicTypes.h"
#include "DFW/DString.h"
#include "DFW/External/Windows/DogWindows.h"

namespace DogFW::win::error
{
	WString getErrorDesc(DWORD errorMessageID);
}

