#pragma once

#include <iostream>
#include <SDL_stdinc.h>
#include <SDL.h>

class Time
{
public:
	static const double get_deltaTime()
	{
		return deltaTime;
	}
	static double UpdateDeltaTime();

private:
	static double deltaTime;
	static Uint64 now;
	static Uint64 last;
};

