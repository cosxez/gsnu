#include <iostream>
#include <fstream>
#include <SDL2/SDL.h>
#include <vector>
#include <string>
#include <cmath>
#include "geometry.h"

using namespace std;

int main()
{
	SDL_Window* win=SDL_CreateWindow("Viewer",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,640,640,SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

	SDL_Renderer* ren=SDL_CreateRenderer(win,-1,0);

	bool run=true;
	SDL_Event event;

	while (run)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type==SDL_QUIT)
			{
				run=false;
			}
		}
		
		SDL_SetRenderDrawColor(ren,0,0,0,255);
		SDL_RenderClear(ren);
		SDL_SetRenderDrawColor(ren,255,255,255,255);
		
		SDL_RenderPresent(ren);
		SDL_Delay(20);
	}
	SDL_Quit();
	SDL_DestroyWindow(win);
}
