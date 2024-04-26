#pragma once

#include "mandelbrot.h"

class Julia : public Mandelbrot
{
private:
	double mCr, mCi, mAngle;

public:
	Julia();

	void drawJulia(SDL_Renderer* renderer);
	int juliaSet(double zr, double zi);
};
