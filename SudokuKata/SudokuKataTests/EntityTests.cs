﻿using System;
using CLI;
using Xunit;

namespace SudokuKataTests
{
    public class EntityTests
    {
        [Fact]
        public void CallCppCode()
        {
            Entity e = new Entity("The Wallman", 20, 35);
            e.Move(5, -10);
            Console.WriteLine(e.XPosition + " " + e.YPosition);
            Console.Read();
        }
    }
}
