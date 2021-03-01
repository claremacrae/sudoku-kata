using ApprovalTests;
using SudokuKata;
using System;
using ApprovalTests.Namers;
using ApprovalTests.Reporters;
using SudokuKata.Utilities;
using Xunit;
using Xunit.Abstractions;

namespace SudokuKataTests
{
    public class ProgramTests
    {
        private readonly ITestOutputHelper _testOutputHelper;

        public ProgramTests(ITestOutputHelper testOutputHelper)
        {
            _testOutputHelper = testOutputHelper;
        }

        [Fact]
        // [UseReporter(typeof(AllFailingTestsClipboardReporter ))]
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
                Program.Play(new RandomNumber(seed));
                string s = consoleOutput.GetOuput();
                Approvals.Verify(s);
            }
            Assert.Equal(currentConsoleOut, Console.Out);
        }
    }
}