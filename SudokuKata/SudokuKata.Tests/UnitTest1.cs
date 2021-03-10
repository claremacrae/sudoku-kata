using System;
using System.IO;
using ApprovalTests;
using Microsoft.VisualStudio.TestPlatform.TestHost;
using Xunit;
using SudokuKata;

namespace SudokuKata.Tests
{
    public class UnitTest1
    {
        [Fact]
        public void Test1()
        {
            var writer = new StringWriter();
            Console.SetOut(writer);
            for (int i = 0; i < 20; i++)
            {
                Program.Play(new Random(i));
            }
            Approvals.Verify(writer.ToString());
        }
    }
}