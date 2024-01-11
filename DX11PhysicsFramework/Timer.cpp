#include "Timer.h"

Timer::Timer()
{
	lastFrame = steady_clock::now();
}

float Timer::GetDeltaTime()
{
	float time = duration<float>(steady_clock::now() - lastFrame).count(); //Delta in seconds
	return time;
}

void Timer::Tick()
{
	lastFrame = steady_clock::now();
}
