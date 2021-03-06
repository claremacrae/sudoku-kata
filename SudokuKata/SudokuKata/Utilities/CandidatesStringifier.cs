namespace SudokuKata.Utilities
{
    public class CandidatesStringifier
    {
        public static string ConvertToString(int[] candidateMasks)
        {
            var blockDivider = "++=====+=====+=====++=====+=====+=====++=====+=====+=====++\n";
            var rowDivider = "++-----+-----+-----++-----+-----+-----++-----+-----+-----++\n";
            string result = blockDivider;

            for (int row = 0; row < 9; row++)
            {
                string line1 = "||";
                string line2 = "||";
                string line3 = "||";
                for (int col = 0; col < 9; col++)
                {
                    // var index = CellPosition.Index(row, col);
                    var index = (9 * row) + col;
                    var mask = candidateMasks[index];
                    line1 += RowForOneCell(index, mask, 1, 2, 3);
                    line2 += RowForOneCell(index, mask, 4, 5, 6);
                    line3 += RowForOneCell(index, mask, 7, 8, 9);
                }

                result += line1 + "\n";
                result += line2 + "\n";
                result += line3 + "\n";
                result += IsAtBlockBoundary(row) ? blockDivider : rowDivider;
            }

            return result;
        }

        private static bool IsAtBlockBoundary(int value)
        {
            return (value + 1) % 3 == 0;
        }

        private static string RowForOneCell(int index, int mask, int digitIndex1, int digitIndex2, int digitIndex3)
        {
            string result = " ";
            result += CharacterForDigit(mask, digitIndex1);
            result += CharacterForDigit(mask, digitIndex2);
            result += CharacterForDigit(mask, digitIndex3);
            result += IsAtBlockBoundary(index) ? " ||" : " |";
            return result;
        }

        private static string CharacterForDigit(int mask, int digit)
        {
            string blank = '.'.ToString();
            var digitMask = 1 << (digit - 1);
            var character = ((mask & digitMask) != 0) ? (digit).ToString() : blank;
            return character;
        }
    }
}