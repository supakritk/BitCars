#pragma once
#include <iostream>
#include <memory>
#include <vector>
#include <chrono>

#include <conio.h>
#include <windows.h>

#include "FileSystem.hpp"
#include "MapDrawing.hpp"
#include "json.hpp"

typedef std::chrono::high_resolution_clock Clock;
using elapsed_resolution = std::chrono::milliseconds;

class GameEngine
{
private:
	const std::string TXT_FILENAME = "config.txt";
	const std::string JSON_FILENAME = "cars.json";
	const char EMPTY_PATH = ' ';
	const char OBS_PATH = 'x';
	const char TEXT_EMPTY = '1';
	const char TEXT_OBS = '0';

	FileSystem *filesystem_ptr = 0;

	std::chrono::steady_clock::time_point initTime, runTime;
	std::shared_ptr<MapDrawing> screenPainter;
	std::vector<std::string> readText;
public:
	GameEngine();
	~GameEngine();
	void readConfigFileAndJsonOnly();
	std::vector<std::string> getTxt();
	nlohmann::json getJson();
	void printMapFromData();
	void startClock();
	void runClock();
	float diffClock();
	int kbhitInput();
	void clearScreen();
};

