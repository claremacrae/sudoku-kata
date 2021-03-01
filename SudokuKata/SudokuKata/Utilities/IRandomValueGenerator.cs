namespace SudokuKata.Utililities
{
    public interface IRandomValueGenerator
    {
        int Next();
        int Next(int limit);
    }
}