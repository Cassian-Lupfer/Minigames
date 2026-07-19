#ifndef ASTEROIDSGAME_H_
#define ASTEROIDSGAME_H_

#include <raylib.h>
#include "../EnumClasses.h"

class AsteroidsGame {
private:
	Scenes& currentScene;
	Vector2 windowSize;
	Font font;
public:
	AsteroidsGame(Scenes& pCurrentScene, Vector2 pWindowSize, Font pFont);
	void update();
	void draw();
};

#endif
