#pragma once
#include "..\..\define\Define.h"

class hero
{
	int *sp;//skill points
	const float DAT = 800,//default attack time
		DBS = 0.0003,//default bullet speed
		DMS = 0.0001,//default move speed
		DHP = 3;//default health points
	float at = DAT,//attack time
		bs = DBS,//bullet speed
		ms = DMS,//move speed
		hp = DHP;//health points
	Texture t;//hero texture
	Sprite s;//hero sprite
	Clock clock;//shooting timer
public:
	int* getSP();
	hero(int x, int y);
	void setpos(int x, int y);
	Sprite getS();
	void move(float time, maps level);
	bool shooting(vector<bullet>* bts);
	void rescale();
};