#include "Asteroids.h"


Asteroids::Asteroids() {
	srand(time(NULL));
}

int Asteroids::getScore() {
	return score;
}

void Asteroids::update(float LaserYPos, int LaserSrcW, float LaserXPos) {
	
	yPos += .5;

	if (yPos > RenderWindow::WindowY) {
		yPos = 10;
		asteroidHit = false;
		asteroidOut = false;
	}
	if (yPos < 350) {
			if(LaserYPos <= (yPos+srcH-10) && LaserYPos>yPos){
				if ((LaserXPos > xPos) && (LaserXPos< xPos + srcW)) {
					score += 10;
					asteroidHit = true;
				}
			}
	else {
	}
	}
	

	updateTexture();	
}
bool Asteroids::isHit() {
	
	return asteroidHit;

}
void Asteroids::updateTexture() {
	if (asteroidHit||hitsSpaceHub()) {

		texture = Textures::createEntityTex("SpaceGame/explosion.png");
		timer++;
		if (timer > 55) {
			timer = 0;
			asteroidOut = true;
			asteroidHit = false;

		}

	}
	else if (asteroidOut && !asteroidHit) {
		
		texture = NULL;
		updateXPos();
		yPos = 10;
		timer++;
		if (timer == 60) {
			timer = 0;
			asteroidHit = false;
			asteroidOut = false;
		}
	}
	else if (!asteroidHit && !asteroidOut) {
		texture = Textures::createEntityTex("SpaceGame/asteroid.png");
	}
}
void Asteroids::updateXPos() {
	xPos = 100+ (rand() % 600);
}
void Asteroids::pause() {
	yPos = yPos;
}
bool Asteroids::hitsSpaceShip(float shipX, int shipW, int shipH) {
	if (!asteroidHit && !asteroidOut) {
		if (((xPos > shipX) && (xPos + srcW < shipX + shipW)) || ((shipX > xPos) && (xPos + srcW > shipX))) {
			if (yPos + srcH >= 355 && yPos < 450) {
				return true;
			}
			else
				return false;
		}
		else if ((xPos < shipW + shipX) && (shipW + shipX < xPos + srcW)) {
			if (yPos + srcH >= 355 && yPos < 450) {
				return true;
			}
			else
				return false;
		}

		else
			return false;
	}
	else return false;
}
bool Asteroids::hitsSpaceHub() {
		if (yPos > RenderWindow::WindowY - 50) {
			if (asteroidHit) {
				return false;
			}
			else
				return true;
		}
	
	else return false;
	
}
void Asteroids::reset() {
	yPos = 10;
	score = 0;
}