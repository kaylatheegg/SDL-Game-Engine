#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "../../include/config.h"
#include "../../include/engine.h"

int gravity = 5;

int gravityDir = DOWN;

int processPlayerPhysics() {

	if (testCollision(gravityDir, player) == 0) {
		//moveObject(gravityDir, gravity, player, COLLIDE);
	}

}