#pragma once
#include "DEngine/Systems/App/IApp.h"

namespace DogFW :: engine
{
	class App : public IApp
	{
	public:
		App();
		~App();
	public:
		void initialize() override;
		void update() override;
	};
}