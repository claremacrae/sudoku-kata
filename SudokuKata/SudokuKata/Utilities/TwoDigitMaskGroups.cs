using System.Linq;

namespace SudokuKata
{
    public class TwoDigitMaskGroups
    {
        public int Mask { get; }
        public int Discriminator { get; }
        public string Description { get; }
        public IGrouping<int, CellGroups> Cells { get; }

        public TwoDigitMaskGroups(int mask, int discriminator, string description, IGrouping<int, CellGroups> cells)
        {
            Mask = mask;
            Discriminator = discriminator;
            Description = description;
            Cells = cells;
        }

        public override string ToString()
        {
            var result = $"{nameof(Mask)}: {Mask}, {nameof(Discriminator)}: {Discriminator}, {nameof(Description)}: {Description}\n";
            foreach (var cellGroups in Cells)
            {
                result += $"   {cellGroups.ToString()}\n";
            }

            return result;
        }
    }
}