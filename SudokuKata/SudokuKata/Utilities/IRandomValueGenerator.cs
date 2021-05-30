namespace SudokuKata
{
    public interface IRandomValueGenerator
    {
        int Next();
        int Next(int limit);
    }
}