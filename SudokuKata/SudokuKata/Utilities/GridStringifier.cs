using System;

namespace SudokuKata.Utilities
{
    public class GridStringifier
    {
        public static string ConvertToString(int[] board)
        {
            const string divider = "+---+---+---+\n";
            var result = divider;
            result += ToRowNumbered(board, 0);
            result += ToRowNumbered(board, 1);
            result += ToRowNumbered(board, 2);
            result += divider;
            result += ToRowNumbered(board, 3);
            result += ToRowNumbered(board, 4);
            result += ToRowNumbered(board, 5);
            result += divider;
            result += ToRowNumbered(board, 6);
            result += ToRowNumbered(board, 7);
            result += ToRowNumbered(board, 8);
            result += divider;
            return result;
        }

        private static string ToRowNumbered(int[] board, int row)
        {
            var o = row * 9;
            var row1 = "|";
            row1 += ToTriplet(board, o + 0);
            row1 += "|";
            row1 += ToTriplet(board, o + 3);
            row1 += "|";
            row1 += ToTriplet(board, o + 6);
            row1 += "|";
            row1 += "\n";
            return row1;
            ;
        }

        private static string ToTriplet(int[] board, int index0)
        {
            var value1 = board[index0];
            var value2 = board[index0 + 1];
            var value3 = board[index0 + 2];
            return ToCell(value1) + ToCell(value2) + ToCell(value3);
        }

        private static string ToCell(int value)
        {
            return value == 0 ? "." : Convert.ToString(value);
        }

        public static string ConvertToCode(int[] board)
        {
            return string.Join(string.Empty, board);
        }
    }
}
