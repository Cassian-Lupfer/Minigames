#include "SnakeGame.h"

SnakeGame::SnakeGame(Scenes pCurrentScene, Vector2 pWindowSize, Font pFont)
	: currentScene(pCurrentScene),
	gameField(fieldWidth * fieldHeight, 0)
{
	windowSize = pWindowSize;
	font = pFont;

	reset();
}

void SnakeGame::update() {
	if (!gameOver) {
		setDirection();
		updateSnake();
	}
	draw();
}

void SnakeGame::draw() {
	ClearBackground(BLACK);
	DrawTextEx(font, "Snake!", {windowSize.x / 2 - 100, 20}, 80, 0, WHITE);
	DrawTextEx(font, TextFormat("FPS: %i", GetFPS()), { 10, windowSize.y - 40 }, 30, 0, WHITE);
	float offsetX = (windowSize.x / 2) - (fieldWidth * cellSize + ((fieldWidth - 1) * (cellSize / 4))) / 2;
	float offsetY = (windowSize.y / 2) - (fieldHeight * cellSize + ((fieldHeight - 1) * (cellSize / 4))) / 2;
	DrawTextEx(font, TextFormat("Score: %i", score), { offsetX, offsetY + (fieldHeight * cellSize + ((fieldHeight - 1) * (cellSize / 4))) }, 60, 0, WHITE);
	for (int i = 0; i < fieldHeight; i++) {
		for (int j = 0; j < fieldWidth; j++) {
			int cellPosX = j * (cellSize + cellSize / 4);
			int cellPosY = i * (cellSize + cellSize / 4);
			DrawRectangle(cellPosX + offsetX, cellPosY + offsetY, cellSize, cellSize, WHITE);

			Vector2 cellCenterPos = { cellPosX + offsetX + (cellSize / 2), cellPosY + offsetY + (cellSize / 2) };
			int cellIndex = j + i * fieldHeight;
			if (gameField[cellIndex] == 0) {
				continue;
			}
			else if (gameField[cellIndex] == 1) {
				DrawCircleV(cellCenterPos, 20, BLACK);
			}
			else if (gameField[cellIndex] == 2) {
				DrawCircleV(cellCenterPos, 20, GREEN);
			}
			else if (gameField[cellIndex] == 3) {
				DrawCircleV(cellCenterPos, 20, RED);
			}
		}
	}
}

void SnakeGame::reset() {
	int headIndex = (fieldWidth / 2) + (fieldHeight * (fieldWidth / 2));
	snakeArray = { headIndex, headIndex - 1, headIndex - 2 };
	gameField[headIndex] = 2;
	gameField[headIndex - 1] = 1;
	gameField[headIndex - 2] = 1;

	spawnApple();
}

void SnakeGame::setDirection() {
	if (IsKeyPressed(KEY_UP) && currentDirection != Direction::DOWN) {
		currentDirection = Direction::UP;
	}
	if (IsKeyPressed(KEY_DOWN) && currentDirection != Direction::UP) {
		currentDirection = Direction::DOWN;
	}
	if (IsKeyPressed(KEY_LEFT) && currentDirection != Direction::RIGHT) {
		currentDirection = Direction::LEFT;
	}
	if (IsKeyPressed(KEY_RIGHT) && currentDirection != Direction::LEFT) {
		currentDirection = Direction::RIGHT;
	}

	// test
	if (IsKeyPressed(KEY_E)) {
		extendSnake();
	}
}

void SnakeGame::updateSnake() {
	timer += GetFrameTime();
	if (timer >= movementDuration) {
		timer = 0.0;
		for (int i = snakeArray.size() - 1; i >= 0; i--) {
			// check if snake head, else if snake tail end and update snake array and game field
			if (i == 0) {
				// check direction and game field border and body hit and change position
				switch (currentDirection) {
				case Direction::UP:
					if (snakeArray[i] < fieldWidth) {
						setGameOver();
						return;
					}
					if (!checkBodyHit(snakeArray[i] - fieldWidth)) {
						snakeArray[i] = snakeArray[i] - fieldWidth;
					}
					break;
				case Direction::DOWN:
					if (snakeArray[i] > fieldHeight * (fieldWidth - 1)) {
						setGameOver();
						return;
					}
					if (!checkBodyHit(snakeArray[i] + fieldWidth)) {
						snakeArray[i] = snakeArray[i] + fieldWidth;
					}
					break;
				case Direction::RIGHT:
					if ((snakeArray[i] % fieldWidth) == (fieldWidth - 1)) {
						setGameOver();
						return;
					}
					if (!checkBodyHit(snakeArray[i] + 1)) {
						snakeArray[i] = snakeArray[i] + 1;
					}
					break;
				case Direction::LEFT:
					if ((snakeArray[i] % fieldWidth) == 0) {
						setGameOver();
						return;
					}
					if (!checkBodyHit(snakeArray[i] - 1)) {
						snakeArray[i] = snakeArray[i] - 1;
					}
					break;
				}
				gameField[snakeArray[i]] = 2;
				checkAppleHit(snakeArray[i]);
			}
			else if (i == snakeArray.size() - 1) {
				// delete current body part
				gameField[snakeArray[i]] = 0;

				// get position of predecessor body part
				snakeArray[i] = snakeArray[i - 1];
				gameField[snakeArray[i]] = 1;
			}
			else {
				// get position of predecessor body part
				snakeArray[i] = snakeArray[i - 1];
				gameField[snakeArray[i]] = 1;
			}
		}
	}
}

bool SnakeGame::checkBodyHit(int pCellIndex) {
	for (int i = 0; i < snakeArray.size(); i++) {
		if (snakeArray[i] == pCellIndex) {
			gameOver = true;
			return true;
		}
	}
	return false;
}

void SnakeGame::extendSnake() {
	snakeArray.push_back(snakeArray[snakeArray.size() - 1]);
}

void SnakeGame::setGameOver() {
	gameOver = true;
}

void SnakeGame::spawnApple() {
	bool inSnake = false;
	do {
		appleCellIndex = GetRandomValue(0, fieldWidth * fieldHeight - 1);
		for (int i = 0; i < snakeArray.size(); i++) {
			if (snakeArray[i] == appleCellIndex) {
				inSnake = true;
			}
			else {
				inSnake = false;
			}
		}
	} while (inSnake);
	
	gameField[appleCellIndex] = 3;
}

void SnakeGame::checkAppleHit(int pCellIndex) {
	if (appleCellIndex == pCellIndex) {
		score += 1;
		extendSnake();
		spawnApple();
	}
}
