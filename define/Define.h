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

using namespace std;
using namespace sf;