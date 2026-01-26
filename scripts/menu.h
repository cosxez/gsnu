#include <iostream>
#include <SDL2/SDL.h>
#include <cmath>
extern SDL_Window* win;
extern SDL_Renderer* ren;

using namespace std;

struct Panel
{
	float x1, y1;
	float x2, y2;
};

void panel2(SDL_Window* window, SDL_Renderer* render, float x1, float y1, float x2, float y2)
{
	int w, h;

	if (x1 == 0) { x1 = 1; }
	if (x2 == 0) { x2 = 1; }
	if (y1 == 0) { y1 = 1; }
	if (y2 == 0) { y2 = 1; }

	SDL_GetWindowSize(window, &w, &h);

	SDL_RenderDrawLine(render, w / 2 + x1, h / 2 - y1, w / 2 + x2, h / 2 - y1);
	SDL_RenderDrawLine(render, w / 2 + x1, h / 2 - y1, w / 2 + x1, h / 2 - y2);
	SDL_RenderDrawLine(render, w / 2 + x1, h / 2 - y2, w / 2 + x2, h / 2 - y2);
	SDL_RenderDrawLine(render, w / 2 + x2, h / 2 - y2, w / 2 + x2, h / 2 - y1);
}