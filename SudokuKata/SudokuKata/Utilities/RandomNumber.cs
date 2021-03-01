using System;

namespace SudokuKata.Utilities
{
    public class RandomNumber : IRandomValueGenerator
    {
        private Random rnd;
        public RandomNumber()
        {
            rnd = new Random();
        }

        public RandomNumber(Int32 seed)
        {
            rnd = new Random(seed);
        }

        public int Next()
        {
            var next = rnd.Next();
            // Console.WriteLine(">>> Next random number: {0}.", next);
            return next;
        }

        public int Next(int limit)
        {
            var next = rnd.Next(limit);
            // Console.WriteLine(">>> Next random number: {0} out of {1}.", next, limit);
            return next;
        }
    }
}