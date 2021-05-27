using System;
using CLI;
using Xunit;

namespace SudokuKataTests
{
    [Collection("Sequential")]
    public class EntityTests
    {
        [Fact]
        public void CallCppCode()
        {
            Entity e = new Entity("The Wallman", 20, 35);
            e.Move(5, -10);
            Console.WriteLine(e.XPosition + " " + e.YPosition);
            //Console.Read();
        }
        
        [Fact]
        public void Is32Bit()
        {
            Assert.False(System.Environment.Is64BitProcess);
        }
    }
}
