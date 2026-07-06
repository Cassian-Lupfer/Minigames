#include "TitleMenu.h"

TitleMenu::TitleMenu(Font pFont) {
	font = pFont;

	// Instance classes
	playButton = Button({ 80, 500 }, { 200, 100 }, WHITE, "Play", font);
	exitButton = Button({ 80, 700 }, { 200, 100 }, WHITE, "Exit", font);

}

void TitleMenu::draw() {
	// Clear and draw
	ClearBackground(purple);
	DrawTextEx(font, "Welcome to\nMINIGAMES!", { 80, 80 }, 150, 0, WHITE);
	if (playButton.has_value()) {
		playButton -> draw();
	}
	if (exitButton.has_value()) {
		exitButton -> draw();
	}

}
