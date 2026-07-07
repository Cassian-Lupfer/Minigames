#include "TitleMenu.h"

TitleMenu::TitleMenu(Vector2 pWindowSize, Font pFont, bool& pClose)
	: close(pClose),
	playButton({ 80, 500 }, { 200, 100 }, WHITE, "Play", pFont),
	exitButton({ 80, 700 }, { 200, 100 }, WHITE, "Exit", pFont),
	backButton({ pWindowSize.x - 280, 80 }, { 200, 100 }, WHITE, "Back", pFont),
	snakePlayButton({ pWindowSize.x / 2 - 200, pWindowSize.y / 2 - 50 }, { 400, 100 }, WHITE, "Play Snakes", pFont)
{
	windowSize = pWindowSize;
	font = pFont;
}

void TitleMenu::update() {
	draw();
	checkInteraction();
}

void TitleMenu::draw() {
	// Clear and draw
	ClearBackground(purple);
	if (currentMode == Modes::TITLE) {
		DrawTextEx(font, "Welcome to\nMINIGAMES!", { 80, 80 }, 150, 0, WHITE);
		playButton.draw();
		exitButton.draw();
	}
	else if (currentMode == Modes::SELECTION) {
		backButton.draw();
		snakePlayButton.draw();
	}
}

void TitleMenu::checkInteraction() {
	// Check button press
	if (currentMode == Modes::TITLE) {
		if (playButton.isPressed()) {
			currentMode = Modes::SELECTION;
		}
		if (exitButton.isPressed()) {
			close = true;
		}
	}
	else if (currentMode == Modes::SELECTION) {
		if (backButton.isPressed()) {
			currentMode = Modes::TITLE;
		}
		if (snakePlayButton.isPressed()) {
			playSnake = true;
		}
	}
}

bool TitleMenu::getSnakeButtonState() {
	return playSnake;
}
