#include <stdio.h>


#include "../../include/config.h"
#include "../../include/engine.h"

int loop = 1;

int main(int argc, char* argv[]) {
	int framerate = 60;

	if (initRender() == 1) {
		return 0;
	}

	initObject();

	



	while (loop) {
		
		SDL_Event event;

		if ( SDL_PollEvent(&event) ) {
			if (event.type == SDL_QUIT) {
				loop = 0;
			}
		} 

		if (render() == 1) {
			loop = 0;
		} 

		
		
		SDL_Delay(1000/framerate);
		//objects[0]->angle++;
	}


	cleanupEngine();
	SDL_Quit();

	return 0;
}
