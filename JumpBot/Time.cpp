#include "Time.h"

Uint64 Time::now = 0;
Uint64 Time::last = 0;
double Time::deltaTime = 0;

double Time::UpdateDeltaTime()
{
	Time::last = now;
	now = SDL_GetPerformanceCounter();

	deltaTime = (double)((now - last) / (double)SDL_GetPerformanceFrequency());

	return deltaTime;
}
