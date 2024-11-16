#pragma once
using namespace std;

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "Textures.h"
#include <iostream>
#include <iomanip>



class RenderWindow {
public:
	RenderWindow();
	~RenderWindow();

	void init(const char* title, float xpos, float ypos, int width, int height, bool fullscreen);
	void setRendererColor(int r, int g, int b);
	//SDL_Texture* createTexture(const char* fileName);
	void renderBackground(SDL_Texture* tex);
	void renderTextures(SDL_Texture* texture, float xpos, float ypos, int srcHeight, int srcWidth);
	void renderWordText(int x, int y, const char* text, TTF_Font* font, SDL_Color color);
	void renderWordRealTime(int x, int y, const char* text, TTF_Font* font, SDL_Color color);
	void display();
	void ClearRender();
	void End();

	void static renderTexture(SDL_Texture* texture, float xpos, float ypos, int srcHeight, int srcWidth);


	static SDL_Renderer* renderer;
	static int WindowY;
	static int WindowX;
private:
	SDL_Window* window;
	

};