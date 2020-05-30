#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <stdlib.h>
#include <string.h>

#include "../../include/config.h"
#include "../../include/engine.h"

int textureCount = 0;

char** textureLocations;

SDL_Texture** textures;

/*

char ** array;

this is an array of char*

*array[i] = char* i
**array[i][j] = char i[j]


*/

int printTextures() {
	for (int i = 0; i < textureCount; i++) {
		printf("texture:%s\n", textureLocations[i]);
	}
}

int createTextures() {
	loadTexture("engine/images/default.png");
	loadTexture("engine/images/brick.png");
	

	for (int i = 0; i < textureCount; i++) {
		if (i == 0) {
			textures = malloc(sizeof(SDL_Texture*));
		} else {
			textures = realloc(textures, sizeof(SDL_Texture*) * (i + 1));
		}
		textures[i] = IMG_LoadTexture(renderer, textureLocations[i]);
		if (textures[i] == NULL) {
			printf("creation of texture \"%s\" failed, error: \"%s\"\n", textureLocations[i], IMG_GetError());
			printf("replacing texture \"%s\" with default texture\n", textureLocations[i]);
			textures[i] = IMG_LoadTexture(renderer, textureLocations[0]);
		}
	}
}  





int loadTexture(char *textureName) {
	if (textureCount == 0) {
		textureLocations = malloc(sizeof(char*));
		textureLocations[0] = malloc(strlen(textureName) + 1);
		strcpy(textureLocations[0], textureName);
		//printf("%s\n%s\n", textureName, textureLocations[0]);
	} else {
		textureLocations = realloc(textureLocations, sizeof(char*) * (textureCount + 1));
		textureLocations[textureCount] = malloc(strlen(textureName) + 1);
		strcpy(textureLocations[textureCount], textureName);

		//printf("%s\n%s\n", textureName, *(textureLocations + (sizeof(char*) * textureCount)));
	
	}
	textureCount++;
}

int cleanTexture() {
	for (int i = 0; i < textureCount; i++) {
		free(textureLocations[i]);
		SDL_DestroyTexture(textures[i]);
	}
	free(textureLocations);
	free(textures);
}