#ifndef TITLEMENU_H_
#define TITLEMENU_H_

#include <raylib.h>
#include "Button.h"

class TitleMenu {
private:
	Color purple = GetColor(0x3003d9FF);
	Font font;
	Button playButton;
	Button exitButton;

public:
	TitleMenu(Font pFont);

	void draw();

};

#endif
