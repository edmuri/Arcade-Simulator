#include "Textures.h"
Textures::Textures() {}

SDL_Texture* Textures::createEntityTex(const char* fileName)
{
	SDL_Texture* entityTex = NULL;
	SDL_Surface* tmpSur = NULL;
	tmpSur = IMG_Load(fileName);
	entityTex = SDL_CreateTextureFromSurface(RenderWindow::renderer, tmpSur);

	return entityTex;
}

 SDL_Texture* Textures::createTexture(const char* fileName, int xpos, int ypos, int srcRecWidth, int srcRecHeight)
{
	xPos = xpos;
	yPos = ypos;
	srcWidth = srcRecWidth;
	srcHeight = srcRecHeight;

	texture = NULL;
	SDL_Surface* surface = NULL;
	surface = IMG_Load(fileName);
	texture = SDL_CreateTextureFromSurface(RenderWindow::renderer, surface);

	if (texture == NULL) {
		cout << "Could not create texture from: " << fileName;
	}
	SDL_FreeSurface(surface);
	return texture;
}
SDL_Texture* Textures::createBackground(const char* fileName)
{
	SDL_Surface* temp;
	SDL_Texture* tex;
	temp = IMG_Load(fileName);
	tex = SDL_CreateTextureFromSurface(RenderWindow::renderer, temp);

	SDL_FreeSurface(temp);

	return tex;
}
int Textures::getSrcHeight() { return srcHeight; }
int Textures :: getSrcWidth() { return srcWidth; }
float Textures :: getxPos() { return xPos; }
float Textures::getyPos() {return yPos;}
