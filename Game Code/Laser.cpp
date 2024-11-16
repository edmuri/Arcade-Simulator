#include "Laser.h"

Laser::Laser() {}

void Laser::updateLaser(float x) {

	Asteroids asteroid;
	initialYPos = 410;

	yVel = -5;

	setYPos(yVel + getYPos());

	if (asteroid.isHit()) {
		setYPos(initialYPos);
	}
	else if (getYPos() < 0) {
		setYPos(initialYPos);
	}

	xPos = x;

	

}