void ReadToModel(std::string path, Model& model, const char* name)
{
	std::ifstream file(path, std::ios::binary);
	if (!file.is_open()) { std::cout << "File cannot be opened\n"; }

	model.name = name;
	Vector vecC;
	Point pointC;
	Triangle trgC;
	Bone boneC;

	uint32_t c;
	while (file.read(reinterpret_cast<char*>(&c), sizeof(c)))
	{
		if (c == 0xA1030)
		{
			file.seekg(sizeof(uint32_t) + static_cast<size_t>(file.tellg()), std::ios::beg);
			while (!file.eof())
			{
				file.read(reinterpret_cast<char*>(&c), sizeof(c));
				if (c == 0xA2040 || c == 0xA3050 || c == 0xA4060) { break; }
				file.read(reinterpret_cast<char*>(&pointC), 3 * sizeof(float));
				model.vertexes.push_back(pointC);
			}
		}
		if (c == 0xA2040)
		{
			file.seekg(sizeof(uint32_t) + static_cast<size_t>(file.tellg()), std::ios::beg);
			while (!file.eof())
			{
				file.read(reinterpret_cast<char*>(&c), sizeof(c));
				if (c == 0xA1030 || c == 0xA3050 || c == 0xA4060) { break; }
				file.read(reinterpret_cast<char*>(&vecC), 6 * sizeof(float));
				model.vectors.push_back(vecC);
			}
		}
		if (c == 0xA3050)
		{
			file.seekg(sizeof(uint32_t) + static_cast<size_t>(file.tellg()), std::ios::beg);
			while (!file.eof())
			{
				file.read(reinterpret_cast<char*>(&c), sizeof(c));
				if (c == 0xA2040 || c == 0xA1030 || c == 0xA4060) { break; }
				file.read(reinterpret_cast<char*>(&trgC), 9 * sizeof(float));
				model.triangles.push_back(trgC);
			}
		}
		if (c == 0xA4060)
		{
			file.seekg(sizeof(uint32_t) + static_cast<size_t>(file.tellg()), std::ios::beg);
			while (!file.eof())
			{
				file.read(reinterpret_cast<char*>(&c), sizeof(c));
				if (c == 0xA2040 || c == 0xA3050 || c == 0xA1030) { break; }
				file.read(reinterpret_cast<char*>(&boneC), 18 * sizeof(float));
				model.bones.push_back(boneC);
			}
		}
	}
	file.close();
}
