#pragma once
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

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
#include <SFML\Audio.hpp>
#include <SFML\Network.hpp>

#include "..\class/header/hero.h"
#include "..\class/header/bullet.h"
#include "..\class/header/maps.h"
#include "..\class/header/game_menu.h"

const int TS = 64;//tile size
const int BS = 16;//bullet size
const int Width = 960, Height = 960;//window size

#define TILE0 "src/bb.png"
#define HEROFILE "src/hero.png"
#define BULLETFILE "src/bullet.png"