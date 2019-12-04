cmake_minimum_required(VERSION 3.15)
project(HW_02)

set(CMAKE_CXX_STANDARD 14)

add_executable(test src/BoardView.cpp include/BoardView.h
        src/Board.cpp include/Board.h src/Test.cpp include/Test.h src/BoardTest.cpp
        include/BoardTest.h src/test.cpp)

add_executable(HW_02 src/main.cpp
        src/BoardView.cpp
        include/BoardView.h
        src/Board.cpp
        include/Board.h src/NCursesBoardView.cpp include/NCursesBoardView.h)