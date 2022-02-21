#include "DFW/Time/StopWatch.h"
#include "DFW/DWin.h"

using namespace DogFW;

StopWatch::StopWatch() :
	startTick_(0),
	stopTick_(0)
{
	Int64 countsPerSec;
	QueryPerformanceFrequency((LARGE_INTEGER*)&countsPerSec);
	secondsPerTick_ = 1.0 / (Double)countsPerSec;
}

void DogFW::StopWatch::start()
{
	Int64 temp;
	QueryPerformanceCounter((LARGE_INTEGER*)&temp);
	startTick_ = temp;
}

void DogFW::StopWatch::stop()
{
	Int64 temp;
	QueryPerformanceCounter((LARGE_INTEGER*)&temp);
	stopTick_ = temp;

}

Int64 DogFW::StopWatch::getTickStart() const
{
	return startTick_;
}

Int64 StopWatch::getTickCurrent() const
{
	Int64 currTime;
	QueryPerformanceCounter((LARGE_INTEGER*)&currTime);
	return currTime;
}

Int64 DogFW::StopWatch::getTickElapsed() const
{
	return stopTick_ - startTick_;
}

Float DogFW::StopWatch::getTimeElapsed() const
{
	return static_cast<Float>(((Double)getTickElapsed())*secondsPerTick_);
}
