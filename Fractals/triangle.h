#pragma once
#include <SDL.h>
#include <utility>

class TriangleFrac
{
private:
	int mMax = 10;

public:
	static const int mLength = 800;

	void drawFractal(float x, float y, int length, SDL_Renderer* renderer, int levels);
	void triangle(std::pair <int, int> a, std::pair <int, int> b, std::pair <int, int> c, SDL_Renderer* renderer);
	void triangleLength(float x, float y, int length, SDL_Renderer* renderer);
};
