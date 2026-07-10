#ifndef BUTTON_H_
#define BUTTON_H_

#include <raylib.h>

namespace Canolu {
	class Button {
	private:
		Vector2 position;
		Vector2 size;
		Color color;
		const char* name;
		Font font;

		Rectangle rec;
	public:
		Button(Vector2 pPosition, Vector2 pSize, Color pColor, const char* pName, Font pFont);
		void draw();
		bool isPressed();
	};
}

#endif
