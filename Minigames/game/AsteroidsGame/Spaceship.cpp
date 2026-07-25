#include "Spaceship.h"

Spaceship::Spaceship(Vector2 pPosition) {
	position = pPosition;
	image = resourceManager.loadTexture("assets/images/Spaceship Texture.png");
}

void Spaceship::update() {
	position.x += velocity.x;
	position.y += velocity.y;
}

void Spaceship::draw() {
	Rectangle source = {0, 0, 64, 64 };
	Rectangle dest = { position.x, position.y, 32, 32 };
	Vector2 origin = { 16, 16 };
	DrawTexturePro(image, source, dest, origin, rotation, WHITE);
}
