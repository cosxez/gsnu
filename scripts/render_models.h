struct Model
{
	const char* name;
	vector<Point> vertexes;
	vector<Vector> vectors;
	vector<Triangle> triangles;
};

struct Color 
{
	uint8_t red, green, blue;
};

void render3(SDL_Window* win, SDL_Renderer* ren, Model model, Color color, char axis, float angle, float offset_x, float offset_y, float offset_z)
{
	float ygl = angle * (M_PI / 180);

	if (axis == 0x01)
	{
		for (int i = 0; i < model.vertexes.size(); i++)
		{
			float n_x = model.vertexes[i].x * cos(ygl) - model.vertexes[i].z * sin(ygl);
			float n_z = model.vertexes[i].x * sin(ygl) + model.vertexes[i].z * cos(ygl);

			SDL_SetRenderDrawColor(ren,color.red,color.green,color.blue,255);
			point3(win, ren, n_x * 400 + offset_x, model.vertexes[i].y * 400 + offset_y, n_z + 1 + offset_z);
		}

		for (int i = 0; i < model.vectors.size(); i++)
		{
			float n_x1 = model.vectors[i].x1 * cos(ygl) - model.vectors[i].z1 * sin(ygl);
			float n_z1 = model.vectors[i].x1 * sin(ygl) + model.vectors[i].z1 * cos(ygl);
			float n_x2 = model.vectors[i].x2 * cos(ygl) - model.vectors[i].z2 * sin(ygl);
			float n_z2 = model.vectors[i].x2 * sin(ygl) + model.vectors[i].z2 * cos(ygl);

			SDL_SetRenderDrawColor(ren, color.red, color.green, color.blue, 255);
			vector3(win, ren, n_x1 * 400 + offset_x, model.vectors[i].y1 * 400 + offset_y, n_z1 + 1 + offset_z, n_x2 * 400 + offset_x, model.vectors[i].y2 * 400 + offset_y, n_z2 + 1 + offset_z);
		}

		for (int i = 0; i < model.triangles.size(); i++)
		{
			float n_x1 = model.triangles[i].x1 * cos(ygl) - model.triangles[i].z1 * sin(ygl);
			float n_z1 = model.triangles[i].x1 * sin(ygl) + model.triangles[i].z1 * cos(ygl);
			float n_x2 = model.triangles[i].x2 * cos(ygl) - model.triangles[i].z2 * sin(ygl);
			float n_z2 = model.triangles[i].x2 * sin(ygl) + model.triangles[i].z2 * cos(ygl);
			float n_x3 = model.triangles[i].x3 * cos(ygl) - model.triangles[i].z3 * sin(ygl);
			float n_z3 = model.triangles[i].x3 * sin(ygl) + model.triangles[i].z3 * cos(ygl);

			SDL_SetRenderDrawColor(ren, color.red, color.green, color.blue, 255);
			triangle3(win, ren, n_x1 * 400 + offset_x, model.triangles[i].y1 * 400 + offset_y, n_z1 + 1 + offset_z, n_x2 * 400 + offset_x, model.triangles[i].y2 * 400 + offset_y, n_z2 + 1 + offset_z, n_x3 * 400 + offset_x, model.triangles[i].y3 * 400 + offset_y, n_z3 + 1 + offset_z);
		}
	}

	if (axis == 0x02)
	{
		for (int i = 0; i < model.vertexes.size(); i++)
		{
			float n_y = model.vertexes[i].y * sin(ygl) + model.vertexes[i].z * cos(ygl);
			float n_z = model.vertexes[i].y * cos(ygl) + model.vertexes[i].z * sin(ygl);

			SDL_SetRenderDrawColor(ren, color.red, color.green, color.blue, 255);
			point3(win, ren, model.vertexes[i].x * 400 + offset_x, n_y * 400 + offset_y, n_z + 1 + offset_z);
		}

		for (int i = 0; i < model.vectors.size(); i++)
		{
			float n_y1 = model.vectors[i].y1 * sin(ygl) + model.vectors[i].z1 * cos(ygl);
			float n_z1 = model.vectors[i].y1 * cos(ygl) + model.vectors[i].z1 * sin(ygl);
			float n_y2 = model.vectors[i].y2 * sin(ygl) + model.vectors[i].z2 * cos(ygl);
			float n_z2 = model.vectors[i].y2 * cos(ygl) + model.vectors[i].z2 * sin(ygl);

			SDL_SetRenderDrawColor(ren, color.red, color.green, color.blue, 255);
			vector3(win, ren, model.vectors[i].x1 * 400 + offset_x, n_y1 * 400 + offset_y, n_z1 + 1 + offset_z, model.vectors[i].x2 * 400 + offset_x, n_y2 * 400 + offset_y, n_z2 + 1 + offset_z);
		}

		for (int i = 0; i < model.triangles.size(); i++)
		{
			float n_y1 = model.triangles[i].y1 * sin(ygl) + model.triangles[i].z1 * cos(ygl);
			float n_z1 = model.triangles[i].y1 * cos(ygl) + model.triangles[i].z1 * sin(ygl);
			float n_y2 = model.triangles[i].y2 * sin(ygl) + model.triangles[i].z2 * cos(ygl);
			float n_z2 = model.triangles[i].x2 * cos(ygl) + model.triangles[i].z2 * sin(ygl);
			float n_y3 = model.triangles[i].y3 * sin(ygl) + model.triangles[i].z3 * cos(ygl);
			float n_z3 = model.triangles[i].y3 * cos(ygl) + model.triangles[i].z3 * sin(ygl);

			SDL_SetRenderDrawColor(ren, color.red, color.green, color.blue, 255);
			triangle3(win, ren, model.triangles[i].x1 * 400 + offset_x, n_y1 * 400 + offset_y, n_z1 + 1 + offset_z, model.triangles[i].x2 * 400 + offset_x, n_y2 * 400 + offset_y, n_z2 + 1 + offset_z, model.triangles[i].x3 * 400 + offset_x, n_y3 * 400 + offset_y, n_z3 + 1 + offset_z);
		}
	}

}