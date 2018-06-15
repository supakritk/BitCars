#pragma once
#include <iostream>
#include <string>

class MapDrawing
{
public:
	MapDrawing();
	~MapDrawing();
	void print(std::string text);
	void printl(std::string text);
	std::string convertAllCharFromText(std::string text, char origin, char changed);
};

