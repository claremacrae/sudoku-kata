using ApprovalTests;
using SudokuKata;
using SudokuKata.Utilities;
using Xunit;

namespace SudokuKataTests
{
    public class GridStringifierTests
    {
        [Fact]
        public void TestPopulatedBoard()
        {
            // Assert
            int[] input =
            {
                4, 2, 9, 5, 3, 8, 6, 1, 7, 6, 3, 7, 9, 1, 4, 8, 2, 5, 8, 5, 1, 7, 6, 2, 4, 3, 9, 9, 7, 5, 6, 8, 3, 1, 4,
                2, 1, 6, 2, 4, 5, 7, 9, 8, 3, 3, 4, 8, 1, 2, 9, 5, 7, 6, 2, 1, 6, 8, 7, 5, 3, 9, 4, 5, 9, 3, 2, 4, 1, 7,
                6, 8, 7, 8, 4, 3, 9, 6, 2, 5, 1
            };
            VerifyBoardAsString(input);
        }

        [Fact]
        public void TestPopulatedBoardAsCode()
        {
            // TODO Are there sections, where I could use the input twice, for two separate outputs?
            // Assert
            int[] input =
            {
                4, 2, 9, 5, 3, 8, 6, 1, 7, 6, 3, 7, 9, 1, 4, 8, 2, 5, 8, 5, 1, 7, 6, 2, 4, 3, 9, 9, 7, 5, 6, 8, 3, 1, 4,
                2, 1, 6, 2, 4, 5, 7, 9, 8, 3, 3, 4, 8, 1, 2, 9, 5, 7, 6, 2, 1, 6, 8, 7, 5, 3, 9, 4, 5, 9, 3, 2, 4, 1, 7,
                6, 8, 7, 8, 4, 3, 9, 6, 2, 5, 1
            };
            VerifyBoardAsCode(input);
        }

        [Fact]
        public void TestPartialBoard()
        {
            // Assert
            int[] input =
            {
                0, 0, 0, 5, 0, 8, 0, 0, 7, 6, 0, 7, 0, 1, 0, 0, 2, 0, 0, 5, 0, 0, 0, 0, 0, 3, 9, 0, 7, 0, 6, 8, 0, 1, 0,
                0, 0, 6, 0, 0, 5, 7, 0, 0, 3, 0, 0, 8, 1, 0, 0, 0, 7, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 5, 9, 0, 0, 4, 1, 7,
                0, 0, 0, 0, 0, 3, 0, 0, 0, 5, 1
            };
            VerifyBoardAsString(input);
        }
        
        [Fact]
        public void TestPartialBoardAsCode()
        {
            // Assert
            int[] input =
            {
                0, 0, 0, 5, 0, 8, 0, 0, 7, 6, 0, 7, 0, 1, 0, 0, 2, 0, 0, 5, 0, 0, 0, 0, 0, 3, 9, 0, 7, 0, 6, 8, 0, 1, 0,
                0, 0, 6, 0, 0, 5, 7, 0, 0, 3, 0, 0, 8, 1, 0, 0, 0, 7, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 5, 9, 0, 0, 4, 1, 7,
                0, 0, 0, 0, 0, 3, 0, 0, 0, 5, 1
            };
            VerifyBoardAsCode(input);
        }

        private static void VerifyBoardAsString(int[] input)
        {
            Approvals.Verify(GridStringifier.ConvertToString(input));
        }

        private static void VerifyBoardAsCode(int[] input)
        {
            Approvals.Verify(GridStringifier.ConvertToCode(input));
        }
    }
}