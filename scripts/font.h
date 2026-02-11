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
		std::vector<uint16_t> regs = {0x0AF10,0x0AF11,0x0AF12,0x0AF13,0x0AF14,0x0AF15,0x0AF16,0x0AF17,0x0AF18,0x0AF19,0x0AF20,0x0AF21,0x0AF22,0x0AF23,0x0AF24,0x0AF25,0x0AF26,0x0AF27,0x0AF28,0x0AF29,0x0AF30,0x0AF31,0x0AF32,0x0AF33,0x0AF34,0x0AF35};
		std::vector<char> alphabet = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
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
