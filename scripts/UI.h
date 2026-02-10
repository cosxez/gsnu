struct EventMouse
{
	char event;
	char *constant;
	char endform;
};

void buttonUI(SDL_Renderer* render, SDL_Event event, EventMouse& EMouse, float x1, float y1, float x2, float y2)
{
	int mx,my;
	SDL_GetMouseState(&mx,&my);
	
	SDL_RenderDrawLine(render, x1, y1 , x2 , y1 );
	SDL_RenderDrawLine(render, x1 , y1 , x1 , y2 );
	SDL_RenderDrawLine(render, x1 , y2 , x2 , y2 );
	SDL_RenderDrawLine(render, x2 , y2 , x2 , y1 );
	
	if (mx <= x1 && mx >= x2 && my >= y1 && my <= y2 || mx <= x2 && mx >= x1 && my <= y2 && my >= y1)
	{	
		SDL_PollEvent(&event);
		
		if (event.button.button == EMouse.event)
		{
			*EMouse.constant = EMouse.endform;
		}	
	}
}
