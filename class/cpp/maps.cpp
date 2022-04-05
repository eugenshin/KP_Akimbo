#pragma once
#include "..\..\define\Define.h"
void maps::testsp()
{
	for (int i = 0; i < N; i++) {
		if (map[i][0] == '0') {
			sp.push_back({ -1, i });
		}
		if (map[0][i] == '0') {
			sp.push_back({ i, -1 });
		}
		if (map[i][N - 1] == '0') {
			sp.push_back({ N, i });
		}
		if (map[N - 1][i] == '0') {
			sp.push_back({ i, N });
		}
	}
}

void maps::draw(RenderWindow& wnd)
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			s.setPosition(i * TS, j * TS);
			wnd.draw(s);
			switch (map[j][i]) {
			case '1':
				s1.setPosition(i*TS, j*TS);
				wnd.draw(s1);
				break;
			}
		}
	}
}

char maps::getTile(int i, int j)
{
	if ((i < 0) || (i >= N) || (j < 0) || (j >= N))
		return '1';
	return map[j][i];
}

void maps::lvl1()
{
	map[0] =  "111111000111111";
	map[1] =  "100000000000001";
	map[2] =  "100000000000001";
	map[3] =  "100000111000001";
	map[4] =  "100000000000001";
	map[5] =  "100000000000001";
	map[6] =  "000100010001000";
	map[7] =  "000100111001000";
	map[8] =  "000100010001000";
	map[9] =  "100000000000001";
	map[10] = "100000000000001";
	map[11] = "100000111000001";
	map[12] = "100000000000001";
	map[13] = "100000000000001";
	map[14] = "111111000111111";
	t.loadFromFile(TILE0);
	s.setTexture(t);
	s.setScale((float)TS / t.getSize().x, (float)TS / t.getSize().y);//скалирование размера под требуемое
	t1.loadFromFile(TILE1);
	s1.setTexture(t1);
	s1.setScale((float)TS / t1.getSize().x, (float)TS / t1.getSize().y);//скалирование размера под требуемое
	testsp();
}

vector<vector<int>> maps::getSP()
{
	return sp;
}