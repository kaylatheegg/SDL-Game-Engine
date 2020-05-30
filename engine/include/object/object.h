#pragma once 
#define OBJ_OBJECT_ENGINE_H

#include <stdbool.h>

int objectCount;

typedef struct {
	int x;
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
}object;

typedef struct {
	object* object;
	int x;
	int y;
	char* name;
	int angle;
} cObject;

int cleanObject();

enum cTypes {
	NO_COLLIDE,
	COLLIDE
};

object* createObject(SDL_Texture* tx, int x, int y, char* name, float scale, bool render, int angle, int collisionType);

int processPosition();