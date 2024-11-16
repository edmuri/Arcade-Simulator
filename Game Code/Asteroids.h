#pragma once
#include "Entity.h"
#include "Textures.h"
#include "RenderWindow.h"

class Asteroids :public Entity {

public:

	Asteroids();
	void update(float, int, float);
	bool isHit();
	void updateTexture();
	void updateXPos();
	void pause();
	bool hitsSpaceShip(float shipX, int shipW, int shipH);
	bool hitsSpaceHub();
	void reset();

	 int getScore();

private:
	int score = 0;
	int timer = 0;
	bool asteroidHit = false;
	bool asteroidOut = false;
	//SDL_Texture* explosion = Textures::createEntityTex("SpaceGame/explosion.png");
	SDL_Texture* original = Textures::createEntityTex("SpaceGame/asteroid.png");

};