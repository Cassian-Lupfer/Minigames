#include <algorithm>
#include "SnakeGame.h"

SnakeGame::SnakeGame(Scenes& pCurrentScene, Vector2 pWindowSize, Font pFont, Texture2D pCellTexture, Texture2D pHeadTexture, Texture2D pBodyTexture)
	: currentScene(pCurrentScene),
	gameField(fieldWidth * fieldHeight, 0)
{
	windowSize = pWindowSize;
	font = pFont;
	cellTexture = pCellTexture;
	headTexture = pHeadTexture;
	bodyTexture = pBodyTexture;

	reset();
}

void SnakeGame::update() {
	if (!gameOver) {
		setDirection();
		updateSnake();
	}
	draw();

	if (IsKeyPressed(KEY_R)) {
		reset();
	}
	if (IsKeyPressed(KEY_E)) {
		currentScene = Scenes::TITLEMENU;
		reset();
	}
}

void SnakeGame::draw() {
	ClearBackground(BLACK);
	DrawTextEx(font, "Snake!", {windowSize.x / 2 - 100, 20}, 80, 0, WHITE);
	DrawTextEx(font, "Direction: [UP][DOWN][LEFT][RIGHT], Restart: [R], Exit: [E]", { 10, windowSize.y - 50 }, 40, 0, WHITE);
	DrawTextEx(font, TextFormat("FPS: %i", GetFPS()), { 10, 10}, 30, 0, WHITE);
	float offsetX = (windowSize.x / 2) - (fieldWidth * cellSize) / 2;
	float offsetY = (windowSize.y / 2) - (fieldHeight * cellSize) / 2;
	DrawTextEx(font, TextFormat("Score: %i", score), { offsetX, offsetY + (fieldHeight * cellSize) }, 60, 0, WHITE);
	for (int i = 0; i < fieldHeight; i++) {
		for (int j = 0; j < fieldWidth; j++) {
			Vector2 cellPos = { j * cellSize + offsetX, i * cellSize + offsetY};
			DrawTextureEx(cellTexture, cellPos, 0, 4, WHITE);

			int cellIndex = j + i * fieldHeight;
			if (gameField[cellIndex] == 0) {
				continue;
			}
			else if (gameField[cellIndex] == 1) {
				DrawTextureEx(bodyTexture, cellPos, 0, 4, WHITE);
			}
			else if (gameField[cellIndex] == 2) {
				DrawTextureEx(bodyTexture, cellPos, 0, 4, WHITE);
			}
			else if (gameField[cellIndex] == 3) {
				DrawTextureEx(bodyTexture, cellPos, 0, 4, WHITE);
			}
			else if (gameField[cellIndex] == 4) {
				DrawTextureEx(bodyTexture, cellPos, 0, 4, WHITE);
			}
			else if (gameField[cellIndex] == 5) {
				DrawTextureEx(headTexture, cellPos, 0, 4, WHITE);
			}
			else if (gameField[cellIndex] == 6) {
				DrawTextureEx(headTexture, cellPos, 0, 4, WHITE);
			}
			else if (gameField[cellIndex] == 7) {
				DrawTextureEx(headTexture, cellPos, 0, 4, WHITE);
			}
			else if (gameField[cellIndex] == 8) {
				DrawTextureEx(headTexture, cellPos, 0, 4, WHITE);
			}
			else if (gameField[cellIndex] == 9) {
				DrawCircleV(cellPos, 20, RED);
			}
		}
	}

	if (gameOver) {
		DrawTextEx(font, "Game Over!", { windowSize.x / 2 - 170, windowSize.y - 120}, 80, 0, RED);
	}
}

void SnakeGame::reset() {
	int headIndex = (fieldWidth / 2) + (fieldHeight * (fieldWidth / 2));
	snakeArray = { headIndex, headIndex - 1, headIndex - 2 };
	std::fill(gameField.begin(), gameField.end(), 0);
	gameField[headIndex] = 2;
	gameField[headIndex - 1] = 1;
	gameField[headIndex - 2] = 1;
	spawnApple();
	currentDirection = Direction::RIGHT;
	gameOver = false;
	score = 0;

	ClearBackground(BLACK);
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
						gameField[snakeArray[i]] = 5;
					}
					break;
				case Direction::DOWN:
					if (snakeArray[i] > fieldHeight * (fieldWidth - 1)) {
						setGameOver();
						return;
					}
					if (!checkBodyHit(snakeArray[i] + fieldWidth)) {
						snakeArray[i] = snakeArray[i] + fieldWidth;
						gameField[snakeArray[i]] = 6;
					}
					break;
				case Direction::LEFT:
					if ((snakeArray[i] % fieldWidth) == 0) {
						setGameOver();
						return;
					}
					if (!checkBodyHit(snakeArray[i] - 1)) {
						snakeArray[i] = snakeArray[i] - 1;
						gameField[snakeArray[i]] = 7;
					}
					break;
				case Direction::RIGHT:
					if ((snakeArray[i] % fieldWidth) == (fieldWidth - 1)) {
						setGameOver();
						return;
					}
					if (!checkBodyHit(snakeArray[i] + 1)) {
						snakeArray[i] = snakeArray[i] + 1;
						gameField[snakeArray[i]] = 8;
					}
					break;
				}
				checkAppleHit(snakeArray[i]);
			}
			else {
				if (i == snakeArray.size() - 1) {
					// delete current body part
					gameField[snakeArray[i]] = 0;
				}

				// get position of predecessor body part
				snakeArray[i] = snakeArray[i - 1];

				// set body part with specific direction
				switch (currentDirection) {
				case Direction::UP:
					gameField[snakeArray[i]] = 1;
					break;
				case Direction::DOWN:
					gameField[snakeArray[i]] = 2;
					break;
				case Direction::LEFT:
					gameField[snakeArray[i]] = 3;
					break;
				case Direction::RIGHT:
					gameField[snakeArray[i]] = 4;
					break;
				}
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
				break;
			}
			else if (i == snakeArray.size() - 1) {
				inSnake = false;
			}
		}
	} while (inSnake);
	
	gameField[appleCellIndex] = 9;
}

void SnakeGame::checkAppleHit(int pCellIndex) {
	if (appleCellIndex == pCellIndex) {
		score += 1;
		extendSnake();
		spawnApple();
	}
}
