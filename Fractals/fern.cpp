#include "fern.h"
#include <random>

int Fern::worldToScreenX(double x)
{
	return x / mScaleFactor + width / 2;
}

int Fern::worldToScreenY(double y)
{
	return -y / mScaleFactor + height;
}

void Fern::nextPoint()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(1, 100);

	int chance = dist(gen);

	if (chance == 1)
	{
		nextX = 0;
		nextY = .16 * y;
	}
	else if (chance <= 85)
	{
		nextX = .85 * x + .04 * y;
		nextY = -.04 * x + .85 * y + 1.6;
	}
	else if (chance <= 93)
	{
		nextX = .2 * x - .26 * y;
		nextY = .23 * x + .22 * y + 1.6;
	}
	else
	{
		nextX = -.15 * x + .28 * y;
		nextY = .26 * x + .24 * y + .44;
	}

	x = nextX;
	y = nextY;
}

void Fern::drawPoint(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	for (int i = 0; i < 100000; i++)
	{
		nextPoint();
		SDL_SetRenderDrawColor(renderer, 225, 225, 225, 225);
		SDL_RenderDrawPointF(renderer, worldToScreenX(x), worldToScreenY(y));
	}
}