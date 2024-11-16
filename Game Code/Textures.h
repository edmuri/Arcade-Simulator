#pragma once
#include "RenderWindow.h"

class Textures {
public:
	Textures();
	static SDL_Texture* createEntityTex(const char* fileName);
	SDL_Texture* createTexture(const char* fileName, int xpos, int ypos, int srcRecWidth, int srcRecHeight);

	SDL_Texture* createBackground(const char* fileName);

	int getSrcHeight();
	int getSrcWidth();
	float getxPos();
	float getyPos();

	SDL_Texture* texture;
private:
	int srcHeight;
	int srcWidth;
	float xPos;
	float yPos;
	
};