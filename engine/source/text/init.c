#include <stdio.h>


#include "../../include/config.h"
#include "../../include/engine.h"

int fontCount = 0;

char** fontLocations;

TTF_Font** fonts; 

int textObjects = 0;

int createFonts() {
	TTF_Init();
	loadFonts("engine/res/fonts/Helvetica 400.ttf");

	for (int i = 0; i < fontCount; i++) {
		if (i == 0) {
			fonts = malloc(sizeof(TTF_Font*));
		} else {
			fonts = realloc(fonts, sizeof(TTF_Font*) * (i + 1));
		}
		fonts[i] = TTF_OpenFont(fontLocations[i], 25);
		if (fonts[i] == NULL) {
			printf("creation of font \"%s\" failed, error: \"%s\"\n", fontLocations[i], TTF_GetError());
			printf("no backup font detected, so if any text is drawn, it will crash the engine!\n");
		}
	}
}

int loadFonts(char* fontName) {
		if (fontCount == 0) {
		fontLocations = malloc(sizeof(char*));
		fontLocations[0] = malloc(strlen(fontName) + 1);
		strcpy(fontLocations[0], fontName);
	} else {
		fontLocations = realloc(fontLocations, sizeof(char*) * (fontCount + 1));
		fontLocations[fontCount] = malloc(strlen(fontName) + 1);
		strcpy(fontLocations[fontCount], fontName);
	
	}
	fontCount++;
}