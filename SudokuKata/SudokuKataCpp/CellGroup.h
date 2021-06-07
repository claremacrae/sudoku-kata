#pragma once

#include <map>
#include <string>
#include <vector>

class CellGroup
{
public:
    int Discriminator = 0;
    std::string Description;
    int Index = 0;
    int Row = 0;
    int Column = 0;

public:
    // TODO Remove accessors - inline?
    int getDiscriminator() const;
    std::string getDescription() const;
    int getIndex() const;
    int getRow() const;
    int getColumn() const;

    CellGroup(int discriminator, const std::string& description, int index, int row, int column);

    std::string ToString() const;
};

// TODO Maybe remove after porting, for more realistic Kata!
using GroupsOfCells = std::vector<std::vector<CellGroup>>;
