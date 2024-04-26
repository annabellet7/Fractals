#pragma once

#include <SDL.h>

class Fern
{
private:
	int width = 1000, height = 1000;
	double mScaleFactor = 1 / (width * .1);
	double nextX, nextY;
	double x = 0, y = 0;
public: 
	int worldToScreenX(double x);
	int worldToScreenY(double y);

	int nextPoint();
	void drawPoint(SDL_Renderer* renderer);
};