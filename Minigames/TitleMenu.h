#pragma once
#include <optional>
#include <raylib.h>
#include "Button.h"

class TitleMenu {
private:
	Color purple = GetColor(0x3003d9FF);
	Font font;
	std::optional<Button> playButton;
	std::optional<Button> exitButton;

public:
	TitleMenu(Font pFont);

	void draw();

};
