#include <iostream>
#include <raylib.h>

int screenWidth = 1920;
int screenHeight = 1080;

int main() {
	InitWindow(screenWidth, screenHeight, "Minigames");
	SetTargetFPS(60);

	// Load assets
	Font mainFont = LoadFontEx("assets/fonts/Nunito-VariableFont_wght.ttf", 32, NULL, 0);

	while (WindowShouldClose() == false) {
		BeginDrawing();

		// Clear and drawing
		ClearBackground(BLACK);
		DrawTextEx(mainFont, "Welcome to\nMINIGAMES!", { 80, 80 }, 100, 16, WHITE);

		EndDrawing();
	}

	// Unloading assets
	UnloadFont(mainFont);

	CloseWindow();
	return 0;
}
