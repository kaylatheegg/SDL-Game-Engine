#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "../../include/config.h"
#include "../../include/engine.h"

int render() {
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderClear(renderer);

	for (int i = 0; i < objectCount; i++) {
		if (objects[i]->render == 1) {
			SDL_Rect renderRect;
			if (objects[i]->angle != 0) {
				if (SDL_RenderCopyEx(renderer, objects[i]->texture, NULL, objects[i]->rect, objects[i]->angle, NULL, SDL_FLIP_NONE) != 0) {
					printf("SDL texture rendering failure, error: %s\n", SDL_GetError());
					return 1;
				}
			} else {
				if (SDL_RenderCopy(renderer, objects[i]->texture, NULL, objects[i]->rect) != 0) {
					printf("SDL texture rendering failure, error: %s\n", SDL_GetError());
					return 1;
				}
			}
		}
	}
	SDL_RenderPresent(renderer);
	return 0;
}