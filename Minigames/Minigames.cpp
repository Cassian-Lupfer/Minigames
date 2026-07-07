#include <raylib.h>
#include "EnumClasses.h"
#include "TitleMenu.h"
#include "SnakeGame.h"

float screenWidth = 1920;
float screenHeight = 1080;
bool close = false;
Scenes currentScene = Scenes::SNAKEGAME;

int main() {
	InitWindow(screenWidth, screenHeight, "Minigames");
	SetTargetFPS(60);

	// Load assets
	Font mainFont = LoadFontEx("assets/fonts/CalSans-Regular.ttf", 128, NULL, 0);
	
	// Instance scene classes
	TitleMenu titleMenu(currentScene, {screenWidth, screenHeight}, mainFont, close);
	SnakeGame snakeGame(currentScene, { screenWidth, screenHeight }, mainFont);

	while (!WindowShouldClose() && !close) {
		BeginDrawing();

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
