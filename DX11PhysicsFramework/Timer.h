#pragma once

#include <chrono>

using namespace std::chrono;

class Timer
{
public:
	Timer(); //Constructor

	float GetDeltaTime(); //Request time since last frame
	void Tick(); //Store time of last frame

private:
	steady_clock::time_point lastFrame;
};

