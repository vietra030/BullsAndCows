using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BullCowCSharp
{
    class BullsAndCows
    {
        public BullsAndCows()
        {

        }

        public BullsAndCows(int x)
        {

        }

        public int MaxTries { get; private set; }
        public int CurrentTry { get; private set; }
        public bool IsGameWon { get; private set; }
        private int secretPosition; // This is where the differences might start appearing
        private List<string> wordCol = new List<string> { "brick", "blind", "simple", "sample", "world" };

        //Private methods
        private void SetSecretWord()
        {

        }

        // Instead of creating a struct I can use a Tuple<> in C#.

        public int GetWordLength() => 0; // TODO : Flesh it out more

        public Tuple<int, int> SubmitGuess(string guess)
        {
            var bull = 0;
            var cow = 0;
            return Tuple.Create(bull, cow);
        }

        public GuessStatus IsGuessValid(string guess)
        {
            throw new NotImplementedException();
        }
    }
}
