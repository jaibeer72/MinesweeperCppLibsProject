//
// Created by Jaibeer Dugal on 15/09/2023.
//

#ifndef MINESWEEPERPROJECT_MINESWEEPER_HPP
#define MINESWEEPERPROJECT_MINESWEEPER_HPP

// Define the export macro
#ifdef _WIN32
#ifdef MINESWEEPERLIB_EXPORTS
        #define MINESWEEPERLIB_API __declspec(dllexport)
    #else
        #define MINESWEEPERLIB_API __declspec(dllimport)
    #endif
#else // define for mac
#define MINESWEEPERLIB_API
#endif

#include "Cell.hpp"
#include <vector>

class MINESWEEPERLIB_API Minesweeper {
public:
    Minesweeper(int rows , int col , int mines);
    Minesweeper(int rows , int col , std::vector<std::pair<int,int>> mineLocations);
    void resetBoard(bool samePos = false);
    void revealCell(int row, int col, std::vector<std::pair<int,int>>& revealNumberedCells);
    bool isMine(int row, int col);
    bool isOpen(int row , int col);
private:
    std::vector<std::vector<Cell>> m_Grid;
    int m_MineCount;
    int m_Rows,m_Columns;
    // testing m_Offsets for calculation
    std::vector<std::pair<int, int>> m_Offsets = {
            {-1, -1}, {-1, 0}, {-1, 1},
            {0, -1},           {0, 1},
            {1, -1}, {1, 0}, {1, 1}
    };
    std::vector<std::pair<int, int>> m_MineLocations;
    //private functions
private:
    bool CalculateNeighborMineCount();


    void InitializeBoard(int rows, int col);

    void PlaceMines(const std::vector<std::pair<int, int>> &mineLocations);

    std::vector<std::pair<int, int>> GenerateRandomMines(int rows, int columns, int numMines);
};


#endif //MINESWEEPERPROJECT_MINESWEEPER_HPP
