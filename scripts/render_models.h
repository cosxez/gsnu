void render3(SDL_Window* win, SDL_Renderer* ren, vector<Point> ver, vector<Vector> vecs, vector<Triangle> trgs,char axis, float angle, float offset_x, float offset_y, float offset_z)
{
	float ygl = angle * (M_PI / 180);

	if (axis == 0x01)
	{
		for (int i = 0; i < ver.size(); i++)
		{
			float n_x = ver[i].x * cos(ygl) - ver[i].z * sin(ygl);
			float n_z = ver[i].x * sin(ygl) + ver[i].z * cos(ygl);

			point3(win, ren, n_x * 400 + offset_x, ver[i].y * 400 + offset_y, n_z + 1 + offset_z);
		}

		for (int i = 0; i < vecs.size(); i++)
		{
			float n_x1 = vecs[i].x1 * cos(ygl) - vecs[i].z1 * sin(ygl);
			float n_z1 = vecs[i].x1 * sin(ygl) + vecs[i].z1 * cos(ygl);
			float n_x2 = vecs[i].x2 * cos(ygl) - vecs[i].z2 * sin(ygl);
			float n_z2 = vecs[i].x2 * sin(ygl) + vecs[i].z2 * cos(ygl);

			vector3(win, ren, n_x1 * 400 + offset_x, vecs[i].y1 * 400 + offset_y, n_z1 + 1 + offset_z, n_x2 * 400 + offset_x, vecs[i].y2 * 400 + offset_y, n_z2 + 1 + offset_z);
		}

		for (int i = 0; i < trgs.size(); i++)
		{
			float n_x1 = trgs[i].x1 * cos(ygl) - trgs[i].z1 * sin(ygl);
			float n_z1 = trgs[i].x1 * sin(ygl) + trgs[i].z1 * cos(ygl);
			float n_x2 = trgs[i].x2 * cos(ygl) - trgs[i].z2 * sin(ygl);
			float n_z2 = trgs[i].x2 * sin(ygl) + trgs[i].z2 * cos(ygl);
			float n_x3 = trgs[i].x3 * cos(ygl) - trgs[i].z3 * sin(ygl);
			float n_z3 = trgs[i].x3 * sin(ygl) + trgs[i].z3 * cos(ygl);

			triangle3(win, ren, n_x1 * 400 + offset_x, trgs[i].y1 * 400 + offset_y, n_z1 + 1 + offset_z, n_x2 * 400, trgs[i].y2 * 400 + offset_y, n_z2 + 1 + offset_z, n_x3 * 400 + offset_x, trgs[i].y3 * 400 + offset_y, n_z3 + 1 + offset_z);
		}
	}

	if (axis == 0x02)
	{
		for (int i = 0; i < ver.size(); i++)
		{
			float n_y = ver[i].y * sin(ygl) + ver[i].z * cos(ygl);
			float n_z = ver[i].y * cos(ygl) + ver[i].z * sin(ygl);

			point3(win, ren, ver[i].x * 400 + offset_x, n_y * 400 + offset_y, n_z + 1 + offset_z);
		}

		for (int i = 0; i < vecs.size(); i++)
		{
			float n_y1 = vecs[i].y1 * sin(ygl) + vecs[i].z1 * cos(ygl);
			float n_z1 = vecs[i].y1 * cos(ygl) + vecs[i].z1 * sin(ygl);
			float n_y2 = vecs[i].y2 * sin(ygl) + vecs[i].z2 * cos(ygl);
			float n_z2 = vecs[i].y2 * cos(ygl) + vecs[i].z2 * sin(ygl);

			vector3(win, ren, vecs[i].x1 * 400 + offset_x, n_y1 * 400 + offset_y, n_z1 + 1 + offset_z, vecs[i].x2 * 400 + offset_x, n_y2 * 400 + offset_y, n_z2 + 1 + offset_z);
		}

		for (int i = 0; i < trgs.size(); i++)
		{
			float n_y1 = trgs[i].y1 * sin(ygl) + trgs[i].z1 * cos(ygl);
			float n_z1 = trgs[i].y1 * cos(ygl) + trgs[i].z1 * sin(ygl);
			float n_y2 = trgs[i].y2 * sin(ygl) + trgs[i].z2 * cos(ygl);
			float n_z2 = trgs[i].x2 * cos(ygl) + trgs[i].z2 * sin(ygl);
			float n_y3 = trgs[i].y3 * sin(ygl) + trgs[i].z3 * cos(ygl);
			float n_z3 = trgs[i].y3 * cos(ygl) + trgs[i].z3 * sin(ygl);

			triangle3(win, ren, trgs[i].x1 * 400 + offset_x, n_y1 * 400 + offset_y, n_z1 + 1 + offset_z, trgs[i].x2 * 400, n_y2 * 400 + offset_y, n_z2 + 1 + offset_z, trgs[i].x3 * 400 + offset_x, n_y3 * 400 + offset_y, n_z3 + 1 + offset_z);
		}
	}
	
}