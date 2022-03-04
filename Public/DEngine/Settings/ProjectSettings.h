#pragma once
#include "DFW/DBasicTypes.h"
#include "DFW/DString.h"
#include "DFW/DLibResources.h"
#include "DFW/DFiles.h"


namespace DogFW::settings
{
	class ProjectSettings
	{
	public:
		ProjectSettings();
		~ProjectSettings();
	public:
		WString getName();
		WString getNameShort();
		Path	getLogPath();

	protected:
		WString projectName {L"Untitled Project"};
		WString projectNameShort {L"U P"};
		Path logPath{ L"Log\\"};
		HICON projectDefaultIcon{ libres::getIcon(libres::EnLibIcons::IconMainDFW) };
	};

}