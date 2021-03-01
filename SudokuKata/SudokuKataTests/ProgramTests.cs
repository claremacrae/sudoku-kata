using ApprovalTests;
using SudokuKata;
using System;
using System.IO;
using SudokuKata.Utililities;
using Xunit;

namespace SudokuKataTests
{
    public class ProgramTests
    {

        // From http://www.vtrifonov.com/2012/11/getting-console-output-within-unit-test.html
        public class ConsoleOutput : IDisposable
        {
            private StringWriter stringWriter;
            private TextWriter originalOutput;

            public ConsoleOutput()
            {
                stringWriter = new StringWriter();
                originalOutput = Console.Out;
                Console.SetOut(stringWriter);
            }

            public string GetOuput()
            {
                return stringWriter.ToString();
            }

            public void Dispose()
            {
                Console.SetOut(originalOutput);
                stringWriter.Dispose();
            }
        }

 
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
            using (var consoleOutput = new ConsoleOutput())
            {
                Program.Play(new RandomNumber(seed));
                string s = consoleOutput.GetOuput();
                Approvals.Verify(s);
            }
            Assert.Equal(currentConsoleOut, Console.Out);
        }
    }
}
