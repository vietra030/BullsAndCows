#pragma once
#include <string>

class FBullCowGame
{
private:
	int _maxTries;
	int _currentTry;
public:
	void Reset(int); // TODO make a more richer return value
	void IncrementTry();
	int GetMaxTries();
	int GetCurrentTry();
	bool IsGameOver();
	FBullCowGame();
	~FBullCowGame();
};

