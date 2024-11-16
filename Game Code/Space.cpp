#include "Space.h"

Space::Space() {}


void Space::moveXPos(bool left) {
	if (left) {
		xVel = -11;
	}
	if (!left) {
		xVel = 11;
	}
}

void Space::updateShip() {
	setXPos(xVel + getXPos());


	for (int i = 0; i < (getXPos() + srcW); i++) {
		if (getXPos() + i < 0) {
			setXPos(RenderWindow::WindowX - i);
		}
	}

	xVel = 0;
}
