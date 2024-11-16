#include "Scores.h"

Score::Score(){}

Score::Score(string userName, int num, int userGame) {
	name = userName;
	score = num;
	storeGame(userGame);
}

void Score::storeScore(int num) {
	score = num;
}

void Score::storeName(string userName) {
	name = userName;
}

void Score::storeGame(int Usergam) {
	if (Usergam == 1) 
		game = "Number Guess";
	else if (Usergam == 2) 
		game = "Space Shooter";
	else if (Usergam == 3) 
		game = "Ghost Shooter";
	else
		game = "Unknown" ;
}
int Score::getGameNum() {
	if (game == "Number Guess")
		return 1;
	else if (game == "Space Shooter")
		return 2;
	else if (game == "Ghost Shooter")
		return 3;
	else
		return 4;
}



int Score::getScore() {
	return score;
}

string Score::getName() {
	return name;
}

string Score::getGame() {
	return game;
}