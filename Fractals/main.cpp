#include <iostream>

#include "mandelbrot.h"
#include "julia.h"
#include "fern.h"

int main(int argc, char* argv[])
{
	bool running = true;
	Mandelbrot mandelbrot;
	Julia julia;
	Fern fern;

	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* window = SDL_CreateWindow("Fractals", 800, 0, 1000, 1000, 0);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
	

	int xMouse, yMouse, state = 1;
	double r, i;
	double real, imaginary;
	SDL_Event event;

	mandelbrot.drawMandelbrot(renderer);
	//fern.drawPoint(renderer);

	std::cout << "running" << std::endl;
	while (running)
	{
		if (state == 2)
		{
			julia.drawJulia(renderer);
		}
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym)
				{
				case SDLK_ESCAPE:
					running = false;
					break;
				case SDLK_1:
					mandelbrot.drawMandelbrot(renderer);
					state = 1;
					break;
				case SDLK_2:
					julia.drawJulia(renderer);
					state = 2;
					break;
				case SDLK_3:
					fern.drawPoint(renderer);
					state = 3;
					break;
				}
				break;
			case SDL_MOUSEMOTION:
				if (state == 1 || state == 2)
				{
					SDL_GetMouseState(&xMouse, &yMouse);
					r = mandelbrot.screenToWorldX(xMouse);
					i = mandelbrot.screenToWorldY(yMouse);
					std::cout << "(" << r << ", " << i << ")" << std::endl;
				}
				break;
			case SDL_MOUSEBUTTONUP:
				if (state == 1)
				{
					SDL_GetMouseState(&xMouse, &yMouse);
					r = mandelbrot.screenToWorldX(xMouse);
					i = mandelbrot.screenToWorldY(yMouse);
					mandelbrot.setOrginR(r);
					mandelbrot.setOrginI(i);

					mandelbrot.drawMandelbrot(renderer);
				}
				break;
			case SDL_MOUSEWHEEL:
				if (state == 1)
				{
					mandelbrot.updateScale();
					mandelbrot.drawMandelbrot(renderer);
				}
				break;
			}
		}
		SDL_RenderPresent(renderer);
		SDL_Delay(16);
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}