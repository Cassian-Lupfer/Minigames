#ifndef SNAKEGAME_H_
#define SNAKEGAME_H_

#include <vector>
#include <raylib.h>
#include "../EnumClasses.h"

class SnakeGame {
private:
	Scenes& currentScene;
	Vector2 windowSize;
	Font font;
	Texture2D cellTexture;
	Texture2D headTexture;
	Texture2D bodyTexture;
	Texture2D appleTexture;

	const Color backgroundColor = GetColor(0x3b1443FF);

	// Array: Every game field cell aligned in one array
	const int fieldWidth = 12;
	const int fieldHeight = 12;
	const int cellSize = 64;
	/* If cell Index : 0 = nothing, 1 = body, 2 = head up, 3 = head down,
	4 = head left, 5 = head right, 6 = apple */
	std::vector<int> gameField;
	// Array cell has cell index of body part position as value
	std::vector<int> snakeArray;

	const enum class Direction { UP, DOWN, LEFT, RIGHT };
	Direction currentDirection = Direction::RIGHT;
	float timer = 0.0;
	float movementDuration = 0.2;
	bool gameOver = false;
	int appleCellIndex;
	int score = 0;
public:
	SnakeGame(Scenes& pCurrentScene, Vector2 pWindowSize, Font pFont, Texture2D pCellTexture, Texture2D pHeadTexture, Texture2D pBodyTexture, Texture2D pAppleTexture);
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
