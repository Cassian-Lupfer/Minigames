#pragma once
#include <raylib.h>

class Button {
private:
	Vector2 position;
	const char* name;
	int width;
	int height;
	Color color;
	Font font;

public:
	Button(Vector2 pPosition, const char* pName, int pWidth, int pHeight, Color pColor, Font pFont);

	void draw();

};
