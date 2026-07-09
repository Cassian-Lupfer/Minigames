#ifndef TITLEMENU_H_
#define TITLEMENU_H_

#include <raylib.h>
#include "EnumClasses.h"
#include "Button.h"

class TitleMenu {
private:
	Scenes& currentScene;
	Vector2 windowSize;
	Font font;
	bool& close;
	const Color backgroundColor = GetColor(0x3003d9FF);
	Button playButton;
	Button exitButton;
	Button backButton;
	Button snakePlayButton;
	enum class Modes {TITLE, SELECTION};
	Modes currentMode = Modes::TITLE;
public:
	TitleMenu(Scenes& pCurrentScene, Vector2 pWindowSize, Font pFont, bool& pClose);
	void update();
	void draw();
	void checkInteraction();
};

#endif
