#include "Map.hpp"



Map::Map()
{
	gameengine = std::make_shared<GameEngine>();
	gameplay = std::make_shared<Gameplay>();
	gameengine->readConfigFileAndJsonOnly();
	mapdata = gameengine->getTxt();
}


Map::~Map()
{
}

void Map::drawMap() {
	gameengine->printMapFromData();
}

void Map::start() {
	gameengine->startClock();
	gameplay->initialization(mapdata);
	while (true) {
		gameengine->runClock();
		if (gameengine->diffClock() > gameplay->getTimeCriteria()) {
			gameengine->startClock();
			gameplay->playGame(gameengine->kbhitInput());
		}
	}
}