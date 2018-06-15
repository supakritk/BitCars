#include "Map.hpp"

int main()
{
	std::shared_ptr<Map> map = std::make_shared<Map>();
	map->drawMap();
	map->start();
	getchar();
}