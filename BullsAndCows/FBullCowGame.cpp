#include "pch.h"
#include "FBullCowGame.h"
#include <random>

// TODO: Fix bug here. Always the first word is getting selected. The entire purpose of mt19937 was to get me random values
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
	_secretPos = (int32)dist(rng); 
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
	for (int32 GCount = 0; GCount < x; GCount++) // GCount is the guess count
	{
		for (int32 HWCount = 0; HWCount < x; HWCount++) // HWCount is the hidden word count
		{
			if (guess[GCount] == _wordDictioary.at(_secretPos)[HWCount])
			{
				if (GCount == HWCount) // If they are in the same place
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

EGuessStatus FBullCowGame::IsGuessValid(FString guess) const
{
	// if the guess isn't an isogram
	if (false)
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (false) // if the guess is not all lowercase
	{
		// TODO : Convert to all lowercase instead of throwing tantrums
		return EGuessStatus::Not_lowercase;
	}
	else if (guess.length() != GetWordLength()) // if the guess is of wrong length
	{
		return EGuessStatus::Wrong_Length;
	}
	else
	{
		return EGuessStatus::OK;
	}
}

// COnstructor and destructor section
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
