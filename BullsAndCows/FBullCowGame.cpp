#include "pch.h"
#include "FBullCowGame.h"
#include <random>

void FBullCowGame::_setSecretWord()
{
	/*
	C++ Random number generation never ceases to amaze me.
	who thought mt19937 was a great name for a type? What do the numbers mean?
	But it's cool. I love using it.
	*/
	std::mt19937 rng;
	rng.seed(std::random_device()());
	std::uniform_int_distribution<std::mt19937::result_type> dist(0, _wordDictioary.size() - 1);
	_secretPos = dist(rng); 
	// TODO: Assign a FString variable with this data. This works for the time being but needs to be done properly.
}

// Getter functions
int32 FBullCowGame::GetMaxTries() const { return _maxTries; }
int32 FBullCowGame::GetCurrentTry() const { return _currentTry; }
int32 FBullCowGame::GetWordLength() const { return _wordDictioary.at(_secretPos).length(); }

void FBullCowGame::Reset()
{
	_currentTry = 1;
}

// receives a VALID guess, Increments turn, returns count of bull and cow
FBullCowCount FBullCowGame::SubmitGuess(FString guess)
{
	/*
	increment the turn number
	setup a return variable
	loop through all the letters in guess
		Compare letters against the hidden word
	*/
	_currentTry++; // When valid input is made the Current try will be incremented
	FBullCowCount bcc;
	int32 x = _wordDictioary.at(_secretPos).length();
	for (int32 i = 0; i < x; i++)
	{
		for (int32 j = 0; j < x; j++)
		{
			if (guess[i] == _wordDictioary.at(_secretPos)[j])
			{
				if (i == j) // If they are in the same place
					bcc.bull++;
				else // If they are not in the same place
					bcc.cow++;
			}
		}
	}
	return bcc;
}

bool FBullCowGame::IsGameOver() const
{
	// TODO: Design a check to see if the game is over
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
