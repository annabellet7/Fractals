#pragma once
#include <SDL.h>

class Mandelbrot
{
private:
	double mScalar;
	double mScalarUpdate;
	double mScaleFactor;
	double mOrginR;
	double mOrginI;
	
	const int WIDTH = 1000;
	const int HEIGHT = 1000;

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
