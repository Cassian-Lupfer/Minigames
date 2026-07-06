#include "Button.h"

Button::Button(Vector2 pPosition, Vector2 pSize, Color pColor, const char* pName, Font pFont) {
	position = pPosition;
	size = pSize;
	color = pColor;
	name = pName;
	font = pFont;

	rec = Rectangle{position.x, position.y, size.x, size.y};
}

void Button::draw() {
	DrawRectangle(position.x, position.y, size.x, size.y, color);
	DrawTextEx(font, name, { position.x + 20, position.y + (size.y / 2) - 40}, 80, 0, BLACK);
}

bool Button::isPressed() {
	Vector2 mousePosition = GetMousePosition();
	return CheckCollisionPointRec(mousePosition, rec);
}
