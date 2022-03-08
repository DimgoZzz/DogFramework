#include "DFW/Time/Stopwatch.h"
#include "DFW/DWin.h"

using namespace DogFW;

Stopwatch::Stopwatch() :
	startTick_(0),
	stopTick_(0),
	stopped_(true)
{
	Int64 countsPerSec;
	QueryPerformanceFrequency((LARGE_INTEGER*)&countsPerSec);
	if (countsPerSec <= 0)
	{
		win::msgbox::critError(L"QueryPerformanceFrequency return 0!");
	}
	secondsPerTick_ = 1.0 / (Double)countsPerSec;
}

void DogFW::Stopwatch::start()
{
	if (stopped_)
	{
		Int64 temp;
		if (QueryPerformanceCounter((LARGE_INTEGER*)&temp) == 0)
		{
			win::msgbox::critError(L"QueryPerformanceCounter return 0!");
		}
		startTick_ = temp;
		stopped_ = false;
	}
}

void DogFW::Stopwatch::stop()
{
	if (!stopped_)
	{
		Int64 temp;
		if (QueryPerformanceCounter((LARGE_INTEGER*)&temp) == 0)
		{
			win::msgbox::critError(L"QueryPerformanceCounter return 0!");
		}
		stopTick_ = temp;
		stopped_ = true;
	}
}

Int64 DogFW::Stopwatch::getTickStart() const
{
	return startTick_;
}

Int64 Stopwatch::getTickCurrent() const
{
	Int64 currTime;
	if (QueryPerformanceCounter((LARGE_INTEGER*)&currTime) == 0)
	{
		win::msgbox::critError(L"QueryPerformanceCounter return 0!");
	}
	return currTime;
}

Int64 DogFW::Stopwatch::getTickElapsed() const
{
	return stopTick_ - startTick_;
}

Float DogFW::Stopwatch::getTimeElapsed() const
{
	return static_cast<Float>(((Double)getTickElapsed())*secondsPerTick_);
}
