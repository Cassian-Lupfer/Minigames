#include "SnakeGame.h"

SnakeGame::SnakeGame(Scenes pCurrentScene, Vector2 pWindowSize, Font pFont)
	: currentScene(pCurrentScene),
	gameField(fieldWidth * fieldHeight, 0)
{
	windowSize = pWindowSize;
	font = pFont;
}

void SnakeGame::update() {
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

			int cellIndex = j + (i - 1) * fieldHeight;
			DrawText("", cellPosX + offsetX, cellPosY + offsetY, 20, BLACK);
		}
	}
}
