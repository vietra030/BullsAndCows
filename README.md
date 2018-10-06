# Bulls and Cows Game
* This is a small console based game built entirely with C++. 
* This is a guess the [**isogram**](https://en.wikipedia.org/wiki/Isogram) game. 

## Rules
1. The number of letters and the first letter of the unknown word is mentioned.
2. The user has a limited number of guesses.
3. After each guess the computer outputs 
    * _Bull_ : Right letter at the right place
    * _Cow_ : Right letter in the wrong place
4. You win if you manage to guess the word before your number of tries run out.

## Requirements
* __Input :__ The guessed word as a string
* __Output :__ The number of bulls, cows and the number of remaining tries.

## Possible future ideas
* Give feedback on every key press
* A large dictionary of hidden words
* User selectable word length
* Difficulty level
* Provide time limits for guesses along with number of tries
* Adding new isograms from the users' wrong inputs
* A hint system