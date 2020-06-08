#include <stdio.h>


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
		printf("texture: %s\n", textureLocations[i]);
	}
	printf("texture count: %d\n", textureCount);
}

int createTextures() {
	loadTexture("engine/res/images/default.png");
	loadTexture("engine/res/images/brick.png");
	

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

int createTexture(char* textureName, SDL_Texture* texture) {
	loadTexture(textureName);
	textures = realloc(textures, sizeof(SDL_Texture*) * (textureCount + 1));
	textures[textureCount] = texture;
}

//sdl_texture*[a] a = sdl_texture* a

//sdl_texture**  = sdl_texture*


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
		//printf("addr of texture: %p\n", &textures[i]);
		//SDL_DestroyTexture(textures[i]);
		//printf("%d\n", i);
		/* unfortunately, there is a bug with sdl 2.0 that stops this from working when it comes to text objects, 
		and because they are all variable it is easier to disable the clearing than testing if they are objects. 
		this does cause a memory leak inside of the engine. this should be SMALL but if the engine ever gets a
		large texture library, we may need to find a workaround that prevents the crash. */
		//just for future kayla, this HAS been tested
		/* i first tested the index, and it crashes on any text objects being removed.
		then, i tested the addresses of the texture and they go up by 0x8 */
	}
	free(textureLocations);
	free(textures);
}