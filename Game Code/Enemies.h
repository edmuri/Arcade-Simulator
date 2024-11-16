#pragma once

#include <iostream>
#include "Entity.h"
#include "Textures.h"

using namespace std;

class Enemies : public Entity {
public:
	Enemies();
	void isClicked(bool Clicked);
	void moveEnemy();
	int getScore();
	void updateEnemy();
	bool arrivedAtHouse();
	void reset();

private:
	int houseX = (RenderWindow::WindowX / 2) - 75;
	int houseXW = houseX + 100;
	int houseY = (RenderWindow::WindowY / 2) - 50;
	int houseYH = houseY + 100;
	bool clickedOn = false;

	int score;
	int counter;
};
