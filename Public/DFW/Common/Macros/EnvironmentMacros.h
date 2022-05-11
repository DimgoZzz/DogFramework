#pragma once

//File/Line Names
#define D_LINE __LINE__

//Current File |WChar
#define D_FILE __FILEW__

//Short Path of current file |WChar
#define D_FILESHORT (DogFW::chars::srchLast(D_FILE, L'\\') ? DogFW::chars::srchLast(D_FILE, L'\\') + 1 : D_FILE)

//Patn and number of current line |WChar
#define D_LINEFILE ((DogFW::string::format(L"Line %i File %s ",D_LINE,D_FILE)).c_str())

