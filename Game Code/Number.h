#pragma once
#include "RenderWindow.h"
class Number {
public:
	Number();
	void NextNumber(int);
	bool isHigher(int);
	int getNum();
	int getScore();
	void resetScore();
	int getMaxInterval(int);
	int getMinInterval(int);
	bool isTooHigh(int, int);
	bool isTooLow(int, int);

private:
	int num;
	int score;
	int minInterval[5];
	int maxInterval[5];
	int spot=0;
	int counter = 0;
};
