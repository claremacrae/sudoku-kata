using System.Collections.Generic;
using System.Linq;

namespace SudokuKata
{
    public class GroupsWithNMasks
    {
        public int Mask { get; set; }
        public string Description { get; set; }
        public IGrouping<int, CellGroups> Cells { get; set; }
        public List<CellGroups> CellsWithMask { get; set; }
        public int CleanableCellsCount { get; set; }

        public override string ToString()
        {
            // string result
            //     = $"{{ Mask = {Mask}, Description = {Description}, Cells = {Cells}, CellsWithMask =\n{string.Join("\n", CellsWithMask)}, CleanableCellsCount =\n{string.Join("\n", CleanableCellsCount)} }}";
            string result
                = $"{{ Mask = {Mask}, Description = {Description}, Cells = {Cells.Count()}, CellsWithMask = {CellsWithMask.Count}, CleanableCellsCount = {CleanableCellsCount}";
            
            return result;
        }
    }
}