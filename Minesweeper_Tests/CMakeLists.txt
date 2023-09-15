cmake_minimum_required(VERSION 3.10)

project(Minesweeper_Tests)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

set(TEST_SOURCES
        TestMinesweeper.cpp
)

add_executable(Minesweeper_Tests ${TEST_SOURCES})

target_link_libraries(Minesweeper_Tests PRIVATE MinesweeperLibrary)

#GetCatch2
find_package(Catch2)

target_link_libraries(Minesweeper_Tests PRIVATE Catch2::Catch2WithMain)

add_test(NAME Minesweeper_Tests COMMAND Minesweeper_Tests)
