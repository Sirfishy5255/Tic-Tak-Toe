cmake_minimum_required(VERSION 3.20)
project(TicTacToe LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(tictactoe
    src/main.cpp
    src/game.cpp
)

target_include_directories(tictactoe PRIVATE include)
