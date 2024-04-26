#include "triangle.h"
#include <cmath>

// draws sierpinski's triangle recursively
void TriangleFrac::drawFractal(float x, float y, int length, SDL_Renderer* renderer, int levels)
{
	if (levels == mMax)
	{
		triangleLength(x, y, length, renderer);
	}
	else
	{
		drawFractal(x, y, length / 2, renderer, levels + 1);
		drawFractal(x + length / 2, y, length / 2, renderer, levels + 1);
		drawFractal(x + length / 4, y - std::sin(M_PI / 3) * length / 2, length / 2, renderer, levels + 1);
	}
}

// draws a triangle given 3 points
void TriangleFrac::triangle(std::pair <int, int> a, std::pair <int, int> b, std::pair <int, int> c, SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, 225, 225, 225, 255);
	SDL_RenderDrawLine(renderer, a.first, a.second, b.first, b.second);
	SDL_RenderDrawLine(renderer, b.first, b.second, c.first, c.second);
	SDL_RenderDrawLine(renderer, c.first, c.second, a.first, a.second);
}

// draws a equilateral triangle given a point and the length of the sides
void TriangleFrac::triangleLength(float x, float y, int length, SDL_Renderer* renderer)
{
	triangle(std::make_pair(x, y), std::make_pair(x + length / 2, y - std::sin(M_PI / 3) * length), std::make_pair(x + length, y), renderer);
}