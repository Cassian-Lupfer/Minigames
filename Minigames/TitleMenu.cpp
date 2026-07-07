#include "TitleMenu.h"

TitleMenu::TitleMenu(Font pFont, bool& pClose)
	: close(pClose),
	playButton({ 80, 500 }, { 200, 100 }, WHITE, "Play", pFont),
	exitButton({ 80, 700 }, { 200, 100 }, WHITE, "Exit", pFont)
{
	font = pFont;
}

void TitleMenu::update() {
	draw();
	checkInteraction();
}

void TitleMenu::draw() {
	// Clear and draw
	ClearBackground(purple);
	DrawTextEx(font, "Welcome to\nMINIGAMES!", { 80, 80 }, 150, 0, WHITE);
	playButton.draw();
	exitButton.draw();
}

void TitleMenu::checkInteraction() {
	// Check button press
	if (playButton.isPressed()) {

	}
	if (exitButton.isPressed()) {
		close = true;
	}
}
