#include <iostream>
#include <SDL2/SDL.h>
#include <cmath>

using namespace std;

struct Point
{
	float x,y,z;
};

struct Vector
{
	float x1,y1,z1;
	float x2,y2,z2;
};

struct Triangle
{
	float x1,y1,z1;
	float x2,y2,z2;
	float x3,y3,z3;
};

struct Circle
{
	float x,y;
	float r;
};

struct Plane
{
	float x1, y1, z1;
	float x2, y2, z2;
};


void point3(SDL_Window* window, SDL_Renderer* render, float x, float y, float z)
{
	int w,h;
	
	if (x==0){x=1;}
	if (y==0){y=1;}
	if (z==0){z=1;}
	
	SDL_GetWindowSize(window,&w,&h);
	SDL_RenderDrawPoint(render,w/2+(x/z),h/2-(y/z));
}

void vector3(SDL_Window* window, SDL_Renderer* render, float x1, float y1, float z1, float x2, float y2, float z2)
{
	int w,h;

	if (z1==0){z1=1;}
	if (z2==0){z2=1;}
	if (x1==0){x1=1;}
	if (x2==0){x2=1;}
	if (y1==0){y1=1;}
	if (y2==0){y2=1;}
	SDL_GetWindowSize(window,&w,&h);

	SDL_RenderDrawLine(render,w/2+(x1/z1),h/2-(y1/z1),w/2+(x2/z2),h/2-(y2/z2));
}

void triangle3(SDL_Window* window, SDL_Renderer* render, float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3)
{
	int w,h;

	if (z1==0){z1=1;}
	if (z2==0){z2=1;}
	if (z3==0){z3=1;}
	if (x1==0){x1=1;}
	if (x2==0){x2=1;}
	if (x3==0){x3=1;}
	if (y1==0){y1=1;}
	if (y2==0){y2=1;}
	if (y3==0){y3=1;}
	
	SDL_GetWindowSize(window,&w,&h);

	SDL_RenderDrawLine(render,w/2+(x1/z1),h/2-(y1/z1),w/2+(x2/z2),h/2-(y2/z2));
	SDL_RenderDrawLine(render,w/2+(x1/z1),h/2-(y1/z1),w/2+(x3/z3),h/2-(y3/z3));
	SDL_RenderDrawLine(render,w/2+(x2/z2),h/2-(y2/z2),w/2+(x3/z3),h/2-(y3/z3));
}

void plane3(SDL_Window* window, SDL_Renderer* render, float x1, float y1, float z1, float x2, float y2, float z2)
{
	int w, h;

	if (z1 == 0) { z1 = 1; }
	if (z2 == 0) { z2 = 1; }
	if (x1 == 0) { x1 = 1; }
	if (x2 == 0) { x2 = 1; }
	if (y1 == 0) { y1 = 1; }
	if (y2 == 0) { y2 = 1; }
	SDL_GetWindowSize(window, &w, &h);

	SDL_RenderDrawLine(render, w / 2 + (x1/z1), h / 2 - (y1 / z1), w / 2 + (x2 / z2), h / 2 - (y1 / z1));
	SDL_RenderDrawLine(render, w / 2 + (x1 / z1), h / 2 - (y1 / z1) , w / 2 + (x1 / z1), h / 2 - (y2 / z2));
	SDL_RenderDrawLine(render, w / 2 + (x1 / z1), h / 2 - (y2 / z2), w / 2 + (x2 / z2), h / 2 - (y2 / z2));
	SDL_RenderDrawLine(render, w / 2 + (x2 / z2), h / 2 - (y2/z2), w / 2 + (x2 / z2), h / 2 - (y1 / z1));
}

void circle2(SDL_Window* window, SDL_Renderer* render, float x, float y, float r)
{
	int w,h;

	if (x==0){x=1;}
	if (y==0){y=1;}
	if (r==0){r=1;}
	SDL_GetWindowSize(window,&w,&h);

	for (int i=0;i<360;i++)
	{
		float angle=i*(M_PI/180);
		float n_x=x*cos(angle);
		float n_y=y*sin(angle);
		SDL_RenderDrawPoint(render,w/2+(n_x*r),h/2-(n_y*r));	
	}
}