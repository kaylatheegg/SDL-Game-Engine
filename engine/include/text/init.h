#pragma once
#define INIT_TEXT_ENGINE_H

int fontCount;

char** fontLocations;

TTF_Font** fonts; 

int textObjects;


int createFonts();
int loadFonts(char* fontName);