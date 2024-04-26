#pragma once

#include "header.h"

class Fern
{
private:
	double mScaleFactor = 1 / (WIDTH * .1);
	double mNextX, mNextY;
	double mX, mY;

public: 
	Fern();

	void drawPoint(SDL_Renderer* renderer);
	int nextPoint();

	int worldToScreenX(double x);
	int worldToScreenY(double y);
};