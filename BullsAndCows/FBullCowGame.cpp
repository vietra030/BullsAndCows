#include "pch.h"
#include "FBullCowGame.h"
#include <random>

std::string WORD;

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
	_secretWord = _wordDictioary[dist(rng)]; // TODO: Fix this. Why is this assignment not working?
}

// Getter functions
int32 FBullCowGame::GetMaxTries() const {	return _maxTries; }
int32 FBullCowGame::GetCurrentTry() const { return _currentTry; }

int32 FBullCowGame::GetWordLength()
{
	// TODO: Remove the debug code

	_secretWord = "Bullshit"; // Debug code
	return _secretWord.length();
}

void FBullCowGame::Reset()
{
	_currentTry = 1;
}

// receives a VALID guess, Increments turn, returns count of bull and cow
BullCowCount FBullCowGame::Count(FString)
{
	/*
	increment the turn number
	setup a return variable
	loop through all the letters in guess
		Compare letters against the hidden word
	*/
	_currentTry++;
	BullCowCount bcc;

	return bcc;
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
