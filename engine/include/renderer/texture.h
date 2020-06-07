#pragma once
#define TX_RENDERER_ENGINE_H

int createTextures();
int loadTexture(char *textureName);

int cleanTexture();

int textureCount;

char** textureLocations;

SDL_Texture** textures;

int createTexture(char* textureName, SDL_Texture* texture);