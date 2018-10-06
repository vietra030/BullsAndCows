#pragma once
#include <string>

class FBullCowGame
{
private:

public:
	void Reset(int); // TODO make a more richer return value
	int GetMaxTries();
	int GetCurrentTry();
	bool IsGameOver();
	FBullCowGame();
	~FBullCowGame();
};

