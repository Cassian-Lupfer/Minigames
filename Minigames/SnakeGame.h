#ifndef SNAKEGAME_H_
#define SNAKEGAME_H_

#include <vector>
#include <raylib.h>
#include "EnumClasses.h"

class SnakeGame {
private:
	Scenes& currentScene;
	Vector2 windowSize;
	Font font;

	// Array: Every game field cell aligned in one array
	int fieldWidth = 12;
	int fieldHeight = 12;
	int cellSize = 40;
	// If cell Index: 0 = nothing, 1 = snake body part, 2: snake head, 3: apple
	std::vector<int> gameField;
	// Array cell has cell index of body part position as value
	std::vector<int> snakeArray;

	enum class Direction { UP, DOWN, LEFT, RIGHT };
	Direction currentDirection = Direction::RIGHT;
	float timer = 0.0;
	float movementDuration = 0.2;
	bool gameOver = false;
	int appleCellIndex;
	int score = 0;
public:
	SnakeGame(Scenes& pCurrentScene, Vector2 pWindowSize, Font pFont);
	void update();
	void draw();
	void reset();
	void setDirection();
	void updateSnake();
	bool checkBodyHit(int pCellIndex);
	void extendSnake();
	void setGameOver();
	void spawnApple();
	void checkAppleHit(int pCellIndex);
};

#endif
