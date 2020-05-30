#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "../../include/config.h"
#include "../../include/engine.h"

int initPlayer() {
	player = createObject(textures[1], WIDTH/2, HEIGHT/2, "Player", ((float)64/(float)1000), 1, 0, COLLIDE);
}