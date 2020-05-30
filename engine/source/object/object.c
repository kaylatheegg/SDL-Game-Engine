#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>



#include "../../include/config.h"
#include "../../include/engine.h"



/*	int x;
	int y;
	int w;
	int h;
	SDL_Rect *rect;
	SDL_Texture *texture;
	float scale;
	int id;
	char* name;
	bool render;
	bool dScale;
	int angle;
	bool collide;
	SDL_Rect *collider;*/

object* createObject(SDL_Texture* tx, int x, int y, char* name, float scale, bool render, int angle, int collisionType) {
	if (objectCount > 0) {
		objects = realloc(objects, sizeof(object*) * (objectCount + 1));
	}
	//size_t objectSize = 4*sizeof(int) + sizeof(SDL_Rect*) + sizeof(float) + sizeof(int) + sizeof(char*) + 2*sizeof(bool) + sizeof(int) + sizeof(bool) + sizeof(SDL_Rect*);
	//printf("%lu\n", objectSize);
	objects[objectCount] = malloc(140);
	objects[objectCount]->rect = malloc(32);
	objects[objectCount]->x = x;
	objects[objectCount]->y = y;
	int w,h;
	SDL_QueryTexture(tx, NULL, NULL, &w, &h);
	objects[objectCount]->w = w;
	objects[objectCount]->h = h;
	objects[objectCount]->rect->x = x;
	objects[objectCount]->rect->y = y;
	objects[objectCount]->rect->w = ceil(w * scale);
	objects[objectCount]->rect->h = ceil(h * scale);
	objects[objectCount]->texture = tx;
	objects[objectCount]->scale = scale;
	objects[objectCount]->id = objectCount;
	objects[objectCount]->name = malloc(strlen(name) + 1);
	strcpy(objects[objectCount]->name, name);
	objects[objectCount]->render = render;
	objects[objectCount]->dScale = 0;
	objects[objectCount]->angle = angle;
	objects[objectCount]->collide = collisionType;
	objectCount++;
	return objects[objectCount-1];
}

int processPosition() {
	for (int i = 0; i < objectCount; i++) {
		objects[i]->rect->x = objects[i]->x;
		objects[i]->rect->y = objects[i]->y;
		//objects[i]->collider->x = 1;
		//objects[i]->collider->y = objects[i]->y;
	}
}

/*typedef struct {
	object* object;
	int x;
	int y;
	char* name;
	int angle;
} cObject;*/


int cleanObject() {
	for (int i = 0; i < objectCount; i++) {
		free(objects[i]->rect);
		free(objects[i]);
	}
	free(objects);
}

