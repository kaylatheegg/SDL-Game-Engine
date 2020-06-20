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
			char error[256];
			sprintf(error, "creation of font \"%s\" failed, error: \"%s\"", fontLocations[i], TTF_GetError());
			logtofile(error, ERR);
			sprintf(error, "no backup font detected, so if any text is drawn, it will crash the engine!");
			logtofile(error, ERR);
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