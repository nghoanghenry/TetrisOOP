#pragma once
#include <string>
#include <raylib.h>
using namespace std;

#define MAX_INPUT_CHARS 9
class Player {
private:

	int score;
	string name;
	int letterCount;
public:
	Player();
	Player(const std::string& playerName, int playerScore);
	int getScore();
	string getName();
	void setScore(int s);
	void reset();
	void getPlayerName();

}; 
