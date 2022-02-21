#include "DFW/Text/Char/Char.h"
#include <string>

namespace DogFW::inline basictypes::chars
{
    const Char* srchLast(const Char *cArr, Char value)
    {
        return std::strrchr(cArr, value);
    }
    const WChar* srchLast(const WChar  *wArr, WChar value)
    {
        return std::wcsrchr(wArr, value);
    }
}
