#pragma once

#include <iostream>
#include <vector>
#include <memory>

#include <string>

#include <windows.h>

#include "Car.hpp"

class Gameplay
{
private:
	const float GAMEPLAY_GAP = 0.1;
	const int NO_INPUT = 0;
	const char EMPTY_SPACE = '1';
	const char SPACE = ' ';
	const char CAR_ICON = 'c';

	std::vector<std::shared_ptr<Car>> cars;
	std::vector<std::string> currentmap;
	int car_amount = 0;
public:
	Gameplay();
	~Gameplay();
	void initialization(std::vector<std::string> &map);
	void playGame(const int& key_input);
	float getTimeCriteria();
	void gotoxy(const SHORT& x, const SHORT& y);
	void setCurrentMap(std::vector<std::string> &map);
	void addCar();
	bool hasNoOtherCar(int mycar, int x, int y);
	void moveAllCar();
	bool isReturn(int mycar, int x, int y);
	bool combinedCondition(int mycar, int x, int y);
	void moveOneCar(int x1, int y1, int x2, int y2);
};

