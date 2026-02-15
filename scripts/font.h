struct Vector2
{
	float x1,y1,x2,y2;
};

void DrawText(SDL_Window* window, SDL_Renderer* render, std::string name_font, uint8_t font_size, std::string text, float x, float y, uint8_t space = 4)
{
	std::ifstream file(name_font,std::ios::binary);
	if (!file.is_open()) {std::cout<<"File cannot be opened\n";}
	else
	{
		uint16_t c;
		Vector2 vC;
		std::vector<std::vector<Vector2>> chars;
		std::vector<uint16_t> regs = {0xAF10,0xAF11,0xAF12,0xAF13,0xAF14,0xAF15,0xAF16,0xAF17,0xAF18,0xAF19,0xAF20,0xAF21,0xAF22,0xAF23,0xAF24,0xAF25,0xAF26,0xAF27,0xAF28,0xAF29,0xAF30,0xAF31,0xAF32,0xAF33,0xAF34,0xAF35,0xAF36,0xAF37,0xAF38,0xAF39,0xAF40,0xAF41,0xAF42,0xAF43,0xAF44};
		std::vector<char> alphabet = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '/', '\"', '\'', ',', '.', '-', '_', '!', '?'};
		while (file.read(reinterpret_cast<char*>(&c), sizeof(c)))
		{
			for (int i = 0; i < regs.size(); i++)
			{
				if (c == regs[i])
				{
					std::vector<Vector2> ch;
					while (!file.eof())
					{
						file.read(reinterpret_cast<char*>(&vC), 4 * sizeof(float));
						ch.push_back(vC);
						file.read(reinterpret_cast<char*>(&c), sizeof(c));
						if (i+1 < regs.size() && c == regs[i + 1]) {  break;  }
					}
					chars.push_back(ch);
				}
			}
		}
		file.close();
		
		for (int i = 0; i < text.size(); i++)
		{
			for (int j = 0; j < alphabet.size(); j++)
			{
				if (text[i] == alphabet[j])
				{
					for (int g = 0; g < chars[j].size(); g++)
					{
						vector2(window,render,chars[j][g].x1 * font_size + x + (font_size * i*space + (chars[j][g].x2 + chars[j][g].x1)), chars[j][g].y1 * font_size + y, chars[j][g].x2 * font_size + x + (font_size * i*space + (chars[j][g].x2 + chars[j][g].x1)), chars[j][g].y2 * font_size + y);
					}
				}
			}
		}
	}
}
