#pragma once
#include "Entity.h"
#include "RenderWindow.h"
#include "Textures.h"

class Space :public Entity {

public:
	Space();

	void moveXPos(bool);

	void updateShip();


private:
	int xVel;

};