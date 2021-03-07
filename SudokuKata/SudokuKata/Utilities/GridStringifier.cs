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
            return ToRow(board, o + 0, o + 1, o + 2, o + 3, o + 4, o + 5, o + 6, o + 7, o + 8);;
        }

        private static string ToRow(int[] board, int index0, int index1, int index2, int index3, int index4, int index5,
            int index6, int index7, int index8)
        {
            var row = "|";
            row += ToTriplet(board, index0, index1, index2);
            row += "|";
            row += ToTriplet(board, index3, index4, index5);
            row += "|";
            row += ToTriplet(board, index6, index7, index8);
            row += "|";
            row += "\n";
            return row;
        }

        private static string ToTriplet(int[] board, int index0, int index1, int index2)
        {
            var value1 = board[index0];
            var value2 = board[index1];
            var value3 = board[index2];
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
