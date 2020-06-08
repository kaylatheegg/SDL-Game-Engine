#include <stdio.h>


#include "../../include/config.h"
#include "../../include/engine.h"



int createTextObject(TTF_Font* font, char* string, int x, int y) {
	SDL_Color color = { 255, 255, 255 };
	SDL_Surface* surface = TTF_RenderText_Solid(font, string, color);
	createTexture("text object", SDL_CreateTextureFromSurface(renderer, surface));
	createObject(textures[textureCount], x, y, "text object", 1, 1, 0, NO_COLLIDE);
	SDL_FreeSurface(surface);
	textObjects++;
}

int cleanFonts() {
	for (int i = 0; i < fontCount; i++) {
		free(fontLocations[i]);
		TTF_CloseFont(fonts[i]);
	}
	free(fontLocations);
	free(fonts);
}