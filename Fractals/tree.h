#pragma once

#include <SDL.h>
#include <utility>

struct Branch
{
	std::pair <int, int> mStart;
	std::pair <int, int> mEnd;
};

class Tree
{
private:

	const int WIDTH = 1000;
	const int HEIGHT = 1000;

	Branch tree[50];
public:
	Tree();

	void drawBranch(SDL_Renderer* renderer);
	void drawLeft();
	void drawRight();

	Branch getBranch(int i);

	void clockWise(Branch branch, double theta, SDL_Renderer* renderer);
	void counterClockWise(Branch branch, double theta, SDL_Renderer* renderer);
};
