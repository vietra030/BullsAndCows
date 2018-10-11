using System;
using static System.Console;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BullCowCSharp
{
    class Program
    {
        static BullsAndCows BCGame = new BullsAndCows();
        static void Main(string[] args)
        {
            do
            {
                PrintIntro();
                PlayGame();
            } while (WillPlayAgain());
            WriteLine();
        }

        private static void PlayGame()
        {
            var temp = BCGame.MaxTries;
            while (temp > 0 && !BCGame.IsGameWon)
            {
                var guess = GetStatus();
                WriteLine();
                var status = BCGame.IsGuessValid(guess);
                switch (status)
                {
                    case GuessStatus.OK:
                        PrintStatus(guess);
                        temp--;
                        break;
                    case GuessStatus.Not_Isogram:
                        WriteLine("Please enter an ISOGRAM (A word with no repeating letters).");
                        break;
                    case GuessStatus.Invalid_Length:
                        WriteLine($"Please enter a {BCGame.GetWordLength()} letter word."); // Another big advantage of C# over java. String interpolation. No need to concatinate string with + operator.
                        break;
                    default:
                        break;
                }
            }
            PrintGameSummary();
        }

        private static void PrintGameSummary()
        {
            if (BCGame.IsGameWon)
            {
                WriteLine($"Congratulations! You have successfully guessed the correct word. You only took {BCGame.CurrentTry - 1} tries.");
            }
            else
            {
                WriteLine("Sorry you failed to beat the game. Better luck next time.");
            }
        }

        private static void PrintStatus(string guess)
        {
            var count = BCGame.SubmitGuess(guess);
            WriteLine($"Bulls : {count.Item1}\tCows : {count.Item2}");
        }

        private static string GetStatus()
        {
            string guess;
            if (BCGame.CurrentTry == 1)
            {
                WriteLine($"Enter your {BCGame.CurrentTry} st guess:");
            }
            else if (BCGame.CurrentTry == 2)
            {
                WriteLine($"Enter your {BCGame.CurrentTry} nd guess:");
            }
            else if (BCGame.CurrentTry == 3)
            {
                WriteLine($"Enter your {BCGame.CurrentTry} rd guess:");
            }
            else
            {
                WriteLine($"Enter your {BCGame.CurrentTry} th guess:");
            }
            guess = ReadLine();
            return guess;
        }

        private static void PrintIntro()
        {
            Clear();
            BCGame.Reset();
            WriteLine("Welcome to Bulls and Cows");
            WriteLine();
            WriteLine("            }   {                 ____");
            WriteLine("            (o  o)               (o  o) ");
            WriteLine("    /--------\\  /                 \\  /---------\\");
            WriteLine("   / |        |O                    o|         | \\ ");
            WriteLine("  *  |-,------|                      |-------,,|  * ");
            WriteLine("     ^        ^                      ^         ^  ");
            WriteLine($"Can you think of {BCGame.GetWordLength()} letter isogram I am thinking of?");
            WriteLine($"You have a total of {BCGame.MaxTries} tries to guess it correctly.");
        }

        /*
         * This is the simpler implementation fo the WillPlayAgain() method
         * Here we only check for the yes condition and default everything else to a no.
         */
        private static bool WillPlayAgain()
        {
            string choice;
            WriteLine("Do you want to play again? (Y/N)");
            choice = ReadLine();
            if (choice[0] == 'Y' || choice[0] == 'y')
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
}
