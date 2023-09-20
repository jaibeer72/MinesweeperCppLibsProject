//
// Created by Jaibeer Dugal on 16/09/2023.
//

#include "Minesweeper.hpp"

extern "C" {

MINESWEEPERLIB_API Minesweeper* Minesweeper_Create(int rows, int cols, int mines) {
    return new Minesweeper(rows, cols, mines);
}

MINESWEEPERLIB_API Minesweeper* Minesweeper_CreateCustom(int rows, int cols, int* mineLocations, int size) {
    std::vector<std::pair<int, int>> minePositions;
    for(int i = 0; i < size; ++i) {
        minePositions.push_back({mineLocations[i*2], mineLocations[i*2 + 1]});
    }
    return new Minesweeper(rows, cols, minePositions);
}

MINESWEEPERLIB_API void Minesweeper_Destroy(Minesweeper* minesweeper) {
    delete minesweeper;
}

MINESWEEPERLIB_API void Minesweeper_ResetBoard(Minesweeper* minesweeper, bool samePos) {
    minesweeper->resetBoard(samePos);
}

MINESWEEPERLIB_API void Minesweeper_RevealCell(Minesweeper* minesweeper, int row, int col, int* revealedCellsWithNum, int* size, int* revealedCellsWithoutNum, int* size2) {
    std::vector<std::pair<int, int>> revealNumberedCells;
    std::vector<std::pair<int, int>> revealNonNumberedCells;
    minesweeper->revealCell(row, col, revealNumberedCells, revealNonNumberedCells);
    *size = revealNumberedCells.size();
    *size2 = revealNonNumberedCells.size();
    for(int i = 0; i < *size; ++i) {
        revealedCellsWithNum[i*2] = revealNumberedCells[i].first;
        revealedCellsWithNum[i*2 + 1] = revealNumberedCells[i].second;
    }
    for(int i =0; i< *size2 ; ++i)
    {
        revealedCellsWithoutNum[i*2] = revealNonNumberedCells[i].first;
        revealedCellsWithoutNum[i*2 + 1] = revealNonNumberedCells[i].second;
    }
}

MINESWEEPERLIB_API bool Minesweeper_IsMine(Minesweeper* minesweeper, int row, int col) {
    return minesweeper->isMine(row, col);
}

MINESWEEPERLIB_API bool Minesweeper_IsOpen(Minesweeper* minesweeper, int row, int col) {
    return minesweeper->isOpen(row, col);
}

MINESWEEPERLIB_API void Minesweeper_SetCustomeMines(Minesweeper* minesweeper, int rows, int cols, int* mineLocations, int size) {
    std::vector<std::pair<int, int>> minePositions;
    for(int i = 0; i < size; ++i) {
        minePositions.push_back({mineLocations[i*2], mineLocations[i*2 + 1]});
    }
    minesweeper->setCustomeMines(rows, cols, minePositions);
}

MINESWEEPERLIB_API bool Minesweeper_GetIfTileIsNumbered(Minesweeper* minesweeper, int row , int col, int* num){
    return minesweeper->getNumIfNumberedTile(row,col,*num);
}
}
