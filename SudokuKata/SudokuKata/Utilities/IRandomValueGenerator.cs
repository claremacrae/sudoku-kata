namespace SudokuKata.Utilities
{
    public interface IRandomValueGenerator
    {
        int Next();
        int Next(int limit);
    }
}