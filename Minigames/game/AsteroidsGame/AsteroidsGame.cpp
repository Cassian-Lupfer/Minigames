#include "AsteroidsGame.h"

AsteroidsGame::AsteroidsGame(Scenes& pCurrentScene, Vector2 pWindowSize, Font pFont)
	: currentScene(pCurrentScene),
	spaceship({pWindowSize.x / 2, pWindowSize.y / 2 })
{
	windowSize = pWindowSize;
	font = pFont;
}

void AsteroidsGame::update() {
	spaceship.update();
	updateInput();
	draw();

	if (IsKeyPressed(KEY_E)) {
		currentScene = Scenes::TITLEMENU;
	}
}

void AsteroidsGame::updateInput() {
	if (IsKeyDown(KEY_SPACE)) {
		isShooting = true;
	}
	if (IsKeyDown(KEY_UP) && spaceship.velocity.y < spaceship.maxSpeed) {
		spaceship.velocity.y += spaceship.acceleration;
	}
	if (IsKeyDown(KEY_LEFT)) {
		spaceship.rotation -= spaceship.rotationSpeed;
	}
	if (IsKeyDown(KEY_RIGHT)) {
		spaceship.rotation += spaceship.rotationSpeed;
	}
}

void AsteroidsGame::draw() {
	ClearBackground(BLACK);
	
	spaceship.draw();
}
