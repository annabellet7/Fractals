#pragma once
#include <SDL.h>

static const int WIDTH = 1000;
static const int HEIGHT = 1000;

enum State
{
	Mandelbrot_State,
	Julia_State,
	Fern_State,
	Triangle_State
};