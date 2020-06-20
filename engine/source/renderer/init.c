#include "../../include/engine.h"

SDL_Window* window;
SDL_Renderer* renderer;

int initRender() {
	char error[256];
	logtofile("Initialising SDL", INF);
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		sprintf(error, "SDL Init failure, error: %s", SDL_GetError());
		logtofile(error, SVR);
		return 1;
	}

	logtofile("Initialising window", INF);
	window = SDL_CreateWindow("SDL Game Engine", 100, 100, WIDTH, HEIGHT, 0);
	if (window == NULL) {
		sprintf(error, "SDL window creation, error: %s", SDL_GetError());
		logtofile(error, SVR);
		return 1;
	}

	logtofile("Initialising renderer", INF);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == NULL) {
		sprintf(error, "SDL renderer creation, error: %s", SDL_GetError());
		logtofile(error, SVR);
		return 1;
	}
	createTextures();
	logtofile("Initialising textures", INF);
	createFonts();
	logtofile("Initialising fonts", INF);
	return 0;
}