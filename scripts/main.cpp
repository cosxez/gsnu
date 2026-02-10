#include <iostream>
#include <fstream>
#include <SDL2/SDL.h>
#include <vector>
#include <string>
#include <cmath>
#include "geometry.h"
#include "render_models.h"
#include "parser.h"
#include "UI.h"

using namespace std;

int main(int args, char* argv[])
{
	SDL_Init(SDL_INIT_VIDEO);
	
	SDL_Window* win = SDL_CreateWindow("GSNU", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1024, 940, SDL_WINDOW_SHOWN);

	SDL_Renderer* ren = SDL_CreateRenderer(win, -1, 0);

	char run = true;
	SDL_Event event;

	Model menu;
	Model sakura_leaf;
	Model saya;
	Model s1;

	ReadToModel("3d_models/s1.jsfm",s1,"scene1");
	ReadToModel("3d_models/saya.jsfm",saya,"saya");
	ReadToModel("3d_models/sakura_leaf.jsfm",sakura_leaf,"sakura_leaf");
	ReadToModel("3d_models/menu.jsfm", menu, "menu");

	char scene = 0x00;
	int width, height;

	SDL_GetWindowSize(win, &width, &height);

	int dx=width/2, dy=height/2;
	while (run)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				run = false;
			}
		}

		SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
		SDL_RenderClear(ren);

		if (scene == 0x00)
		{
			dx -= 2;
			dy -= 7;
			if (dy <= -height / 2) { dx = width / 2; dy = height; }
			
			//house and saya
			render3(win, ren, menu, Color{150,150,150}, 0x01, 125, width / 2 + (width / 100 * 20), 0, 1);

			//animated sakura leaves
			{
				render3(win, ren, sakura_leaf, Color{ 200,100,150 }, 0x02, 10 + dy, dx * 17, dy * 17, 17);
				render3(win, ren, sakura_leaf, Color{ 200,100,150 }, 0x01, 20 - dy, dx * 17 - 90 * 17, dy * 17 + 400 * 17, 17);
				render3(win, ren, sakura_leaf, Color{ 200,100,150 }, 0x01, 50 + dx, dx * 17 - 10 * 17, dy * 17 - 150 * 17, 17);
				render3(win, ren, sakura_leaf, Color{ 200,100,150 }, 0x02, 20 - dy, dx * 17 - 260 * 17, dy * 17 + 350 * 17, 17);
				render3(win, ren, sakura_leaf, Color{ 200,100,150 }, 0x01, 50 + dx, dx * 17 - 350 * 17, dy * 17 - 230 * 17, 17);
				render3(win, ren, sakura_leaf, Color{ 200,100,150 }, 0x02, 20 - dx, dx * 17 - 220 * 17, dy * 17 + 690 * 17, 17);
				render3(win, ren, sakura_leaf, Color{ 200,100,150 }, 0x01, 50 + dy, dx * 17 - 490 * 17, dy * 17 - 110 * 17, 17);
				render3(win, ren, sakura_leaf, Color{ 200,100,150 }, 0x01, 20 - dy, dx * 17 - 90 * 17, dy * 17 + 200 * 17, 17);
				render3(win, ren, sakura_leaf, Color{ 200,100,150 }, 0x01, 50 + dx, dx * 17 - 10 * 17, dy * 17 - 550 * 17, 17);
				render3(win, ren, sakura_leaf, Color{ 200,100,150 }, 0x02, 20 - dy, dx * 17 - 260 * 17, dy * 17 + 250 * 17, 17);
				render3(win, ren, sakura_leaf, Color{ 200,100,150 }, 0x01, 50 + dx, dx * 17 - 350 * 17, dy * 17 - 730 * 17, 17);
				render3(win, ren, sakura_leaf, Color{ 200,100,150 }, 0x01, 20 - dx, dx * 17 - 20 * 17, dy * 17 + 90 * 17, 17);
				render3(win, ren, sakura_leaf, Color{ 200,100,150 }, 0x02, 50 + dy, dx * 17 - 490 * 17, dy * 17 - 410 * 17, 17);
			}
			SDL_SetRenderDrawColor(ren,200,200,200,255);
			
			//UI
			EventMouse start_button;
			EventMouse exit_button;
			
			start_button.event = SDL_BUTTON_LEFT;
			start_button.constant = &scene;
			start_button.endform = 0x01;

			exit_button.event=SDL_BUTTON_LEFT;
			exit_button.constant=&run;
			exit_button.endform = false;
			
			buttonUI(ren, event, start_button, width / 100 * 20, height / 100 * 20, width / 100 * 40, height / 100 * 30);
			buttonUI(ren,event,exit_button, width/100*40,height/100*70,width/100*60,height/100*80);
			
			if (scene==0x01) 
			{
				uint8_t c=150;
				while (c>0)
				{
					SDL_PollEvent(&event);
					render3(win,ren,menu,Color{c,c,c},0x01,125,width/2+(width/100*20),0,1);
					c--;
					SDL_RenderPresent(ren);
					SDL_Delay(5);
				}
			}
		}
		
		if (scene == 0x01)
		{
			render3(win, ren, s1, {170,30,50},0x01,-30,-200*3,100*3,3);
		}

		SDL_RenderPresent(ren);
		SDL_Delay(20);
	}
	SDL_Quit();
	SDL_DestroyWindow(win);
	return 0;
}
