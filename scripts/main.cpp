#include <iostream>
#include <fstream>
#include <SDL2/SDL.h>
#include <vector>
#include <string>
#include <cmath>
#include "geometry.h"
#include "menu.h"
#include "render_models.h"
#include "parser.h"

using namespace std;

int main(int args, char* argv[])
{
	SDL_Init(NULL);

	SDL_Window* win = SDL_CreateWindow("Viewer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1024, 940, SDL_WINDOW_SHOWN);

	SDL_Renderer* ren = SDL_CreateRenderer(win, -1, 0);

	SDL_Event event;

	Model saya;
	
	ReadToModel("3d_models/saya", saya, "saya");
	
	unsigned char scene = 0x00;
	int width, height;

	SDL_GetWindowSize(win, &width, &height);
	
	while (true)
	{
		SDL_PollEvent(&event);

		if (event.type == SDL_QUIT)
		{
			break;
		}

		SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
		SDL_RenderClear(ren);
		SDL_SetRenderDrawColor(ren, 255, 255, 255, 255);
		
		if (scene == 0x00)
		{
			render3(win,ren,saya,0x01,135,width/2+(width/100*20), 0, 1.3);
		}
		
		SDL_RenderPresent(ren);
		SDL_Delay(40);
	}
	SDL_Quit();
	SDL_DestroyWindow(win);
	return 0;
}