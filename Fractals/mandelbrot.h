#pragma once

#include "header.h"

class Mandelbrot
{
private:
	double mScalar;
	double mScalarUpdate;
	double mScaleFactor;
	double mOrginR;
	double mOrginI;

public:
	Mandelbrot();
	~Mandelbrot();

	void drawMandelbrot(SDL_Renderer* renderer);

	int inSet(double cr, double ci);

	double screenToWorldX(int x);
	double screenToWorldY(int y);

	void setOrginR(double r);
	void setOrginI(double i);

	void updateScale();
};
