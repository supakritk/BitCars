#include "FileSystem.hpp"

FileSystem::FileSystem()
{
}


FileSystem::~FileSystem()
{
}

FileSystem::FileSystem(std::string textfilename, std::string jsonfilename)
{
	filename = textfilename;
	jsonname = jsonfilename;
	this->readTextFile();
	this->readJsonFile();
}

void FileSystem::readTextFile() {
	std::ifstream input(filename);
	std::string line;
	std::string token;

	while (getline(input, line)) {
		filedata.push_back(line);
	}
}

void FileSystem::readJsonFile() {
	std::ifstream ifs(jsonname);
	jsondata = nlohmann::json::parse(ifs);
}

std::vector<std::string> FileSystem::getTextData() {
	return filedata;
}

nlohmann::json FileSystem::getJsonData() {
	return jsondata.dump();
}