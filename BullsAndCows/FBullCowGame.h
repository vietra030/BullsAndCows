#pragma once
#include <string>
#include <vector>

// Substitutions made to make code more unreal like
using FString = std::string;
using int32 = int;
using List = std::vector<FString>;

// bull and cow values initialized to 0
struct FBullCowCount
{
	int32 bull = 0;
	int32 cow = 0;
};

/*
This is a strongly typed enum.
C++ 11 standard
enum class should be used instead of just simple enum to mitigate the type redefination error with other enums.
*/
// Check the status of the word
enum class EGuessStatus
{
	Invalid, // It's not necessary, but can be used in future
	OK, // The correct status
	Not_Isogram, // Error. User needs to re-enter the guess
	Wrong_Length, // Error. User needs to re-enter the guess
	Not_lowercase // Convert the inserted string to lowercase and then use it.
};

class FBullCowGame
{
private:
	// Variables
	int32 _maxTries;
	int32 _currentTry;
	int32 _secretPos;
	List _wordDictioary = { "brick", "blind", "simple", "sample" , "world"};
	// Methods
	void _setSecretWord();
public:
	// Getter functions
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetWordLength() const;

	// Check functions
	bool IsGameWon() const;
	EGuessStatus IsGuessValid(FString) const;

	void Reset(); // TODO: make a more richer return value
	FBullCowCount SubmitGuess(FString); 
	
	// Constructors
	FBullCowGame();
	FBullCowGame(int32); // Constructor for when there is a variable difficulty in the game.
	
	// Destructors
	~FBullCowGame();
};

