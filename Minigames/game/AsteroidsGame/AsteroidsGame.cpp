#include "AsteroidsGame.h"

AsteroidsGame::AsteroidsGame(Scenes& pCurrentScene, Vector2 pWindowSize, Font pFont)
	: currentScene(pCurrentScene)
{
	windowSize = pWindowSize;
	font = pFont;
}

void AsteroidsGame::update() {
	draw();

	if (IsKeyPressed(KEY_E)) {
		currentScene = Scenes::TITLEMENU;
	}
}

void AsteroidsGame::draw() {
	ClearBackground(BLACK);
}
