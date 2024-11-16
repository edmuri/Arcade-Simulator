#pragma once
#include "Entity.h"
#include "Asteroids.h"

class Laser :public Entity {
public:
	Laser();
	void updateLaser(float x);


private:
	int yVel;
	float initialYPos;
};