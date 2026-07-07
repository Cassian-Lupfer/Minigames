#ifndef TITLEMENU_H_
#define TITLEMENU_H_

#include <raylib.h>
#include "Button.h"

class TitleMenu {
private:
	Font font;
	bool& close;
	Color purple = GetColor(0x3003d9FF);
	Button playButton;
	Button exitButton;
public:
	TitleMenu(Font pFont, bool& pClose);
	void update();
	void draw();
	void checkInteraction();
};

#endif
