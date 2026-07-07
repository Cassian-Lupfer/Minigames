#include <iostream>
#include <raylib.h>
#include "TitleMenu.h"

int screenWidth = 1920;
int screenHeight = 1080;

bool close = false;

int main() {
	InitWindow(screenWidth, screenHeight, "Minigames");
	SetTargetFPS(60);

	// Load assets
	Font mainFont = LoadFontEx("assets/fonts/CalSans-Regular.ttf", 128, NULL, 0);
	
	// Instance scene classes
	TitleMenu titleMenu(mainFont, close);

	while (!WindowShouldClose() && !close) {
		BeginDrawing();

		// Update scene class
		titleMenu.update();

		EndDrawing();
	}

	// Unload assets
	UnloadFont(mainFont);

	CloseWindow();
	return 0;
}
