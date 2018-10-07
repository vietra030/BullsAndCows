#include "pch.h"
#include "FBullCowGame.h"

// Getter functions
int32 FBullCowGame::GetMaxTries() const {	return _maxTries; }
int32 FBullCowGame::GetCurrentTry() const { return _currentTry; }

void FBullCowGame::Reset()
{
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

bool FBullCowGame::IsGuessValid(FString guess) const
{
	// TODO: Implement the function and remove the debugging code
	return true;
}

FBullCowGame::FBullCowGame()
{
	Reset();
	_maxTries = 6;
}

FBullCowGame::FBullCowGame(int32 x)
{
	Reset();
	_maxTries = x;
}


FBullCowGame::~FBullCowGame()
{}
