#include "julia.h"

Julia::Julia()
{
	cr = 0;
	ci = 0;
	angle = 0;
}

int Julia::juliaSet(double zr, double zi)
{
	for (int k = 0; k < 50; k++)
	{
		double setZr = zr * zr - zi * zi + cr;
		double setZi = 2 * zr * zi + ci;
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

void Julia::drawJulia(SDL_Renderer* renderer)
{
	cr = cos(angle * 3.213);
	ci = sin(angle);
	angle += .01;
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