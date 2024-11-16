#include "Entity.h"
//Entity character; 

//Textures character;
Entity::Entity() {}

SDL_Texture* Entity::createTexture(SDL_Texture* tex,float x, float y, int srcHeight, int srcWidth)
{
	srcH = srcHeight;
	srcW = srcWidth;
	xPos = x;
	yPos = y;
	originalXPos = x;
	originalYPos = y;

	texture = tex;
	return texture;
}

void Entity::setYPos(float y) {
	yPos= y;
}
void Entity::setXPos(float x) {
	xPos= x;
}
float Entity::getXPos() {
	return xPos;
}
float Entity::getYPos() {
	return yPos;
}

//void Entity::jump()
