#pragma once

namespace DogFW :: engine
{
	class IApp
	{
	protected:
		IApp();
		virtual ~IApp() = 0;
	public:
		virtual void initialize() = 0;
		virtual void update() = 0;
	};
}