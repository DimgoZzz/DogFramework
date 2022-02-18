#pragma once
//Windows.h shortcut for DogFW, DogFW::win located at DogFW/DogWin.h

// target Windows 10 or later
#define _WIN32_WINNT 0x0A00
#include <sdkddkver.h>

// Exclude rarely-used stuff from Windows headers
#define WIN32_LEAN_AND_MEAN 

#include <Windows.h>
