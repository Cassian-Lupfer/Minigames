#ifndef ASTEROIDSGAME_H_
#define ASTEROIDSGAME_H_

#include <raylib.h>
#include "../EnumClasses.h"
#include "Spaceship.h"

class AsteroidsGame {
private:
	Scenes& currentScene;
	Vector2 windowSize;
	Font font;

	Spaceship spaceship;
	
	bool isShooting = false;
public:
	AsteroidsGame(Scenes& pCurrentScene, Vector2 pWindowSize, Font pFont);
	void update();
	void updateInput();
	void draw();
};

#endif
