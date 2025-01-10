#pragma once
class screenResolution
{
public:
	static const int get_screenWidth() {
		return screenWidth;
	}
	static const int get_screenHeight() {
		return screenHeight;
	}
private:
	static int screenWidth;
	static int screenHeight;
};

