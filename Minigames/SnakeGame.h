#ifndef SNAKEGAME_H_
#define SNAKEGAME_H_

#include <vector>
#include <raylib.h>
#include "EnumClasses.h"

class SnakeGame {
private:
	Scenes currentScene;
	Vector2 windowSize;
	Font font;

	// Array: Every game field cell aligned in one array
	int fieldWidth = 16;
	int fieldHeight = 16;
	int cellSize = 40;
	std::vector<int> gameField;
	/* Every array cell has cell index of one body part in game field.
	Head of snake is at array cell 0 */
	std::vector<int> snakeArray;
public:
	SnakeGame(Scenes pCurrentScene, Vector2 pWindowSize, Font pFont);
	void update();
	void draw();
};

#endif
