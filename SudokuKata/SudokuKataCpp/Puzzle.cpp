#include <unordered_map>
#include <stack>
#include <numeric>
#include <map>
#include <iostream>
#include <deque>
#include <algorithm>
#include <fmt/format.h>
#include "TwoDigitMaskGroups.h"
#include "GroupsWithNMasks.h"
#include "CellGroup.h"
#include "Program.h"
#include "Puzzle.h"

std::vector<int> SudokuKata::Puzzle::ConstructBoardToSolve(std::__1::vector<std::vector<char>>& board,
                                                IRandomValueGenerator* rng)
{
    // Construct board to be solved

    // Top element is current state of the board
    std::__1::stack<std::vector<int>> stateStack;

    // Top elements are (row, col) of cell which has been modified compared to previous state
    std::stack<int> rowIndexStack;
    std::stack<int> colIndexStack;

    // Top element indicates candidate digits (those with False) for (row, col)
    std::__1::stack<std::vector<bool>> usedDigitsStack;

    // Top element is the value that was set on (row, col)
    std::stack<int> lastDigitStack;

    // Indicates operation to perform next
    // - expand - finds next empty cell and puts new state on stacks
    // - move - finds next candidate number at current pos and applies it to current state
    // - collapse - pops current state from stack as it did not yield a solution
    std::string command = "expand";
    while (stateStack.size() <= 9 * 9)
    {
        if (command == "expand")
        {
            std::vector<int> currentState(9 * 9);

            if (!stateStack.empty())
            {
                std::copy_n(
                    stateStack.top().begin(), currentState.size(), currentState.begin());
            }

            int bestRow = -1;
            int bestCol = -1;
            std::vector<bool> bestUsedDigits;
            int bestCandidatesCount = -1;
            int bestRandomValue = -1;
            bool containsUnsolvableCells = false;

            for (int index = 0; index < currentState.size(); index++)
            {
                if (currentState[index] == 0)
                {

                    int row = index / 9;
                    int col = index % 9;
                    int blockRow = row / 3;
                    int blockCol = col / 3;

                    std::vector<bool> isDigitUsed(9);

                    for (int i = 0; i < 9; i++)
                    {
                        int rowDigit = currentState[9 * i + col];
                        if (rowDigit > 0)
                        {
                            isDigitUsed[rowDigit - 1] = true;
                        }

                        int colDigit = currentState[9 * row + i];
                        if (colDigit > 0)
                        {
                            isDigitUsed[colDigit - 1] = true;
                        }

                        int blockDigit =
                            currentState[(blockRow * 3 + i / 3) * 9 + (blockCol * 3 + i % 3)];
                        if (blockDigit > 0)
                        {
                            isDigitUsed[blockDigit - 1] = true;
                        }
                    } // for (i = 0..8)

                    auto candidatesCount =
                        std::count(isDigitUsed.begin(), isDigitUsed.end(), false);

                    if (candidatesCount == 0)
                    {
                        containsUnsolvableCells = true;
                        break;
                    }

                    int randomValue = rng->Next();

                    if (bestCandidatesCount < 0 || candidatesCount < bestCandidatesCount ||
                        (candidatesCount == bestCandidatesCount &&
                         randomValue < bestRandomValue))
                    {
                        bestRow = row;
                        bestCol = col;
                        bestUsedDigits = isDigitUsed;
                        bestCandidatesCount = candidatesCount;
                        bestRandomValue = randomValue;
                    }

                } // for (index = 0..81)
            }

            if (!containsUnsolvableCells)
            {
                stateStack.push(currentState);
                rowIndexStack.push(bestRow);
                colIndexStack.push(bestCol);
                usedDigitsStack.push(bestUsedDigits);
                lastDigitStack.push(0); // No digit was tried at this position
            }

            // Always try to move after expand
            command = "move";

        } // if (command == "expand")
        else if (command == "collapse")
        {
            stateStack.pop();
            rowIndexStack.pop();
            colIndexStack.pop();
            usedDigitsStack.pop();
            lastDigitStack.pop();

            command = "move"; // Always try to move after collapse
        }
        else if (command == "move")
        {

            int rowToMove = rowIndexStack.top();
            int colToMove = colIndexStack.top();
            int digitToMove = lastDigitStack.top();
            lastDigitStack.pop();

            int rowToWrite = rowToMove + rowToMove / 3 + 1;
            int colToWrite = colToMove + colToMove / 3 + 1;

            std::vector<bool>& usedDigits = usedDigitsStack.top();
            std::vector<int>& currentState = stateStack.top();
            int currentStateIndex = 9 * rowToMove + colToMove;

            int movedToDigit = digitToMove + 1;
            while (movedToDigit <= 9 && usedDigits[movedToDigit - 1])
            {
                movedToDigit += 1;
            }

            if (digitToMove > 0)
            {
                usedDigits[digitToMove - 1] = false;
                currentState[currentStateIndex] = 0;
                board[rowToWrite][colToWrite] = '.';
            }

            if (movedToDigit <= 9)
            {
                lastDigitStack.push(movedToDigit);
                usedDigits[movedToDigit - 1] = true;
                currentState[currentStateIndex] = movedToDigit;
                board[rowToWrite][colToWrite] = static_cast<char>('0' + movedToDigit);

                // Next possible digit was found at current position
                // Next step will be to expand the state
                command = "expand";
            }
            else
            {
                // No viable candidate was found at current position - pop it in the next iteration
                lastDigitStack.push(0);
                command = "collapse";
            }
        } // if (command == "move")
    }

    return stateStack.top();
}

std::__1::vector<std::vector<char>> SudokuKata::Puzzle::ConstructFullBoard()
    {
        // Prepare empty board
        std::string line = "+---+---+---+";
        std::string middle = "|...|...|...|";
        return {std::vector<char>(line.begin(), line.end()),
                std::vector<char>(middle.begin(), middle.end()),
                std::vector<char>(middle.begin(), middle.end()),
                std::vector<char>(middle.begin(), middle.end()),
                std::vector<char>(line.begin(), line.end()),
                std::vector<char>(middle.begin(), middle.end()),
                std::vector<char>(middle.begin(), middle.end()),
                std::vector<char>(middle.begin(), middle.end()),
                std::vector<char>(line.begin(), line.end()),
                std::vector<char>(middle.begin(), middle.end()),
                std::vector<char>(middle.begin(), middle.end()),
                std::vector<char>(middle.begin(), middle.end()),
                std::vector<char>(line.begin(), line.end())};
    }