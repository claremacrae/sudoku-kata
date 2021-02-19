using ApprovalTests;
using ApprovalTests.Reporters;
using SudokuKata;
using System;
using System.IO;
using Xunit;

namespace SudokuKataTests
{
    public class UnitTest1
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

 
        [UseReporter(typeof(AraxisMergeReporter))]
        [Fact]
        public void Test1()
        {
            var currentConsoleOut = Console.Out;
            using (var consoleOutput = new ConsoleOutput())
            {
                SudokuKata.Program.Play(new Random(42));
                string s = consoleOutput.GetOuput();
                Approvals.Verify(s);
            }
            Assert.Equal(currentConsoleOut, Console.Out);
        }
    }
}
