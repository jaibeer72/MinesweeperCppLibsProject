//
// Created by Jaibeer Dugal on 15/09/2023.
//

#ifndef MINESWEEPERPROJECT_CELL_HPP
#define MINESWEEPERPROJECT_CELL_HPP
struct Cell{
    int Row{0},Col{0};
    int NeighborMineCount =0;
    bool IsOpen = false;
    bool IsMine = false;
};
#endif //MINESWEEPERPROJECT_CELL_HPP
