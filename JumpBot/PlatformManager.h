#pragma once

#include <vector>
#include "Platform.h"

class PlatformManager
{
public:
	std::vector<std::unique_ptr<Platform>> platforms = {};

	int init();
	void update();
	void render();
	void addPlat(std::unique_ptr<Platform> plats);
};

