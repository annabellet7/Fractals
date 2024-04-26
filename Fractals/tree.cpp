#include "tree.h"
#include <cmath>
#include <math.h>

Tree::Tree() 
{
	
}

void Tree::drawBranch(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, 225, 225, 225, 225);
	SDL_RenderDrawLine(renderer, WIDTH / 2, HEIGHT, WIDTH / 2, HEIGHT / 2);

	tree[0].mStart.first = WIDTH / 2;
	tree[0].mStart.second = HEIGHT;
	tree[0].mEnd.first = WIDTH / 2;
	tree[0].mEnd.second = HEIGHT / 2;
}

void Tree::drawLeft()
{

}

void Tree::drawRight()
{

}

Branch Tree::getBranch(int i)
{
	return tree[i];
}

void Tree::clockWise(Branch branch, double theta, SDL_Renderer* renderer)
{
	std::pair <int, int> start;
	std::pair <int, int> end;

	std::pair <int, int> branchVec;

	branchVec.first = branch.mEnd.first - branch.mStart.first;
	branchVec.second = branch.mEnd.second - branch.mStart.second;

	start.first = branch.mEnd.first;
	start.second = branch.mEnd.second;

	end.first = branch.mEnd.first; + branchVec.first;
	end.second = branch.mEnd.second + branchVec.second;

	end.first = (std::cos(theta) * (end.first - start.first) + std::sin(theta) * (end.second - start.second)) + start.second;
	end.second = -std::sin(theta) * (end.first - start.first) + std::cos(theta) * (end.second - start.second) + start.second;

	SDL_SetRenderDrawColor(renderer, 225, 225, 225, 225);
	SDL_RenderDrawLine(renderer, start.first, start.second, end.first, end.second);
}

void Tree::counterClockWise(Branch branch, double theta, SDL_Renderer* renderer)
{

}