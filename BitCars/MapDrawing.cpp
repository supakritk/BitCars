#include "MapDrawing.hpp"


MapDrawing::MapDrawing()
{
}


MapDrawing::~MapDrawing()
{
}

void MapDrawing::print(std::string text) {
	std::cout << text;
}

void MapDrawing::printl(std::string text) {
	std::cout << text << std::endl;
}

std::string MapDrawing::convertAllCharFromText(std::string text, char origin, char changed) {
	for (int i = 0; i < static_cast<int>(text.size()); i++) {
		if (text.at(i) == origin) {
			text.at(i) = changed;
		}
	}
	return text;
}