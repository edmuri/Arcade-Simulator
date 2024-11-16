#include "Enemies.h"

Enemies::Enemies() {}

int Enemies::getScore() {
	return score;
}
void Enemies::isClicked(bool clicked) {
	if (clicked)
		clickedOn = true;
	else
		clickedOn = false;
}
void Enemies::moveEnemy() {
	if (clickedOn) {
		setYPos(originalYPos);
		setXPos(originalXPos);
		counter++;
		
		if (counter > 50) {
			score += 50;
			clickedOn = false;
			counter = 0;
		}
		
	}
	else if (!clickedOn) {
		if ((xPos < RenderWindow::WindowX / 2)&&(yPos < RenderWindow::WindowY/2)) {
		xPos += 0.9;
		yPos += 0.5;
	}
	else if ((xPos < RenderWindow::WindowX / 2) && (yPos > RenderWindow::WindowY / 2)) {
		xPos += 0.9;
		yPos -= 0.5;
	}
	else if ((xPos > RenderWindow::WindowX / 2) && (yPos < RenderWindow::WindowY / 2)) {
		xPos -= 0.9;
		yPos += 0.5;
	}
	else if ((xPos > RenderWindow::WindowX / 2) && (yPos > RenderWindow::WindowY / 2)) {
		xPos -= 0.9;
		yPos -= 0.5;
	}

	}
	
	
}

void Enemies::reset() {
	setYPos(originalYPos);
	setXPos(originalXPos);
	score = 0;
}
bool Enemies::arrivedAtHouse() {


	if ((xPos > houseX) && (xPos + srcW < houseXW) || ((houseX > xPos) && (xPos + srcW > houseX))) {
		if (yPos + srcH >= houseY && yPos < houseYH) {
			return true;
		}
		else if ((yPos + srcH > houseYH) && (yPos < houseYH)) {
			return true;
		}
		else
			return false;
	}
	else if ((xPos < houseXW) && (houseX < xPos + srcW)) {
		if (yPos + srcH >= houseY && yPos < houseYH) {
			return true;
		}
		else if ((yPos + srcH > houseYH) && (yPos < houseYH)) {
			return true;
		}
		else
			return false;
	}
	else
		return false;
}
void Enemies::updateEnemy() {
	moveEnemy();

}