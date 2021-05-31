using System;
using System.Collections.Generic;
using System.IO;

namespace SudokuKata
{
    public class FileWritingRandomNumber : IRandomValueGenerator
    {
        private RandomNumber rnd;
        List<int> _results = new List<int>();

        public FileWritingRandomNumber(Int32 seed)
        {
            rnd = new RandomNumber(seed);
        }

        public int Next()
        {
            var next = rnd.Next();
            _results.Add(next);
            return next;
        }

        public int Next(int limit)
        {
            var next = rnd.Next(limit);
            _results.Add(next);
            return next;
        }

        public void WriteValuesToFile(string seedsFile)
        {
            using(TextWriter tw = new StreamWriter(seedsFile))
            {
                foreach (int s in _results)
                    tw.WriteLine(s);
            }
        }
    }
}