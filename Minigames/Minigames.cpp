#include <iostream>
#include <raylib.h>
#include "TitleMenu.h"
#include "SnakeGame.h"

float screenWidth = 1920;
float screenHeight = 1080;
bool close = false;
enum class Scenes {TITLEMENU, SNAKEGAME};
Scenes currentScene = Scenes::TITLEMENU;

int main() {
	InitWindow(screenWidth, screenHeight, "Minigames");
	SetTargetFPS(60);

	// Load assets
	Font mainFont = LoadFontEx("assets/fonts/CalSans-Regular.ttf", 128, NULL, 0);
	
	// Instance scene classes
	TitleMenu titleMenu({screenWidth, screenHeight}, mainFont, close);
	SnakeGame snakeGame({ screenWidth, screenHeight }, mainFont);

	while (!WindowShouldClose() && !close) {
		BeginDrawing();

		// Check SnakePlayButton of TitleMenu
		if (titleMenu.getSnakeButtonState()) {
			currentScene = Scenes::SNAKEGAME;
		}

		// Update scene class
		switch (currentScene) {
		case Scenes::TITLEMENU:
			titleMenu.update();
			break;
		case Scenes::SNAKEGAME:
			snakeGame.update();
			break;
		}
		
		EndDrawing();
	}

	// Unload assets
	UnloadFont(mainFont);

	CloseWindow();
	return 0;
}
