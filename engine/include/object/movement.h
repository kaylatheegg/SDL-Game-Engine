#pragma once
#define MOVEMENT_OBJECT_ENGINE_H

enum directions {
	UP = 1,
	DOWN = 2,
	LEFT = 3,
	RIGHT = 4
};


void moveObject(int dir, int amount, object* object, int collision);

int testCollision(int dir, object* object);