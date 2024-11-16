#include "Number.h"

Number::Number() {
	srand(time(NULL));


	num = 10000 + (rand()%(50000-10000)+1);
	minInterval[0] = 10000;
	minInterval[1] = 2000;
	minInterval[2] = 100;
	minInterval[3] = 10;
	minInterval[4] = 0;

	maxInterval[0] = 50000;
	maxInterval[1] = 40000;
	maxInterval[2] = 150;
	maxInterval[3] = 40;
	maxInterval[4] = 10;
}

void Number:: NextNumber(int newSpot){
	spot = newSpot;
	num = minInterval[spot] + (rand() % (maxInterval[spot]-minInterval[spot]+1));
	counter = 0;
}
bool Number::isTooHigh(int Usernum, int SPOT) {
	if (Usernum > maxInterval[SPOT])
		return true;
	else
		return false;
}
bool Number::isTooLow(int Usernum, int SPOT) {
	if (Usernum < minInterval[SPOT])
		return true;
	else
		return false;
}
int Number::getScore() {
	return score;
}
void Number::resetScore()
{
	score = 0;
}
int Number::getMaxInterval(int round) {
	return maxInterval[round];
}
int Number::getMinInterval(int round) {
	return minInterval[round];
}


bool Number::isHigher(int Usernum) {
	if (Usernum >= num) {
		if (counter < 1) {
			score += 1000;
			counter++;
		}
		
		return true;
	}
	else
		return false;
}

int Number::getNum() {
	return num;
}
