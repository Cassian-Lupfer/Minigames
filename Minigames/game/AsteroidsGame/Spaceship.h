#ifndef SPACESHIP_H_
#define SPACESHIP_H_

#include <raylib.h>
#include <ResourceManager.h>

class Spaceship {
private:
	Canolu::ResourceManager resourceManager;

	Texture2D image;
public:
	Vector2 position;
	float rotation = 180.0;
	Vector2 velocity;
	const int maxSpeed = 2;
	const int acceleration = 1;
	const int rotationSpeed = 3;

	Spaceship(Vector2 pPosition);
	void update();
	void draw();
};

#endif
