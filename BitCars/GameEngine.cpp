#include "GameEngine.hpp"

GameEngine::GameEngine()
{
	screenPainter = std::make_shared<MapDrawing>();
}

GameEngine::~GameEngine()
{
}

void GameEngine::readConfigFileAndJsonOnly() {
	if (!filesystem_ptr) {
		filesystem_ptr = new FileSystem(TXT_FILENAME, JSON_FILENAME);
		readText = filesystem_ptr->getTextData();
	}
}

std::vector<std::string> GameEngine::getTxt() {
	return readText;
}

nlohmann::json GameEngine::getJson() {
	return filesystem_ptr->getJsonData();
}

void GameEngine::printMapFromData() {
	for (int i = 0; i < static_cast<int>(readText.size()); i++) {
		readText[i] = screenPainter->convertAllCharFromText(readText[i], TEXT_OBS, OBS_PATH);
		readText[i] = screenPainter->convertAllCharFromText(readText[i], TEXT_EMPTY, EMPTY_PATH);
		screenPainter->printl(readText[i]);
	}
}

void GameEngine::startClock() {
	initTime = Clock::now();
}

void GameEngine::runClock() {
	runTime = Clock::now();
}

float GameEngine::diffClock() {
	return static_cast<float>(std::chrono::duration_cast<elapsed_resolution>(runTime - initTime).count() / 1000.0);
}

int GameEngine::kbhitInput() {
	if (_kbhit()) {
		int input = _getch();
		return static_cast<char>(input);
	}
	return 0;
}

void GameEngine::clearScreen() {
	HANDLE                     hStdOut;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD                      count;
	DWORD                      cellCount;
	COORD                      homeCoords = { 0, 0 };

	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hStdOut == INVALID_HANDLE_VALUE) return;

	/* Get the number of cells in the current buffer */
	if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
	cellCount = csbi.dwSize.X *csbi.dwSize.Y;

	/* Fill the entire buffer with spaces */
	if (!FillConsoleOutputCharacter(
		hStdOut,
		(TCHAR) ' ',
		cellCount,
		homeCoords,
		&count
	)) return;

	/* Fill the entire buffer with the current colors and attributes */
	if (!FillConsoleOutputAttribute(
		hStdOut,
		csbi.wAttributes,
		cellCount,
		homeCoords,
		&count
	)) return;

	/* Move the cursor home */
	SetConsoleCursorPosition(hStdOut, homeCoords);
}