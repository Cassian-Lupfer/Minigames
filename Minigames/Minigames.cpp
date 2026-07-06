#include <iostream>
#include <raylib.h>
#include "Button.h"

int screenWidth = 1920;
int screenHeight = 1080;

Color purple = GetColor(0x3003d9FF);

int main() {
	InitWindow(screenWidth, screenHeight, "Minigames");
	SetTargetFPS(60);

	// Load assets
	Font mainFont = LoadFontEx("assets/fonts/CalSans-Regular.ttf", 128, NULL, 0);

	// Instance classes
	Button playButton({ 80, 500 }, "Play", 200, 100, WHITE, mainFont);
	Button exitButton({80, 700}, "Exit", 200, 100, WHITE, mainFont);

	while (WindowShouldClose() == false) {
		BeginDrawing();

		// Clear and drawing
		ClearBackground(purple);
		DrawTextEx(mainFont, "Welcome to\nMINIGAMES!", { 80, 80 }, 150, 0, WHITE);
		playButton.draw();
		exitButton.draw();

		EndDrawing();
	}

	// Unload assets
	UnloadFont(mainFont);

	CloseWindow();
	return 0;
}
