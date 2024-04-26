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

int Fern::nextPoint()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(1, 100);

	int chance = dist(gen);
	int color;

	if (chance == 1)
	{
		nextX = 0;
		nextY = .16 * y;
		color = 0;
	}
	else if (chance <= 85)
	{
		nextX = .85 * x + .04 * y;
		nextY = -.04 * x + .85 * y + 1.6;
		color = 1;
	}
	else if (chance <= 93)
	{
		nextX = .2 * x - .26 * y;
		nextY = .23 * x + .22 * y + 1.6;
		color = 2;
	}
	else
	{
		nextX = -.15 * x + .28 * y;
		nextY = .26 * x + .24 * y + .44;
		color = 3;
	}

	x = nextX;
	y = nextY;

	return color;
}

void Fern::drawPoint(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	for (int i = 0; i < 100000; i++)
	{
		switch (nextPoint())
		{
		case 0:
			SDL_SetRenderDrawColor(renderer, 210, 238, 219, 225);
			SDL_RenderDrawPointF(renderer, worldToScreenX(x), worldToScreenY(y));
			break;
		case 1:
			SDL_SetRenderDrawColor(renderer, 181, 227, 196, 225);
			SDL_RenderDrawPointF(renderer, worldToScreenX(x), worldToScreenY(y));
			break;
		case 2:
			SDL_SetRenderDrawColor(renderer, 137, 210, 161, 225);
			SDL_RenderDrawPointF(renderer, worldToScreenX(x), worldToScreenY(y));
			break;
		case 3:
			SDL_SetRenderDrawColor(renderer, 107, 199, 138, 225);
			SDL_RenderDrawPointF(renderer, worldToScreenX(x), worldToScreenY(y));
			break;
		}
		
	}
}