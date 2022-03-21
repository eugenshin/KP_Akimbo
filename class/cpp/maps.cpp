#pragma once
#include "..\..\define\Define.h"
void maps::draw(RenderWindow* wnd)
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			switch (map[j][i]) {
			case '1':
				s.setPosition(i*TS, j*TS);
				wnd->draw(s);
				break;
			}
		}
	}
}

char maps::getTile(int i, int j)
{
	return map[j][i];
}

void maps::lvl1()
{
	map[0] =  "111111000111111";
	map[1] =  "100000000000001";
	map[2] =  "100000010000001";
	map[3] =  "100000111000001";
	map[4] =  "100000010000001";
	map[5] =  "100000000000001";
	map[6] =  "000000000000000";
	map[7] =  "000000000000000";
	map[8] =  "000000000000000";
	map[9] =  "100000000000001";
	map[10] = "100000000000001";
	map[11] = "100000000000001";
	map[12] = "100000000000001";
	map[13] = "100000000000001";
	map[14] = "111111000111111";
	t.loadFromFile(TILE0);
	s.setTexture(t);
	s.setColor(Color(255,255,255,128));
}