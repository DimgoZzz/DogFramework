#pragma once
#include "DFW/DBasicTypes.h"

namespace DogFW
{
	class StopWatch
	{
	public:
		StopWatch();

		void start();
		void stop();

		Int64 getTickStart()   const;
		Int64 getTickCurrent() const;
		Int64 getTickElapsed() const;
		Float getTimeElapsed() const;
	private:
		Double secondsPerTick_;

		Int64 startTick_;
		Int64 stopTick_;
	};
}
