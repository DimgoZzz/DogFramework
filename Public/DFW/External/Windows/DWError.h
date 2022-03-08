#pragma once
#include "DFW/DBase.h"
#include "DFW/External/Windows/DogWindows.h"

namespace DogFW::win::error
{
	WString getErrorDesc(DWORD errorMessageID);
}

