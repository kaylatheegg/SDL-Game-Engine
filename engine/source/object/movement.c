#include "../../include/engine.h"



void moveObject(int dir, int amount, object* object, int collision) {
	int collide = testCollision(dir, object);
	if (collide == 0 && collision == COLLIDE) {
		if (dir == UP) {
			object->y = object->y - amount;
		} else if (dir == DOWN) {
			object->y = object->y + amount;
		} else if (dir == LEFT) {
			object->x = object->x - amount;
		} else if (dir == RIGHT) {
			object->x = object->x + amount;
		} 
	}
}

int testCollision(int dir, object* object) {
	int collide = 0;
	SDL_Rect *testRect = object->rect;
	if (dir == UP) {
		testRect->y = testRect->y - 1;
	} else if (dir == DOWN) {
		testRect->y = testRect->y + 1;
	} else if (dir == LEFT) {
		testRect->x = testRect->x - 1;
	} else if (dir == RIGHT) {
		testRect->x = testRect->x + 1;
	} 

	for (int i = 0; i < objectCount; i++) {
		if (!(objects[i]->id == object->id)) {
			if (SDL_HasIntersection(objects[i]->rect, testRect)) {
				//printf("object name: %s, testrect name: %s\n", objects[i]->name, object->name);
				collide = 1;
				break;
			} else {
				collide = 0;
			}
		}
	}
	return collide;
}