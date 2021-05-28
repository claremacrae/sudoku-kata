#include "SudokuKataCLR.h"
#include "ManagedObject.h"

#include "../SudokuKataCpp/SudokuKataCpp.h"

void SudokuKataCLR::SudokuCpp::Play()
{
}

String^ SudokuKataCLR::SudokuCpp::Line()
{
    return CLI::char_array_to_string(SudokuKataCpp::SudokuCpp::line());
}
