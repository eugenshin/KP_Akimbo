#pragma once
#include "..\..\define\Define.h"

enemy::enemy(vector<vector<int>> sp, int ls)
{
	ms = DMS * (1 + ls * 0.05);
	hp = DHP + ls;
	t.loadFromFile(ENEMYFILE);
	s.setTexture(t);
	//s.setColor(Color::Red);
	s.setScale((float)TS / t.getSize().x, (float)TS / t.getSize().y);//скалирование размера под требуемое
	int r = rand() % sp.size();
	px = sp[r][0];
	py = sp[r][1];
	if (px < 0)
		moving = 'r';
	if (px > N - 1)
		moving = 'l';
	if (py < 0)
		moving = 'd';
	if (py > N - 1)
		moving = 'u';
	s.setPosition(px * TS, py * TS);
}

void enemy::move(float time, maps level, Vector2f heropos)
{
	float move = ms * time;
	int ex = s.getPosition().x / TS + 0.5,
		ey = s.getPosition().y / TS + 0.5,
		hx = heropos.x / TS + 0.5,
		hy = heropos.y / TS + 0.5;
	if ((ex == hx) && (ey == hy))//если враг добрался до игрока
		return;
	switch (moving) {
	case 'l':
		if ((px - 1) * TS < s.getPosition().x) {
			s.move(-move, 0);
			return;
		}
		else
			px--;
		break;
	case 'r':
		if ((px + 1) * TS > s.getPosition().x) {
			s.move(move, 0);
			return;
		}
		else
			px++;
		break;
	case 'u':
		if ((py - 1) * TS < s.getPosition().y) {
			s.move(0, -move);
			return;
		}
		else
			py--;
		break;
	case 'd':
		if ((py + 1) * TS > s.getPosition().y) {
			s.move(0, move);
			return;
		}
		else
			py++;
		break;
	}
	s.setPosition(px * TS, py * TS);
	moving = route_building(level, ex, ey, hx, hy);
}

char enemy::route_building(maps level, int ex, int ey, int hx, int hy)
{
	vector<char> da[N][N];
	da[ex][ey].push_back('O');
	while (da[hx][hy].empty())
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				if (level.getTile(i, j) == '0') {
					if (i + 1 < N)
						if (!da[i + 1][j].empty())
							if ((da[i][j].size() > da[i + 1][j].size()) || (da[i][j].empty())) {
								da[i][j] = da[i + 1][j];
								da[i][j].push_back('l');
							}
					if (i > 0)
						if (!da[i - 1][j].empty())
							if ((da[i][j].size() > da[i - 1][j].size()) || (da[i][j].empty())) {
								da[i][j] = da[i - 1][j];
								da[i][j].push_back('r');
							}
					if (j + 1 < N)
						if (!da[i][j + 1].empty())
							if ((da[i][j].size() > da[i][j + 1].size()) || (da[i][j].empty())) {
								da[i][j] = da[i][j + 1];
								da[i][j].push_back('u');
							}
					if (j > 0)
						if (!da[i][j - 1].empty())
							if ((da[i][j].size() > da[i][j - 1].size()) || (da[i][j].empty())) {
								da[i][j] = da[i][j - 1];
								da[i][j].push_back('d');
							}
				}
	return da[hx][hy][1];
}

void enemy::draw(RenderWindow& wnd)
{
	s.setTexture(t);
	wnd.draw(s);
}

Vector2f enemy::getPos()
{
	return s.getPosition();
}

int enemy::hit(vector<bullet>* bts)
{
	for (int i = 0; i < (*bts).size(); i++) {
		int bx = (*bts)[i].getPos().x,
			by = (*bts)[i].getPos().y,
			ex = s.getPosition().x,
			ey = s.getPosition().y;
		int bs = (*bts)[i].getbs();
		if ((((bx > ex) && (bx < ex + TS)) || ((bx + bs > ex) && (bx + bs < ex + TS))) && (((by > ey) && (by < ey + TS)) || ((by + bs > ey) && (by + bs < ey + TS)))) {
			hp -= (*bts)[i].getdmg();
			return i;
		}
	}
	return -1;
}

bool enemy::isdead()
{
	if (!(hp > 0))
		return 1;
	return 0;
}