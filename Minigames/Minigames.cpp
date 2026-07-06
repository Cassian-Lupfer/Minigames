#include <iostream>
#include <raylib.h>
#include "TitleMenu.h"

int screenWidth = 1920;
int screenHeight = 1080;

int main() {
	InitWindow(screenWidth, screenHeight, "Minigames");
	SetTargetFPS(60);

	// Load assets
	Font mainFont = LoadFontEx("assets/fonts/CalSans-Regular.ttf", 128, NULL, 0);
	
	// Instance classes
	TitleMenu titleMenu(mainFont);

	while (WindowShouldClose() == false) {
		BeginDrawing();

		// Draw
		titleMenu.draw();

		EndDrawing();
	}

	// Unload assets
	UnloadFont(mainFont);

	CloseWindow();
	return 0;
}
