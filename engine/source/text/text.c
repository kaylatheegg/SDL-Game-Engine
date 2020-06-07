#include <stdio.h>


#include "../../include/config.h"
#include "../../include/engine.h"



int createTextObject(SDL_Font* font, char* string, int x, int y) {
	SDL_Color color = { 255, 255, 255 };
	SDL_Surface* surface = TTF_RenderText_Solid(font, string, color);
	createTexture("text object", SDL_CreateTextureFromSurface(renderer, surface));
	SDL_FreeSurface(surface);
}