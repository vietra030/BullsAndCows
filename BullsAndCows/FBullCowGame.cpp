/*
Author: Matruprasad Chand
Date: 06/10/2018
Info:
	* This is a console based word guessing game
	* The User will be provided with a few clues and has to guess the word correctly within the given number of tries.
	* For each letter in the right place, the user gets a bull and for each correct character placed in the wrong place the user gets a cow.
*/
#pragma once
#include "pch.h"
#include "FBullCowGame.h"
#include <random>
#include <chrono>
#include <map>
#define TMap std::map // Unreal syntax for std::map of C++

void FBullCowGame::_setSecretWord()
{
	/*
	C++ Random number generation never ceases to amaze me.
	who thought mt19937 was a great name for a type? What do the numbers mean?
	But it's cool. I love using it.
	*/
	std::mt19937 rng;
	rng.seed(std::chrono::high_resolution_clock::now().time_since_epoch().count());
	std::uniform_int_distribution<std::mt19937::result_type> dist(0, _wordDictioary.size() - 1);
	_secretPos = dist(rng); 
	_setMaxTries();
}

void FBullCowGame::_setMaxTries() {	_maxTries = _wordDictioary[_secretPos].length() - 1; } // Sets the maximum tries depending on the number of letters in the word

// TODO: Define the logic to check if there are repeating letters present
bool FBullCowGame::_isIsogram(FString guess) const
{
	if (guess.length() < 2) // Not possible to repeat a character if there is only one
	{
		return true;
	}
	TMap<char, bool> letterSeen;
	/*
		I had no idea the range based for loop is present in C++. Have been extensively using it in Java and C#

		Also I had no idea about auto. Embaressing to admit but this is the first time using it in my 4 years of C++ experience. Always used var in C# but had no idea about C++ implementation.
	*/
	for (auto letter : guess)
	{
		if (letterSeen[letter])
		{
			return false;
		}
		else
		{
			letterSeen[letter] = true;
		}
	}
	return true;
}

// Getter functions
int32 FBullCowGame::GetMaxTries() const	{ return _maxTries; }
int32 FBullCowGame::GetCurrentTry() const { return _currentTry; }
int32 FBullCowGame::GetWordLength() const {	return _wordDictioary[_secretPos].length();	}
// Boolean functions
bool FBullCowGame::IsGameWon() const { return _bGameWon; }

// Error checking code
EGuessStatus FBullCowGame::IsGuessValid(FString guess) const
{
	if (!_isIsogram(guess))
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (guess.length() != GetWordLength())
	{
		return EGuessStatus::Wrong_Length;
	}
	else
	{
		return EGuessStatus::OK;
	}
}

void FBullCowGame::Reset()
{
	_bGameWon = false;
	_setSecretWord();
	_currentTry = 1;
}

FBullCowCount FBullCowGame::SubmitGuess(FString guess)
{
	_currentTry++; // When valid input is made the Current try will be incremented
	FBullCowCount bcc;
	auto x = GetWordLength();
	for (auto GCount = 0; GCount < x; GCount++) // GCount is the guess count
	{
		for (auto HWCount = 0; HWCount < x; HWCount++) // HWCount is the hidden word count
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
	if (bcc.bull == GetWordLength())
	{
		_bGameWon = true;
	}
	return bcc;
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
