//Environment Macros
#pragma once
#include "DogFW/DogBasicTypes.h"

//Current File |WChar
#define D_FILE_ __FILEW__

//Short Path of current file |WChar
#define D_FILESHORTNAME_ (DogFW::chars::srchLast(__FILEW__, L'\\') ? DogFW::chars::srchLast(__FILEW__, L'\\') + 1 : __FILEW__)

//Patn and number of current line |WChar
#define D_FILELINEW_ ((DogFW::string::format(L"Line %i File %s ",__LINE__,__FILEW__)).c_str())

