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
            return LogNumber(next);
        }

        public int Next(int limit)
        {
            var next = rnd.Next(limit);
            return LogNumber(next);
        }

        public void WriteValuesToFile(string seedsFile)
        {
            using(TextWriter tw = new StreamWriter(seedsFile))
            {
                foreach (int s in _results)
                    tw.WriteLine(s);
            }
        }

        private int LogNumber(int next)
        {
            _results.Add(next);
            return next;
        }
    }
}