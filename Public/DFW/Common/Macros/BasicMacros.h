//Environment Macros
#pragma once

//#define D_DISABLEEXCEPT

#ifdef D_DISABLEEXCEPT
#define nexpt 
#else
#define nexpt noexcept
#endif

//File/Line Names

#define D_LINE_ __LINE__

//Current File |WChar
#define D_FILE_ __FILEW__

//Short Path of current file |WChar
#define D_FILESHORT_ (DogFW::chars::srchLast(D_FILE_, L'\\') ? DogFW::chars::srchLast(D_FILE_, L'\\') + 1 : D_FILE_)

//Patn and number of current line |WChar
#define D_LINEFILE_ ((DogFW::string::format(L"Line %i File %s ",__LINE__,D_FILE_)).c_str())
