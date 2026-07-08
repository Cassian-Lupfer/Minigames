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
	setDirection();
	updateSnake();
	draw();
}

void SnakeGame::draw() {
	ClearBackground(BLACK);
	for (int i = 0; i < fieldHeight; i++) {
		for (int j = 0; j < fieldWidth; j++) {
			int cellPosX = j * (cellSize + cellSize / 4);
			int cellPosY = i * (cellSize + cellSize / 4);
			int offsetX = (windowSize.x / 2) - (fieldWidth * cellSize + ((fieldWidth - 1) * (cellSize / 4))) / 2;
			int offsetY = (windowSize.y / 2) - (fieldHeight * cellSize + ((fieldHeight - 1) * (cellSize / 4))) / 2;
			DrawRectangle(cellPosX + offsetX, cellPosY + offsetY, cellSize, cellSize, WHITE);

			Vector2 cellCenterPos = { cellPosX + offsetX + (cellSize / 2), cellPosY + offsetY + (cellSize / 2) };
			int cellIndex = j + i * fieldHeight;
			if (gameField[cellIndex] == 0) {
				continue;
			}
			if (gameField[cellIndex] == 1) {
				DrawCircleV(cellCenterPos, 20, BLACK);
			}
			else if (gameField[cellIndex] == 2) {
				DrawCircleV(cellCenterPos, 20, GREEN);
			}
		}
	}
}

void SnakeGame::reset() {
	gameField[120] = 2;
	snakeArray.push_back(120);
	gameField[119] = 1;
	snakeArray.push_back(119);
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

		for (int i = 0; i < snakeArray.size(); i++) {
			//check direction and change position
			switch (currentDirection) {
			case Direction::UP:
				snakeArray[i] = snakeArray[i] - fieldWidth;
				break;
			case Direction::DOWN:
				snakeArray[i] = snakeArray[i] + fieldWidth;
				break;
			case Direction::RIGHT:
				snakeArray[i] = snakeArray[i] + 1;
				break;
			case Direction::LEFT:
				snakeArray[i] = snakeArray[i] - 1;
				break;
			}

			//check game field border
			

			// check if snake head, else if snake tail end and update game field
			if (i == 0) {
				gameField[snakeArray[i]] = 2;
			}
			else if (i == snakeArray.size() - 1) {
				gameField[snakeArray[i]] = 1;
				//check direction and delte body part
				switch (currentDirection) {
				case Direction::UP:
					gameField[snakeArray[i] - fieldWidth] = 0;
					break;
				case Direction::DOWN:
					gameField[snakeArray[i] + fieldWidth] = 0;
					break;
				case Direction::RIGHT:
					gameField[snakeArray[i] - 1] = 0;
					break;
				case Direction::LEFT:
					gameField[snakeArray[i] + 1] = 0;
					break;
				}
			}
			else {
				gameField[snakeArray[i]] = 1;
			}
		}
	}
}

void SnakeGame::extendSnake() {

}
