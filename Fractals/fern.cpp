#include "fern.h"
#include <random>

Fern::Fern()
{
	mScaleFactor = 1 / (WIDTH * .1);
	mNextX = 0;
	mNextY = 0;
	mX = 0;
	mY = 0;
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
			SDL_RenderDrawPointF(renderer, worldToScreenX(mX), worldToScreenY(mY));
			break;
		case 1:
			SDL_SetRenderDrawColor(renderer, 181, 227, 196, 225);
			SDL_RenderDrawPointF(renderer, worldToScreenX(mX), worldToScreenY(mY));
			break;
		case 2:
			SDL_SetRenderDrawColor(renderer, 137, 210, 161, 225);
			SDL_RenderDrawPointF(renderer, worldToScreenX(mX), worldToScreenY(mY));
			break;
		case 3:
			SDL_SetRenderDrawColor(renderer, 107, 199, 138, 225);
			SDL_RenderDrawPointF(renderer, worldToScreenX(mX), worldToScreenY(mY));
			break;
		}

	}
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
		mNextX = 0;
		mNextY = .16 * mY;
		color = 0;
	}
	else if (chance <= 85)
	{
		mNextX = .85 * mX + .04 * mY;
		mNextY = -.04 * mX + .85 * mY + 1.6;
		color = 1;
	}
	else if (chance <= 93)
	{
		mNextX = .2 * mX - .26 * mY;
		mNextY = .23 * mX + .22 * mY + 1.6;
		color = 2;
	}
	else
	{
		mNextX = -.15 * mX + .28 * mY;
		mNextY = .26 * mX + .24 * mY + .44;
		color = 3;
	}

	mX = mNextX;
	mY = mNextY;

	return color;
}

int Fern::worldToScreenX(double x)
{
	return x / mScaleFactor + WIDTH / 2;
}

int Fern::worldToScreenY(double y)
{
	return -y / mScaleFactor + HEIGHT;
}

