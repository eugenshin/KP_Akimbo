#pragma once
#pragma warning(disable : 4996)

#include <iostream>
#include <fstream>
#include <memory>
#include <cmath>
#include <list>
#include <vector>
#include <algorithm>
#include <thread>
#include <functional>

#include <SFML\Graphics.hpp>

using namespace sf;
using namespace std;


const int TS = 64;//tile size
const int Width = 960, Height = 960;//window size
const int N = 15;//width and height in tiles on map

#include "..\class/header/object.h"
#include "..\class/header/maps.h"
#include "..\class/header/bullet.h"
#include "..\class/header/enemy.h"
#include "..\class/header/hero.h"
#include "..\class/header/button.h"
#include "..\class/header/game_menu.h"

#define TILE0 "src/TILE0.png"
#define TILE1 "src/TILE1.png"
#define PLUS "src/plus.png"
#define HEROFILE "src/hero.png"
#define ENEMYFILE "src/enemy.png"
#define BULLETFILE "src/bullet.png"
#define FONT "src/font.ttf"