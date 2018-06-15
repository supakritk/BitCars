#pragma once
#include <iostream>
#include <memory>
#include <vector>

#include "GameEngine.hpp"
#include "Gameplay.hpp"

class Map
{
private:
	std::shared_ptr<GameEngine> gameengine;
	std::vector<std::string> mapdata;
	std::shared_ptr<Gameplay> gameplay;
public:
	Map();
	~Map();
	void drawMap();
	void start();
};

