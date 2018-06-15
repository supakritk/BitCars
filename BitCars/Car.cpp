#include "Car.hpp"

Car::Car()
{
}


Car::~Car()
{
}

void Car::setX(int locx) {
	x = locx;
}

void Car::setY(int locy) {
	y = locy;
}

int Car::getX() {
	return x;
}

int Car::getY() {
	return y;
}

void Car::setOldX(int locx) {
	oldx = locx;
}

void Car::setOldY(int locy) {
	oldy = locy;
}

int Car::getOldX() {
	return oldx;
}

int Car::getOldY() {
	return oldy;
}

void Car::setProperties() {

}

int Car::getID() {
	return id;
}

int Car::getFuel() {
	return fuel;
}

std::string Car::getName() {
	return name;
}

std::string Car::getWheel() {
	return wheel;
}