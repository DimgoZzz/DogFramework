#pragma once
#include "DogFW/Engine/Core/App/IApp.h"

namespace DogFW :: inline app
{
	class Application : public IApplication
	{
	public:
		Application();
		~Application();
	public:
		void initialize() override;
		void update() override;
	};
}