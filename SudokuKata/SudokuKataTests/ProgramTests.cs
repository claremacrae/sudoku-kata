using ApprovalTests;
using SudokuKata;
using System;
using ApprovalTests.Namers;
using SudokuKata.Utilities;
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
                var section = $"{seed:D4}";
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
        
        private static void VerifySudokuForSeed(int seed)
        {
            var currentConsoleOut = Console.Out;
            using (var consoleOutput = new ConsoleUtilities.ConsoleOutput())
            {
                Program.Play(new Random(seed));
                string s = consoleOutput.GetOuput();
                Approvals.Verify(s);
            }
            Assert.Equal(currentConsoleOut, Console.Out);
        }
        
        [Fact]
        public void ShouldSolveGrid()
        {
            // See Easy https://www.websudoku.com/?level=1&set_id=2417252423
            var input    = "004509000500100048090020560000030016340010025720060000059040070270001003000702600";
            var expected = "164589237532176948897423561985234716346917825721865394659348172278691453413752689";

            var inputDigits = new int[81];
            Assert.Equal(81, input.Length);
            for (var i = 0; i < input.Length; i++)
            {
                var character = input[i];
                var digit = (int)char.GetNumericValue(character);
                inputDigits[i] = digit;
            }

            var finalState = new int[81];
            var grid = new Grid(inputDigits, finalState);
            Program.SolveBoard(new Random(0), grid);
            Assert.Equal(expected, GridStringifier.ConvertToCode(grid._state));
        }
    }
}