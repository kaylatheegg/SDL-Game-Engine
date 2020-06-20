#include "../../include/engine.h"

int render() {
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderClear(renderer);
	char error[256];
	for (int i = 0; i < objectCount; i++) {
		if (objects[i]->render == 1) {
			SDL_Rect renderRect;
			if (objects[i]->angle != 0) {
				if (SDL_RenderCopyEx(renderer, objects[i]->texture, NULL, objects[i]->rect, objects[i]->angle, NULL, SDL_FLIP_NONE) != 0) {
					sprintf(error, "SDL texture rendering failure, error: %s", SDL_GetError());
					logtofile(error, ERR);
					sprintf(error, "trying to render with default texture");
					logtofile(error, ERR);
					if (SDL_RenderCopyEx(renderer, textures[0], NULL, objects[i]->rect, objects[i]->angle, NULL, SDL_FLIP_NONE) != 0) {
						sprintf(error,"SDL texture rendering failure, error: %s", SDL_GetError());
						logtofile(error, SVR);
						sprintf(error, "failed to render with default texture, something has gone TERRIBLY WRONG!!");
						logtofile(error, SVR);
						return 1;
					}
				}
			} else {
				if (SDL_RenderCopy(renderer, objects[i]->texture, NULL, objects[i]->rect) != 0) {
					sprintf(error, "SDL texture rendering failure, error: %s", SDL_GetError());
					logtofile(error, ERR);
					sprintf(error, "trying to render with default texture");
					logtofile(error, ERR);
					/*if (SDL_RenderCopy(renderer, textures[0], NULL, objects[i]->rect) != 0) {
						printf("SDL texture rendering failure, error: %s\n", SDL_GetError());
						printf("failed to render with default texture, something has gone TERRIBLY WRONG!!\n");
						return 1;
					}*/
				}
			}
		}
	}
	SDL_RenderPresent(renderer);
	return 0;
}