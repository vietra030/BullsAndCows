#include "pch.h" // Why do you bother me? I don't need a precompiled class that does nothing more than annoy me to the end.
#include <iostream>
#include <string>
using namespace std;

int main()
{
	constexpr int WORD_LENGTH = 9; // Word length. Will change from Constant to variable in future, but for the current version constant seems to work the best.
	string Guess = "";
    cout << "\nWelcome to Bulls and Cows\n"; 
	cout << "\nCan you think of " << WORD_LENGTH << " letter isogram I am thinking of?\n";
	cout << "\nEnter your guess: ";
	cin >> Guess;
	cout << "\nYour guess is : " << Guess << endl;
	return 0;
}
