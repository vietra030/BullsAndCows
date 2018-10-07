#pragma once
#include <string>

// Substitutions made to make code more unreal like
using FString = std::string;
using int32 = int;

// bull and cow values initialized to 0
struct BullCowCount
{
	int32 bull = 0;
	int32 cow = 0;
};

class FBullCowGame
{
private:
	int32 _maxTries;
	int32 _currentTry;
public:
	// Getter functions
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;

	// Check functions
	bool IsGameOver() const;
	bool IsGuessValid(FString) const;

	void Reset(); // TODO: make a more richer return value
	BullCowCount Count(FString); 
	
	// Constructors
	FBullCowGame();
	FBullCowGame(int32); // Constructor for when there is a variable difficulty in the game.
	
	// Destructors
	~FBullCowGame();
};

