#include "Button.h"

Button::Button(Vector2 pPosition, const char* pName, int pWidth, int pHeight, Color pColor, Font pFont) {
	position = pPosition;
	name = pName;
	width = pWidth,
	height = pHeight;
	color = pColor;
	font = pFont;
}

void Button::draw() {
	DrawRectangle(position.x, position.y, width, height, color);
	DrawTextEx(font, name, { position.x + (width / 2) - 60, position.y + (height / 2) - 40}, 80, 0, BLACK);
}
