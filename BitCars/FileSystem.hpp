#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

#include "json.hpp"

class FileSystem
{
	std::string filename;
	std::string jsonname;
	std::vector<std::string> filedata;
	nlohmann::json jsondata;

	FileSystem();
	void readTextFile();
	void readJsonFile();
public:
	~FileSystem();
	FileSystem(std::string textfilename, std::string jsonfilename);
	std::vector<std::string> getTextData();
	nlohmann::json getJsonData();
};
