#include <iostream>
#include <raylib.h>

int screenWidth = 1920;
int screenHeight = 1080;

int main() {
	InitWindow(screenWidth, screenHeight, "Minigames");
	SetTargetFPS(60);

	while (WindowShouldClose() == false) {
		BeginDrawing();

		ClearBackground(BLACK);

		EndDrawing();
	}

	CloseWindow();
	return 0;
}
