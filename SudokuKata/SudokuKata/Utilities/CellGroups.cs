namespace SudokuKata
{
    public class CellGroups
    {
        public int Discriminator { get; }
        public string Description { get; }
        public int Index { get; }
        public int Row { get; }
        public int Column { get; }

        public CellGroups(int discriminator, string description, int index, int row, int column)
        {
            Discriminator = discriminator;
            Description = description;
            Index = index;
            Row = row;
            Column = column;
        }

        public override string ToString()
        {
            return
                $"{nameof(Discriminator)}: {Discriminator}, {nameof(Description)}: {Description}, {nameof(Index)}: {Index}, {nameof(Row)}: {Row}, {nameof(Column)}: {Column}";
        }
    }
}