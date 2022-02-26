#include "DFW/External/Windows/DWError.h"

#include <comdef.h>

namespace DogFW::win::error
{
	WString getErrorDesc(DWORD errorMessageID)
	{
		_com_error error(errorMessageID);
		WString error_message = error.ErrorMessage();
		return error_message;
	}
}