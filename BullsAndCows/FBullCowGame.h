#pragma once
#include <string>
#include <vector>

// Substitutions made to make code more unreal like
using FString = std::string;
using int32 = int;
using List = std::vector<FString>;

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
	int32 _secretPos;
	List _wordDictioary = { "brick", "blind", "simple", "sample" , "world"};

	void _setSecretWord();
public:
	// Getter functions
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetWordLength() const;

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

