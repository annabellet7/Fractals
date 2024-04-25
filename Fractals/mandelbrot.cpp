#include "mandelbrot.h"
#include <cmath>

Mandelbrot::Mandelbrot()
{
	mScalar = .25;
	mScalarUpdate = .1;
	mScaleFactor = 1 / (WIDTH * mScalar);
	mOrginR = 0;
	mOrginI = 0;
}

Mandelbrot::~Mandelbrot()
{

}

int Mandelbrot::inSet(double cr, double ci)
{
	double zr = 0;
	double zi = 0;
	for (int k = 0; k < 250; k++)
	{
		double setZr = zr * zr - zi * zi + cr;
		double setZi = 2 * zr * zi + ci;
		zr = setZr;
		zi = setZi;
		double dist = sqrt(zr * zr + zi * zi);
		if (dist > 2)
		{
			int color = (k % 5) + 1;
			return color;
		}
	}

	return 0;
}

double Mandelbrot::screenToWorldX(int x)
{
	return mOrginR + (x - WIDTH / 2) * mScaleFactor;
}

double Mandelbrot::screenToWorldY(int y)
{
	return mOrginI - (y - HEIGHT / 2) * mScaleFactor;
}

void Mandelbrot::setOrginR(double r)
{
	mOrginR = r;
}

void Mandelbrot::setOrginI(double i)
{
	mOrginI = i;
}

void Mandelbrot::drawMandelbrot(SDL_Renderer* renderer)
{
	for (double x = 0; x < 1.0; x += 0.001)
	{
		for (double y = 0; y < 1.0; y += 0.001)
		{
			double real = screenToWorldX(x * 1000);
			double imaginary = screenToWorldY(y * 1000);
			int iters = inSet(real, imaginary);

			switch (iters)
			{
			case MandelbrotColors::Black:
				SDL_SetRenderDrawColor(renderer, 0, 0, 0, 225);
				SDL_RenderDrawPointF(renderer, x * 1000, y * 1000);
				break;
			case MandelbrotColors::Purple:
				SDL_SetRenderDrawColor(renderer, 60, 55, 68, 225);
				SDL_RenderDrawPointF(renderer, x * 1000, y * 1000);
				break;
			case MandelbrotColors::RoyalBlue:
				SDL_SetRenderDrawColor(renderer, 9, 12, 155, 225);
				SDL_RenderDrawPointF(renderer, x * 1000, y * 1000);
				break;
			case MandelbrotColors::Blue:
				SDL_SetRenderDrawColor(renderer, 61, 82, 213, 225);
				SDL_RenderDrawPointF(renderer, x * 1000, y * 1000);
				break;
			case MandelbrotColors::LightBlue:
				SDL_SetRenderDrawColor(renderer, 180, 192, 228, 225);
				SDL_RenderDrawPointF(renderer, x * 1000, y * 1000);
				break;
			case MandelbrotColors::White:
				SDL_SetRenderDrawColor(renderer, 251, 255, 241, 225);
				SDL_RenderDrawPointF(renderer, x * 1000, y * 1000);
				break;
			}
		}
	}
}

void Mandelbrot::updateScale()
{
	mScalar += mScalarUpdate;
	mScaleFactor = 1 / (WIDTH * mScalar);

	if (mScalarUpdate <= 1)
	{
		mScalarUpdate += .1;
	}
	if (mScalarUpdate > 1)
	{
		mScalarUpdate += 10;
	}
}