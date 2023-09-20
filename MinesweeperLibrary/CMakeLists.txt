cmake_minimum_required(VERSION 3.10)

project(MinesweeperLibrary)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
        Minesweeper.cpp
        MinesweeperWrapper.cpp
)

if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    set(OUTPUT_NAME "lib_windowsMineSweeper")
elseif(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    set(OUTPUT_NAME "lib_appleMineSweeper")
else()
    set(OUTPUT_NAME "lib_MineSweeper")
endif()

add_library(MinesweeperLibrary SHARED ${SOURCES})

target_include_directories(MinesweeperLibrary PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Define MINESWEEPERLIBRARY_EXPORTS for DLL export
target_compile_definitions(MinesweeperLibrary PRIVATE MINESWEEPERLIBRARY_EXPORTS)
