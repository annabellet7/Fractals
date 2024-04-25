#include <iostream>

#include "Header.h"
#include "mandelbrot.h"
#include "julia.h"

int main(int argc, char* argv[])
{
	bool running = true;
	Mandelbrot mandelbrot;
	Julia julia;

	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* window = SDL_CreateWindow("Fractals", 800, 0, WIDTH, HEIGHT, 0);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
	

	int xMouse, yMouse;
	double r, i;
	double real, imaginary;
	SDL_Event event;

	std::cout << "running" << std::endl;
	while (running)
	{
		//SDL_RenderClear(renderer);
		//mandelbrot.drawMandelbrot(renderer);
		julia.drawJulia(renderer);
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_KEYDOWN:
				running = false;
				break;
			case SDL_MOUSEMOTION:
				SDL_GetMouseState(&xMouse, &yMouse);
				r = mandelbrot.screenToWorldX(xMouse);
				i = mandelbrot.screenToWorldY(yMouse);
				std::cout << "(" << r << ", " << i << ")" << std::endl;
				break;
			case SDL_MOUSEBUTTONUP:
				SDL_GetMouseState(&xMouse, &yMouse);
				r = mandelbrot.screenToWorldX(xMouse);
				i = mandelbrot.screenToWorldY(yMouse);
				mandelbrot.setOrginR(r);
				mandelbrot.setOrginI(i);

				mandelbrot.drawMandelbrot(renderer);
				break;
			case SDL_MOUSEWHEEL:
				mandelbrot.updateScale();
				mandelbrot.drawMandelbrot(renderer);
				break;
			}
		}
		SDL_RenderPresent(renderer);
		//SDL_Delay(16);
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	return 0;
}