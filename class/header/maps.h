#pragma once
#include "..\..\define\Define.h"
class maps:public object
{
	String map[N];
	vector<vector<int>> sp;//spawn place. ��������� ����� ��� ��������� ����������
	Texture t1;
	Sprite s1;
	void testsp();//��������� �� ����� ���������� ����� ��� ��������� ����������
public:
	void draw(RenderWindow& wnd) override;
	char getTile(int i, int j);
	void lvl1();
	vector<vector<int>> getSP();
};