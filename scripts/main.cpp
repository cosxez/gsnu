#include <iostream>
#include <fstream>
#include <SDL2/SDL.h>
#include <vector>
#include <string>
#include <cmath>
#include <string>
#include "geometry.h"
#include "menu.h"
#include "render_models.h"

using namespace std;

int main(int args, char* argv[])
{
	SDL_Init(NULL);

	SDL_Window* win = SDL_CreateWindow("Viewer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1024, 940, SDL_WINDOW_SHOWN);

	SDL_Renderer* ren = SDL_CreateRenderer(win, -1, 0);

	SDL_Event event;

	ifstream file("3d_models/saya");

	Vector vecC
	Point pointC;
	Triangle trgC;

	vector<Vector> vecs;
	vector<Point> ver;
	vector<Triangle> trgs;

	string line;
	while (getline(file, line))
	{
		if (!line.empty())
		{
			line += ' ';
			string ch;
			short cht = 0;
			for (int i = 2; i < line.size(); i++)
			{
				if (line[i] == ' ')
				{
					float chi = stof(ch);
					if (line[0] == 't')
					{
						if (cht == 0) { trgC.x1 = chi; }
						if (cht == 1) { trgC.y1 = chi; }
						if (cht == 2) { trgC.z1 = chi; }
						if (cht == 3) { trgC.x2 = chi; }
						if (cht == 4) { trgC.y2 = chi; }
						if (cht == 5) { trgC.z2 = chi; }
						if (cht == 6) { trgC.x3 = chi; }
						if (cht == 7) { trgC.y3 = chi; }
						if (cht == 8) { trgC.z3 = chi; trgs.push_back(trgC); }
					}

					if (line[0] == 'p')
					{
						if (cht == 0) { pointC.x = chi; }
						if (cht == 1) { pointC.y = chi; }
						if (cht == 2) { pointC.z = chi; ver.push_back(pointC); }
					}

					if (line[0] == 'v')
					{
						if (cht == 0) { vecC.x1 = chi; }
						if (cht == 1) { vecC.y1 = chi; }
						if (cht == 2) { vecC.z1 = chi; }
						if (cht == 3) { vecC.x2 = chi; }
						if (cht == 4) { vecC.y2 = chi; }
						if (cht == 5) { vecC.z2 = chi; vecs.push_back(vecC); }
					}

					ch = "";
					cht++;
				}
				else { ch += line[i]; }
			}
			cht = 0;
		}
	}
	file.close();

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
			render3(win,ren,ver,vecs,trgs,0x01,135,400,0,1);
		}
		
		SDL_RenderPresent(ren);
		SDL_Delay(40);
	}
	SDL_Quit();
	SDL_DestroyWindow(win);
	return 0;
}