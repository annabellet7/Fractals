#pragma once

#include "Header.h"
#include "mandelbrot.h"

class Julia : public Mandelbrot
{
private:
	double cr, ci, angle;

public:
	Julia();

	int juliaSet(double cr, double ci);
	void drawJulia(SDL_Renderer* renderer);

};
