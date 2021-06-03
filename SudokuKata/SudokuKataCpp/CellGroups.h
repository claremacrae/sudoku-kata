#include <map>
#include <string>
#include <vector>

class CellGroups
{
private:
    int Discriminator = 0;
    std::wstring Description;
    int Index = 0;
    int Row = 0;
    int Column = 0;

public:
    int getDiscriminator() const;
    std::wstring getDescription() const;
    int getIndex() const;
    int getRow() const;
    int getColumn() const;

    CellGroups(int discriminator, const std::wstring& description, int index, int row, int column);

    std::wstring ToString() const;
};

// TODO Maybe remove after porting, for more realistic Kata!
using CellGroupsMap = std::map<int, std::vector<CellGroups>>;
