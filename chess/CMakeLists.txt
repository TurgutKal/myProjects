cmake_minimum_required(VERSION 3.16)

project(chess LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(chess main.cpp
    piece.h piece.cpp
    king.h king.cpp
    queen.h queen.cpp
    pawn.h pawn.cpp
    knight.h knight.cpp
    bishop.h bishop.cpp
    rook.h rook.cpp
    gameboard.h gameboard.cpp
    gamelogic.h gamelogic.cpp)

include(GNUInstallDirs)
install(TARGETS chess
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
