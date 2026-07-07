#include "TitleMenu.h"

TitleMenu::TitleMenu(Font pFont)
	: playButton({ 80, 500 }, { 200, 100 }, WHITE, "Play", font),
	exitButton({ 80, 700 }, { 200, 100 }, WHITE, "Exit", font)
{
	font = pFont;

}

void TitleMenu::draw() {
	// Clear and draw
	ClearBackground(purple);
	DrawTextEx(font, "Welcome to\nMINIGAMES!", { 80, 80 }, 150, 0, WHITE);
	playButton.draw();
	exitButton.draw();

}
