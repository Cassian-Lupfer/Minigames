#include <raylib.h>
#include <ResourceManager.h>
#include "EnumClasses.h"
#include "TitleMenu.h"
#include "SnakeGame/SnakeGame.h"

Canolu::ResourceManager resourceManager;
constexpr float screenWidth = 1920;
constexpr float screenHeight = 1080;
bool close = false;
Scenes currentScene = Scenes::SNAKEGAME;

void updateMusic(Music& pMusic, bool shouldPlay) {
	if (shouldPlay) {
		if (!IsMusicStreamPlaying(pMusic)) {
			PlayMusicStream(pMusic);
		}
		UpdateMusicStream(pMusic);
	}
	else {
		if (IsMusicStreamPlaying(pMusic)) {
			StopMusicStream(pMusic);
		}
	}
}

int main() {
	InitWindow(screenWidth, screenHeight, "Minigames");
	SetTargetFPS(120);
	InitAudioDevice();

	// Load assets
	Font mainFont = LoadFontEx("assets/fonts/CalSans-Regular.ttf", 128, NULL, 0);
	Texture2D cellTexture = resourceManager.loadTexture("assets/images/Snake Cell Texture.png");
	Texture2D headTexture = resourceManager.loadTexture("assets/images/Snake Head Texture.png");
	Texture2D bodyTexture = resourceManager.loadTexture("assets/images/Snake Body Texture.png");
	Texture2D appleTexture = resourceManager.loadTexture("assets/images/Apple Texture.png");
	Music titleMenuSoundtrack = resourceManager.loadMusic("assets/sounds/Menu Soundtrack.wav");
	
	// Instance scene classes
	TitleMenu titleMenu(currentScene, {screenWidth, screenHeight}, mainFont, close);
	SnakeGame snakeGame(currentScene, { screenWidth, screenHeight }, mainFont, cellTexture, headTexture, bodyTexture, appleTexture);

	while (!WindowShouldClose() && !close) {
		BeginDrawing();

		// Update scene class
		switch (currentScene) {
		case Scenes::TITLEMENU:
			titleMenu.update();
			updateMusic(titleMenuSoundtrack, true);
			break;
		case Scenes::SNAKEGAME:
			snakeGame.update();
			updateMusic(titleMenuSoundtrack, false);
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
