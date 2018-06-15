#pragma once
#include <iostream>

class Car
{
private:
	int x, y;
	int oldx, oldy;
	std::string name;
	int id;
	int fuel;
	std::string wheel;
public:
	Car();
	~Car();
	void setX(int locx);
	void setY(int locy);
	int getX();
	int getY();
	void setProperties();
	int getID();
	int getFuel();
	std::string getName();
	std::string getWheel();
	void setOldX(int locx);
	void setOldY(int locy);
	int getOldY();
	int getOldX();
};

