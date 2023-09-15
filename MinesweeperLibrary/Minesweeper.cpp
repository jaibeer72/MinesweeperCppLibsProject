//
// Created by Jaibeer Dugal on 15/09/2023.
//

#include "Minesweeper.hpp"
#include <stdexcept>
#include <unordered_set>
#include <cstdlib>
#include <ctime>

// For Randome mine placement
Minesweeper::Minesweeper(int rows, int col, int mines) : m_Rows{rows}, m_Columns{col},m_MineCount{mines}
{
    InitializeBoard(m_Rows, m_Columns);
    m_MineLocations = GenerateRandomMines(m_Rows,m_Columns , m_MineCount);
    PlaceMines(m_MineLocations);
    CalculateNeighborMineCount();
}
Minesweeper::Minesweeper(int rows, int col, std::vector<std::pair<int, int>> mineLocations)
        : m_Rows{rows}, m_Columns{col}, m_MineLocations(mineLocations)
{
    m_MineCount = (int)mineLocations.size();
    InitializeBoard(m_Rows,m_Columns );
    PlaceMines(m_MineLocations);
    CalculateNeighborMineCount();
}

void Minesweeper::PlaceMines(const std::vector<std::pair<int, int>> &mineLocations) {
    for(int i = 0; i < m_MineCount; i++){
        std::pair<int,int> loc = mineLocations[i];
        m_Grid[loc.first][loc.second].IsMine = true;
    }
}

void Minesweeper::InitializeBoard(int rows, int col) {
    if(m_MineCount > rows * col)
        throw new std::runtime_error("number of mines are greater than the grid size");

    m_Grid.resize(m_Rows, std::__1::vector<Cell>(m_Columns));
}

void Minesweeper::resetBoard(bool samePos) {
    // clear the grid
    m_Grid.clear();
    if(!samePos)
    {
        m_MineLocations = GenerateRandomMines(m_Rows,m_Columns,m_MineCount);
    }
    InitializeBoard(m_Rows,m_Columns);
    PlaceMines(m_MineLocations);
}

void Minesweeper::revealCell(int row, int col , std::vector<std::pair<int,int>>& revealNumberedCells) {
    // row conditions doing this for readability
    if(row< 0 || row > m_Rows || col < 0 || col > m_Columns || m_Grid[row][col].IsOpen || m_Grid[row][col].IsMine)
        return;

    m_Grid[row][col].IsOpen = true;

    if(m_Grid[row][col].NeighborMineCount >0){
        revealNumberedCells.push_back(std::pair<int,int>(row,col));
        return;
    }

    if(m_Grid[row][col].NeighborMineCount == 0){
        for(const auto& offset : m_Offsets){
            int nx = row + offset.first;
            int ny = col + offset.second;
            revealCell(nx,ny, revealNumberedCells);
        }
    }
}

bool Minesweeper::isMine(int row, int col) {
    return m_Grid[row][col].IsMine;
}

bool Minesweeper::CalculateNeighborMineCount() {
    for(int i = 0; i < m_Rows; ++i) {
        for(int j = 0; j < m_Columns; ++j) {
            int neighborMineCount = 0;
            for(const auto& offset : m_Offsets) {
                int ni = i + offset.first;
                int nj = j + offset.second;
                if(ni >= 0 && ni < m_Rows && nj >= 0 && nj < m_Columns && m_Grid[ni][nj].IsMine) {
                    ++neighborMineCount;
                }
            }
            m_Grid[i][j].NeighborMineCount = neighborMineCount;
        }
    }
    return true;
}

std::vector<std::pair<int, int>> Minesweeper::GenerateRandomMines(int rows, int columns, int numMines) {
    std::srand(std::time(0)); // Use current time as seed for random generator

    std::unordered_set<int> uniquePositions;
    std::vector<std::pair<int, int>> minePositions;

    while (minePositions.size() < numMines) {
        int randomRow = std::rand() % rows;
        int randomColumn = std::rand() % columns;
        int uniqueKey = randomRow * columns + randomColumn; // Create a unique key for the position

        // Check if the position is unique
        if (uniquePositions.find(uniqueKey) == uniquePositions.end()) {
            uniquePositions.insert(uniqueKey);
            minePositions.push_back({randomRow, randomColumn});
        }
    }

    return minePositions;
}

bool Minesweeper::isOpen(int row, int col) {
    return m_Grid[row][col].IsOpen;
}
