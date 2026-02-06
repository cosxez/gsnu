struct EventMouse
{
	char event;
	char *constant;
	char endform;
};

void buttonUI(SDL_Window* window, SDL_Renderer* render, SDL_Event event, EventMouse& EMouse, float x1, float y1, float x2, float y2)
{
	int w, h;
	SDL_GetWindowSize(window, &w, &h);
	int mx = event.button.x;
	int my = event.button.y;

	SDL_RenderDrawLine(render, w / 2 + x1, h / 2 - y1 , w / 2 + x2 , h / 2 - y1 );
	SDL_RenderDrawLine(render, w / 2 + x1 , h / 2 - y1 , w / 2 + x1 , h / 2 - y2 );
	SDL_RenderDrawLine(render, w / 2 + x1 , h / 2 - y2 , w / 2 + x2 , h / 2 - y2 );
	SDL_RenderDrawLine(render, w / 2 + x2 , h / 2 - y2 , w / 2 + x2 , h / 2 - y1 );

	if (-w / 2 + mx <= x1 && -w / 2 + mx >= x2 && h / 2 - my >= y1 && h / 2 - my <= y2 || -w / 2 + mx <= x2 && -w / 2 + mx >= x1 && h / 2 - my <= y2 && h / 2 - my >= y1)
	{
		SDL_PollEvent(&event);
		if (event.button.button == EMouse.event)
		{
			*EMouse.constant = EMouse.endform;
		}
	}
}