struct Vector2
{
	float x1,y1,x2,y2;
};

void DrawText(SDL_Window* window, SDL_Renderer* render, std::string name_font, uint8_t font_size, std::string text, float x, float y)
{
	std::ifstream file(name_font,std::ios::binary);
	if (!file.is_open()) {std::cout<<"File cannot be opened\n";}
	
	uint16_t c;
	Vector2 vC;
	std::vector<Vector2> chars;
	while (file.read(reinterpret_cast<char*>(&c),sizeof(c)))
	{
		if (c==0xAF10){file.read(reinterpret_cast<char*>(&vC),4 * sizeof(float));chars.push_back(vC);}
		if (c==0xAF11){file.read(reinterpret_cast<char*>(&vC),4*sizeof(float));chars.push_back(vC);}
		
	}
	file.close();

	for (int i=0;i<chars.size();i++)
	{
		vector2(window,render,chars[i].x1 * font_size + x,chars[i].y1 * font_size + y,chars[i].x2 * font_size + x,chars[i].y2 * font_size + y);
	}
}
