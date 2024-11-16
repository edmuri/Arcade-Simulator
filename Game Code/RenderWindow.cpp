#include "RenderWindow.h"

SDL_Renderer *RenderWindow::renderer = NULL;
int RenderWindow:: WindowX = 800;
int RenderWindow:: WindowY = 600;

RenderWindow::RenderWindow() {}
RenderWindow :: ~RenderWindow() {}

void RenderWindow::init(const char* title, float xpos, float ypos, int width, int height, bool fullscreen)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		
		if (fullscreen)
			fullscreen = SDL_WINDOW_FULLSCREEN;

		window = SDL_CreateWindow(title, xpos, ypos, width, height, fullscreen);
		SDL_MaximizeWindow(window);

		if (window == NULL)
			cout << "cannot create window";

		renderer = SDL_CreateRenderer(window, -1, 0);
	}
	
}

void RenderWindow::setRendererColor(int r, int g, int b)
{
	SDL_SetRenderDrawColor(renderer, r, g, b, 255);
}

void RenderWindow::renderBackground(SDL_Texture* tex)
{
	SDL_Rect desRec;
	desRec.y = 0;
	desRec.x = 0;
	desRec.w = WindowX;
	desRec.h = WindowY;

	SDL_RenderCopy(renderer, tex, NULL, &desRec);
}

void RenderWindow::renderTextures(SDL_Texture* texture, float xpos, float ypos, int srcHeight, int srcWidth)
{
	SDL_Rect srcRec;
	srcRec.x = 0;
	srcRec.y = 0;
	srcRec.w;
	srcRec.h;

	SDL_Rect destRec;
	destRec.x = xpos;
	destRec.y = ypos;
	destRec.w = srcWidth;
	destRec.h = srcHeight;

	SDL_RenderCopy(renderer,texture,NULL,&destRec);
}

void RenderWindow::ClearRender () {
	SDL_RenderClear(renderer);
}

void RenderWindow::display()
{
	SDL_RenderPresent(renderer);
	SDL_Delay(15);
}

void RenderWindow::End() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	TTF_Quit();
}

void RenderWindow::renderTexture(SDL_Texture* texture, float xpos, float ypos, int srcHeight, int srcWidth)
{
	SDL_Rect srcRec;
	srcRec.x = 0;
	srcRec.y = 0;
	srcRec.w;
	srcRec.h;

	SDL_Rect destRec;
	destRec.x = xpos;
	destRec.y = ypos;
	destRec.w = srcWidth;
	destRec.h = srcHeight;

	SDL_RenderCopy(renderer, texture, NULL, &destRec);
}
void RenderWindow::renderWordText(int x, int y, const char* text, TTF_Font* font, SDL_Color color) {
	SDL_Surface* surfaceMessage = TTF_RenderText_Blended(font, text, color);
	SDL_Texture* message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);

	SDL_Rect src;
	src.x = 0;
	src.y = 0;
	src.w = surfaceMessage->w;
	src.h = surfaceMessage->h;

	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	dst.w = src.w;
	dst.h = src.h;

	SDL_RenderCopy(renderer, message, &src, &dst);
	SDL_FreeSurface(surfaceMessage);
}
void RenderWindow::renderWordRealTime(int x, int y, const char* text,TTF_Font* font, SDL_Color color) {
	SDL_Surface* TEMP = NULL;
	SDL_Texture* textImage=NULL;
	SDL_Rect src;
	src.x = 0;
	src.y = 0;
	
	

	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	

	TEMP = TTF_RenderText_Solid(font, text, color);

	if (TEMP) {
		textImage = SDL_CreateTextureFromSurface(renderer, TEMP);
		src.w = TEMP->w;
		src.h = TEMP->h;
		dst.w = src.w;
		dst.h = src.h;
		SDL_FreeSurface(TEMP);
		TEMP = NULL;

	}
	SDL_RenderCopy(renderer, textImage, NULL, &dst);

}


