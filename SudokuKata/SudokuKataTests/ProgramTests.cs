using ApprovalTests;
using SudokuKata;
using System;
using SudokuKata.Utililities;
using Xunit;

namespace SudokuKataTests
{
    public class ProgramTests
    {
        [Fact]
        public void Test1()
        {
            VerifySudokuForSeed(42);
        }
        
        [Fact]
        public void Test2()
        {
            VerifySudokuForSeed(1);
        }
        
        [Fact]
        public void Test3()
        {
            // this one reaches 'block' description
            VerifySudokuForSeed(4);
        }

        [Fact]
        public void Test4()
        {
            // this one reaches 'fail' description - although the calculation does complete
            VerifySudokuForSeed(6);
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
