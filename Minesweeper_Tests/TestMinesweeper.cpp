//
// Created by Jaibeer Dugal on 15/09/2023.
//
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch2/catch_all.hpp"
#include "../MinesweeperLibrary/Minesweeper.hpp"

TEST_CASE("Minesweeper Class Tests","[minesweeper]"){
    SECTION("Randome mine placement making sure are all"){
        Minesweeper ms(5,5,25);
        REQUIRE(ms.isMine(0,0)== true);
    }
    SECTION("Test constructor with specified mine locations") {
        std::vector<std::pair<int, int>> mineLocations = {{0, 0}, {1, 1}, {2, 2}};
        Minesweeper ms(10, 10, mineLocations);
        REQUIRE(ms.isMine(0, 0) == true);
        REQUIRE(ms.isMine(1, 1) == true);
        REQUIRE(ms.isMine(2, 2) == true);
        REQUIRE(ms.isMine(3, 3) == false);
    }
    SECTION("Test revealCell method to revel one cell ") {
        /*
         *  x * *                                           x * 1
         *  * x *  clicking on (0,2) should only -> * x *
         *  * 0 *                                           * x *
         */
        std::vector<std::pair<int, int>> mineLocations = {{0, 0}, {1, 1}, {2, 2}};
        Minesweeper ms(3, 3, mineLocations);
        std::vector<std::pair<int, int>> revealNumberedCells;
        ms.revealCell(0, 2, revealNumberedCells);
        REQUIRE(ms.isOpen(0,2) == true);
        REQUIRE(ms.isOpen(0,1) == false);
        REQUIRE(ms.isOpen(1,2)==false);
    }
}