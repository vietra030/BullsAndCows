#include "pch.h"
#include "FBullCowGame.h"


void FBullCowGame::Reset(int)
{}

void FBullCowGame::IncrementTry()
{
	_currentTry++;
}

int FBullCowGame::GetMaxTries() const
{
	return _maxTries;
}

int FBullCowGame::GetCurrentTry() const
{
	return _currentTry;
}

bool FBullCowGame::IsGameOver() const
{
	return false;
}

FBullCowGame::FBullCowGame()
{
	_maxTries = 6;
	_currentTry = 1;
}

FBullCowGame::FBullCowGame(int x)
{
	_maxTries = x;
	_currentTry = 1;
}


FBullCowGame::~FBullCowGame()
{}
