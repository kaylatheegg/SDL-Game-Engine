#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "../../include/config.h"
#include "../../include/engine.h"

int loop = 1;

int main(int argc, char* argv[]) {
	int framerate = 60;

	if (initRender() == 1) {
		return 0;
	}

	initObject();

	


	
	for (int i = 0; i < HEIGHT/64 + 1; i++) {
		createObject(textures[0], WIDTH-64, i * 64, "Floor", 1, 1, 0, COLLIDE);
		createObject(textures[0], 0, i * 64, "Floor", 1, 1, 0, COLLIDE);
	}
	for (int i = 0; i < WIDTH/64 + 1; i++) {
		createObject(textures[0], i * 64, HEIGHT-64, "Floor", 1, 1, 0, COLLIDE);
		createObject(textures[0], i * 64, 0, "Floor", 1, 1, 0, COLLIDE);
	}
	initPlayer();
	//createObject(textures[1], 100, 100, "Cunt", 0.1f, 1, 193);
	//createObject(textures[0], 190, 250, "Cunt2", 1, 1, 0);
	//initLevel();

	while (loop) {
		
		SDL_Event event;

		if ( SDL_PollEvent(&event) ) {
			if (event.type == SDL_QUIT)
				loop = 0;
			if (event.type == SDL_KEYDOWN)
    		    switch (event.key.keysym.sym) {
           	 		case SDLK_a: moveObject(LEFT, 64, player, COLLIDE); break;
          	 		case SDLK_d: moveObject(RIGHT, 64, player, COLLIDE); break;
            		case SDLK_w: moveObject(UP, 64, player, COLLIDE); break;
            		case SDLK_s: moveObject(DOWN, 64, player, COLLIDE); break;
       			}
		} 

		if (render() == 1) {
			loop = 0;
		}

		processPlayerPhysics();
		
		processPosition();

		SDL_Delay(1000/framerate);
		//objects[0]->angle++;
	}


	cleanupEngine();
	SDL_Quit();

	return 0;
}
