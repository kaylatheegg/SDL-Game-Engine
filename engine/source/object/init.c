#include "../../include/engine.h"

object** objects;

static size_t objectSize;
static size_t rectSize;


/*
	object** pointer so its an array of object*, so we can dynamically assign new objects easily
	*objects = object*
	**objects = object
	objects[0].x SHOULD BE objects[0]->x
	because that is actually *objects[0].x
*/

/* rect size = 32
objSize = 106*/

void initObject() {
	logtofile("Initialising objects", INF);
	objects = malloc(sizeof(object*));
}



/*typedef struct {
	int x;
	int y;
	int w;
	int h;
	SDL_Rect* rect;
	SDL_Texture* texture;
	float scale;
	int id;
	char* name;
	bool render;
	bool dScale;
}object;
*/