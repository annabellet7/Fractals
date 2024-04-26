#include <iostream>

#include "header.h"
#include "mandelbrot.h"
#include "julia.h"
#include "fern.h"
#include "triangle.h"

int main(int argc, char* argv[])
{
	bool running = true;
	Mandelbrot mandelbrot;
	Julia julia;
	Fern fern;
	TriangleFrac triangle;

	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* window = SDL_CreateWindow("Fractals", 800, 0, WIDTH, HEIGHT, 0);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

	int xMouse, yMouse, state = Mandelbrot_State;
	double r, i;
	double real, imaginary;
	SDL_Event event;

	mandelbrot.drawMandelbrot(renderer);

	std::cout << "running" << std::endl;
	while (running)
	{
		if (state == Julia_State)
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
					state = Mandelbrot_State;
					break;
				case SDLK_2:
					julia.drawJulia(renderer);
					state = Julia_State;
					break;
				case SDLK_3:
					fern.drawPoint(renderer);
					state = Fern_State;
					break;
				case SDLK_4:
					SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
					SDL_RenderClear(renderer);
					triangle.drawFractal(WIDTH / 2 - triangle.mLength / 2, HEIGHT / 2 + std::sin(M_PI / 3) * triangle.mLength / 2, triangle.mLength, renderer, 1);
					state = Triangle_State;
					break;
				}
				break;
			case SDL_MOUSEMOTION:
				if (state == Mandelbrot_State || state == Julia_State)
				{
					SDL_GetMouseState(&xMouse, &yMouse);
					r = mandelbrot.screenToWorldX(xMouse);
					i = mandelbrot.screenToWorldY(yMouse);
					std::cout << "(" << r << ", " << i << ")" << std::endl;
				}
				break;
			case SDL_MOUSEBUTTONUP:
				if (state == Mandelbrot_State)
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
				if (state == Mandelbrot_State)
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