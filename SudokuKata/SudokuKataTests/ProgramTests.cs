using ApprovalTests;
using SudokuKata;
using System;
using System.IO;
using ApprovalTests.Namers;
using SudokuKataTests.TestHelpers;
using Xunit;
using Xunit.Abstractions;

namespace SudokuKataTests
{
    [Collection("Sequential")]
    //  ^^^ Prevent running in parallel with other tests that write to console
    //  This test works by capturing any output to standard output.
    //  It must not run in parallel with any other tests that also write to standard output.
    //  Any other tests that also capture console output should also be put in the same Collection.
    //  See https://stackoverflow.com/a/47174842/104370
    public class ProgramTests
    {
        private readonly ITestOutputHelper _testOutputHelper;

        public ProgramTests(ITestOutputHelper testOutputHelper)
        {
            _testOutputHelper = testOutputHelper;
        }

        [Fact]
        public void TestSeed()
        {
            var errors = 0;
            for (int seed = 0; seed < 20; seed++)
            {
                var section = SeedSectionName(seed);
                using (var cleanup = NamerFactory.AsEnvironmentSpecificTest("" + section))
                {
                    try
                    {
                        VerifySudokuForSeed(seed);
                    }
                    catch (Exception e)
                    {
                        _testOutputHelper.WriteLine(e.ToString());
                        errors += 1;
                    }
                }
            }
            Assert.Equal(0, errors);
        }

        private static string SeedSectionName(int seed)
        {
            return $"{seed:D4}";
        }

        private static void VerifySudokuForSeed(int seed)
        {
            var randomValueGenerator = new FileWritingRandomNumber(seed);
            var currentConsoleOut = Console.Out;
            using (var consoleOutput = new ConsoleUtilities.ConsoleOutput())
            {
                Program.Play(randomValueGenerator);
                string s = consoleOutput.GetOuput();
                Approvals.Verify(s);
            }

            {
                var namer = Approvals.GetDefaultNamer();
                var basename = Path.Combine(namer.SourcePath, namer.Name);
                var section = SeedSectionName(seed);
                var seedsFile = basename + "." + section + ".seeds.txt";
                Console.WriteLine(seedsFile);
                randomValueGenerator.WriteValuesToFile(seedsFile);

            }
            Assert.Equal(currentConsoleOut, Console.Out);
        }
    }
}