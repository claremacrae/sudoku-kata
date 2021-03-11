using System;
using SudokuKata;
using SudokuKata.Utilities;
using Xunit;

namespace SudokuKataTests
{
    public class GridTests
    {
        [Fact]
        public void ShouldConstructASolvedGridFromString()
        {
            var input  = "164589237532176948897423561985234716346917825721865394659348172278691453413752689";
            var solved = "000000000000000000000000000000000000000000000000000000000000000000000000000000000";
            var grid = new Grid(input);
            Assert.Equal(input, GridStringifier.ConvertToCode(grid._state));
            Assert.Equal(solved, GridStringifier.ConvertToCode(grid._finalState));
        }
    }
}
