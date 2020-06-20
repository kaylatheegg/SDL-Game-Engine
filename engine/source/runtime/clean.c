#include "../../include/engine.h"

int cleanupEngine() {
	logtofile("Destroying objects", INF);
	cleanObjects();

	logtofile("Destroying fonts", INF);
	cleanFonts();

	logtofile("Destroying textures", INF);
	cleanTexture();

	
	logtofile("Destroying renderer", INF);
	SDL_DestroyRenderer(renderer);

	logtofile("Destroying window", INF);
	SDL_DestroyWindow(window);

	logtofile("Closing TTF", INF);
	TTF_Quit();

	logtofile("Closing SDL, have a wonderful day!", INF);
	SDL_Quit();
}