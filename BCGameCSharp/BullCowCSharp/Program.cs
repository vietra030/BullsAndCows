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
            throw new NotImplementedException();
        }

        private static void PrintIntro()
        {
            throw new NotImplementedException();
        }

        private static bool WillPlayAgain()
        {
            throw new NotImplementedException();
        }
    }
}
