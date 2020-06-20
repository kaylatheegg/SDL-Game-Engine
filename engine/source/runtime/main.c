#include "../../include/engine.h"

int loop = 1;

int main(int argc, char* argv[]) {
	int framerate = 60;
	initLog();
	char log[128];
	sprintf(log, "Starting Roguelike Version %s", RVERSION);
	logtofile(log, INF);

	if (initRender() == 1) {
		logtofile("Initialising rendering failed!", SVR);
		return 0;
	}

	initObject();

	createTextObject(fonts[0], "poopy", 100, 100);
	createTextObject(fonts[0], "poopy1", 200, 100);
	createTextObject(fonts[0], "poopy2", 300, 100);
	printTextures();

	while (loop) {
		
		SDL_Event event;

		if ( SDL_PollEvent(&event) ) {
			if (event.type == SDL_QUIT) {
				loop = 0;
			}
		} 

		if (render() == 1) {
			loop = 0;
			logtofile("Rendering failed!", SVR);
		} 

		
		
		SDL_Delay(1000/framerate);
	}


	cleanupEngine();	
	return 0;
}
