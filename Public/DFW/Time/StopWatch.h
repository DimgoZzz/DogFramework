#pragma once
#include "DFW/DBase.h"

namespace DogFW
{
	class Stopwatch
	{
	public:
		Stopwatch();

		void start();
		void stop();

		Int64 getTickStart()   const;
		Int64 getTickCurrent() const;
		Int64 getTickElapsed() const;
		Float getTimeElapsed() const;
	private:
		Double secondsPerTick_;

		Bool stopped_;
		Int64 startTick_;
		Int64 stopTick_;
	};
}
