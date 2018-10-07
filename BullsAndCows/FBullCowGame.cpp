#include "pch.h"
#include "FBullCowGame.h"


void FBullCowGame::Reset(int)
{}

void FBullCowGame::IncrementTry()
{
	_currentTry++;
}

int FBullCowGame::GetMaxTries()
{
	return _maxTries;
}

int FBullCowGame::GetCurrentTry()
{
	return _currentTry;
}

bool FBullCowGame::IsGameOver()
{
	return false;
}

FBullCowGame::FBullCowGame()
{
	_maxTries = 6;
	_currentTry = 1;
}


FBullCowGame::~FBullCowGame()
{}
