#include <raylib.h>
#include <ResourceManager.h>
#include "EnumClasses.h"
#include "TitleMenu.h"
#include "SnakeGame/SnakeGame.h"
#include "AsteroidsGame/AsteroidsGame.h"

Canolu::ResourceManager resourceManager;
constexpr float screenWidth = 1920;
constexpr float screenHeight = 1080;
bool close = false;
Scenes currentScene = Scenes::TITLEMENU;

int main() {
	InitWindow(screenWidth, screenHeight, "Minigames");
	SetTargetFPS(120);
	InitAudioDevice();

	// Load assets
	Font mainFont = LoadFontEx("assets/fonts/CalSans-Regular.ttf", 128, NULL, 0);
	
	// Instance scene classes
	TitleMenu titleMenu(currentScene, {screenWidth, screenHeight}, mainFont, close);
	SnakeGame snakeGame(currentScene, { screenWidth, screenHeight }, mainFont);
	AsteroidsGame asteroidsGame(currentScene, { screenWidth, screenHeight }, mainFont);

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
		case Scenes::ASTEROIDSGAME:
			asteroidsGame.update();
			break;
		}
		
		EndDrawing();
	}

	// Unload assets
	UnloadFont(mainFont);
	resourceManager.unloadAllAssets();

	CloseAudioDevice();
	CloseWindow();
	return 0;
}
