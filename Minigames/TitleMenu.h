#ifndef TITLEMENU_H_
#define TITLEMENU_H_

#include <raylib.h>
#include "Button.h"

class TitleMenu {
private:
	Vector2 windowSize;
	Font font;
	bool& close;
	Color purple = GetColor(0x3003d9FF);
	Button playButton;
	Button exitButton;
	Button backButton;
	Button snakePlayButton;
	enum class Modes {TITLE, SELECTION};
	Modes currentMode = Modes::TITLE;
	bool playSnake = false;
public:
	TitleMenu(Vector2 pWindowSize, Font pFont, bool& pClose);
	void update();
	void draw();
	void checkInteraction();
	bool getSnakeButtonState();
};

#endif
