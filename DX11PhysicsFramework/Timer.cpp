#include "Timer.h"

Timer::Timer()
{
	lastFrame;
}

float Timer::GetDeltaTime()
{
	return 0.0f;
}

void Timer::Tick()
{
	lastFrame = steady_clock::now();

	lastFrame = duration<float>(steady_clock::now() - lastFrame).count();
}
