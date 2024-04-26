#include "julia.h"

Julia::Julia()
{
	mCr = 0;
	mCi = 0;
	mAngle = 0;
}

// draws the julia set, iteratates if z goes to infinity
// when c is a constant. Every time this function is called 
// c is adjusted slightly to see mandelbrot dust. This is 
// different than the mandelbrot set where c cooresponded
// to the screen coordinate that was being drawn to.
void Julia::drawJulia(SDL_Renderer* renderer)
{
	mCr = cos(mAngle * 3.213);
	mCi = sin(mAngle);
	mAngle += .01;
	for (double x = 0; x < 1.0; x += 0.001)
	{
		for (double y = 0; y < 1.0; y += 0.001)
		{
			double real = screenToWorldX(x * 1000);
			double imaginary = screenToWorldY(y * 1000);
			int iters = juliaSet(real, imaginary);

			if (iters == 0)
			{
				SDL_SetRenderDrawColor(renderer, 0, 0, 0, 225);
				SDL_RenderDrawPointF(renderer, x * 1000, y * 1000);
			}
			else
			{
				SDL_SetRenderDrawColor(renderer, 0 + iters * 5, 0 + iters * 5.5, 0 + iters * 6, 225);
				SDL_RenderDrawPointF(renderer, x * 1000, y * 1000);
			}
		}
	}
}

// bascially the same as the mandelbrot set function but c
// is a constant
int Julia::juliaSet(double zr, double zi)
{
	for (int k = 0; k < 50; k++)
	{
		double setZr = zr * zr - zi * zi + mCr;
		double setZi = 2 * zr * zi + mCi;
		zr = setZr;
		zi = setZi;
		double dist = sqrt(zr * zr + zi * zi);
		if (dist > 2)
		{
			int color = (k % 5) + 1;
			return k;
		}
	}

	return 0;
}