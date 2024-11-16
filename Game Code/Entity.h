#pragma once
#include "RenderWindow.h"
#include "Textures.h"

class Entity {
public:
	Entity();

	SDL_Texture* createTexture(SDL_Texture* tex, float x, float y, int srcHeight, int srcWidth);
	void setXPos(float); 
	void setYPos(float);
	float getYPos();
	float getXPos();
	int srcH;
	int srcW;

	int originalXPos;
	int originalYPos;
	float xPos;
	float yPos;

	SDL_Texture* texture;
private:


};
