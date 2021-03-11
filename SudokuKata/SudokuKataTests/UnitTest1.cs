using System;
using System.IO;
using ApprovalTests;
using SudokuKata;
using Xunit;

namespace SudokuKataTests
{
    public class UnitTest1
    {
        [Fact]
        public void ShouldDoTheSameThingTwice()
        {
            TextWriter capture = new StringWriter();
            Console.SetOut(capture);
            for (int i = 0; i < 10; i++)
            {
                Program.Play(new Random(i));
            }
            Approvals.Verify(capture);
        }
    }
}
