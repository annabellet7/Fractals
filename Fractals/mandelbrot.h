#pragma once
#include "Header.h"

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

	int inSet(double cr, double ci);
	double screenToWorldX(int x);
	double screenToWorldY(int y);
	void drawMandelbrot(SDL_Renderer* renderer);

	void setOrginR(double r);
	void setOrginI(double i);
	void updateScale();

};
