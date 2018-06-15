#include "Gameplay.hpp"



Gameplay::Gameplay()
{
}


Gameplay::~Gameplay()
{
}

void Gameplay::initialization(std::vector<std::string> &map) {
	this->setCurrentMap(map);
	this->addCar();
}

void Gameplay::playGame(const int& key_input) {
	if (key_input != NO_INPUT) {
		this->addCar();
	}
	this->moveAllCar();
}

float Gameplay::getTimeCriteria() {
	return GAMEPLAY_GAP;
}

void Gameplay::gotoxy(const SHORT& x, const SHORT& y)
{
	COORD p = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}

void Gameplay::setCurrentMap(std::vector<std::string> &map) {
	for (int i = 0; i < static_cast<int>(map.size()); i++) {
		currentmap.push_back(map[i]);
	}
}

void Gameplay::addCar() {
	cars.push_back(std::make_shared<Car>());
	for (int j = 0; j < static_cast<int>(currentmap.size()); j++) {
		for (int i = 0; i < static_cast<int>(currentmap[j].size()); i++) {
			if (currentmap[j].at(i) == EMPTY_SPACE) {
				if (this->hasNoOtherCar(car_amount, i, j)) {
					cars[car_amount]->setX(i);
					cars[car_amount]->setY(j);
					cars[car_amount]->setOldX(-1);
					cars[car_amount]->setOldY(-1);
					this->moveOneCar(i, j, i, j);
					car_amount++;
					return;
				}
			}
		}
	}
}

bool Gameplay::hasNoOtherCar(int mycar, int x, int y) {
	for (int i = 0; i < static_cast<int>(cars.size()); i++) {
		if (i != mycar) {
			if (x != cars[i]->getX()) {
				if (y != cars[i]->getY()) {
					return false;
				}
			}
		}
	}
	return true;
}

void Gameplay::moveAllCar() {
	for (int i = 0; i < static_cast<int>(cars.size()); i++) {
		int x = cars[i]->getX();
		int y = cars[i]->getY();

		if (combinedCondition(i, x + 1, y)) {
			this->moveOneCar(x, y, x + 1, y);
			cars[i]->setX(x + 1);
			cars[i]->setY(y);
		}
		else if (combinedCondition(i, x, y + 1)) {
			this->moveOneCar(x, y, x, y + 1);
			cars[i]->setX(x);
			cars[i]->setY(y + 1);
		}
		else if (combinedCondition(i, x - 1, y)) {
			this->moveOneCar(x, y, x - 1, y);
			cars[i]->setX(x - 1);
			cars[i]->setY(y);
		}
		else if (combinedCondition(i, x, y - 1)) {
			this->moveOneCar(x, y, x, y - 1);
			cars[i]->setX(x);
			cars[i]->setY(y - 1);
		}

		cars[i]->setOldX(x);
		cars[i]->setOldY(y);
	}
}

bool Gameplay::isReturn(int mycar, int x, int y) {
	if (x == cars[mycar]->getOldX()) {
		if (y == cars[mycar]->getOldY()) {
			return true;
		}
	}
	return false;
}

bool Gameplay::combinedCondition(int mycar, int x, int y) {
	if (currentmap[y].at(x) == EMPTY_SPACE) {
		if (hasNoOtherCar(mycar, x, y)) {
			if (!isReturn(mycar, x, y)) {
				return true;
			}
		}
	}
	return false;
}

void Gameplay::moveOneCar(int x1, int y1, int x2, int y2) {
	this->gotoxy(static_cast<SHORT>(x1), static_cast<SHORT>(y1));
	std::cout << SPACE;
	this->gotoxy(static_cast<SHORT>(x2), static_cast<SHORT>(y2));
	std::cout << CAR_ICON;
}