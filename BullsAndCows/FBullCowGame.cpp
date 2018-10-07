#include "pch.h"
#include "FBullCowGame.h"

// Getter functions
int FBullCowGame::GetMaxTries() const {	return _maxTries; }
int FBullCowGame::GetCurrentTry() const { return _currentTry; }

/*
Reset sets the maxTries to variable x and currentTry to 1.

Reset can be a private method but we will see what to do with this later.
*/
void FBullCowGame::Reset(int x)
{
	_maxTries = x;
	_currentTry = 1;
}

void FBullCowGame::IncrementTry()
{
	_currentTry++;
}



bool FBullCowGame::IsGameOver() const
{
	return false;
}

bool FBullCowGame::IsGuessValid(std::string guess) const
{
	// TODO: Implement the function and remove the debugging code
	return true;
}

FBullCowGame::FBullCowGame()
{
	Reset(6);
}

FBullCowGame::FBullCowGame(int x)
{
	Reset(x);
}


FBullCowGame::~FBullCowGame()
{}
