#include "DFW/LibResources/Icons/LibIcons.h"

namespace DogFW::libres
{
	HICON getIcon(EnLibIcons icon,Int32 iconSize)
	{
		switch (icon)
		{
		///////////////////////////////////////////
		case EnLibIcons::IconDFWMain:
			{
				return icons::getDFWMain(iconSize);
			}
		///////////////////////////////////////////

		}
	}
}