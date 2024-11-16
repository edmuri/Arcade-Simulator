#pragma once

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Score {
public:
	Score();
	Score(string, int, int);

	int getScore();
	string getName();
	string getGame();
	int getGameNum();

	void storeScore(int num);
	void storeName(string Username);
	void storeGame(int game);

private:
	int score;
	string name;
	string game;

};
