void ReadToModel(string path, Model& model, const char* name)
{
	ifstream file(path);
	if (!file.is_open()) { cout << "File was not opened"; }

	model.name = name;
	Vector vecC;
	Point pointC;
	Triangle trgC;

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
						if (cht == 8) { trgC.z3 = chi; model.triangles.push_back(trgC); }
					}

					if (line[0] == 'p')
					{
						if (cht == 0) { pointC.x = chi; }
						if (cht == 1) { pointC.y = chi; }
						if (cht == 2) { pointC.z = chi; model.vertexes.push_back(pointC); }
					}

					if (line[0] == 'v')
					{
						if (cht == 0) { vecC.x1 = chi; }
						if (cht == 1) { vecC.y1 = chi; }
						if (cht == 2) { vecC.z1 = chi; }
						if (cht == 3) { vecC.x2 = chi; }
						if (cht == 4) { vecC.y2 = chi; }
						if (cht == 5) { vecC.z2 = chi; model.vectors.push_back(vecC); }
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
}