using System;
using System.Collections.Generic;
using System.IO;

namespace SudokuKata
{
    public class FileWritingRandomNumber : IRandomValueGenerator
    {
        private Random rnd;
        List<int> _results = new List<int>();

        public FileWritingRandomNumber(Int32 seed)
        {
            rnd = new Random(seed);
        }

        public int Next()
        {
            var next = rnd.Next();
            _results.Add(next);
            // Console.WriteLine(">>> Next random number: {0}.", next);
            return next;
        }

        public int Next(int limit)
        {
            var next = rnd.Next(limit);
            _results.Add(next);
            // Console.WriteLine(">>> Next random number: {0} out of {1}.", next, limit);
            return next;
        }

        public void WriteValuesToFile(string seedsFile)
        {
            // System.IO.File.WriteAllLines(seedsFile, _results);
            using(TextWriter tw = new StreamWriter(seedsFile))
            {
                foreach (int s in _results)
                    tw.WriteLine(s);
            }
        }
    }
}