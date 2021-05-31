using System.Collections.Generic;
using System.IO;

namespace SudokuKata
{
    public class FileReadingRandomNumber : IRandomValueGenerator
    {
        Queue<int> _results = new Queue<int>();

        public FileReadingRandomNumber()
        {
            // User must call ReadValuesFromFile() to complete the initialisation
        }

        public int Next()
        {
            var result = _results.Dequeue();
            return result;
        }

        public int Next(int limit)
        {
            // limit is intentionally unused
            return Next();
        }

        public void ReadValuesFromFile(string seedsFile)
        {
            using (TextReader reader = File.OpenText(seedsFile))
            {
                string line;
                while ((line = reader.ReadLine()) != null)
                {
                    int r = int.Parse(line);
                    _results.Enqueue(r);
                }
            }
        }
    }
}
