#include "bishop.h"
#include "gameboard.h"

Bishop::Bishop(Color color, const std::string &designation, int row, int column) : Piece(color, designation, row, column)
{}

bool Bishop::isMoveToTheTopRightValid(int nextRow, int nextColumn, GameBoard &board) {
    for (int i = row + 1; i < nextRow; i++) {
        for (int j = column + 1; j < nextColumn; j++) {
            if (board.isTherePiece(i, j)) {
                return false;
            }
        }
    }
    return true;
}

bool Bishop::isMoveToTheTopLeftValid(int nextRow, int nextColumn, GameBoard &board) {
    for (int i = row + 1; i < nextRow; i++) {
        for (int j = column - 1; j < nextColumn; j++) {
            if (board.isTherePiece(i, j)) {
                return false;
            }
        }
    }
    return true;
}

bool Bishop::isMoveToTheButtomRightValid(int nextRow, int nextColumn, GameBoard &board) {
    for (int i = row - 1; i < nextRow; i++) {
        for (int j = column + 1; j < nextColumn; j++) {
            if (board.isTherePiece(i, j)) {
                return false;
            }
        }
    }
    return true;
}

bool Bishop::isMoveToTheButtomLeftValid(int next_row, int next_column, GameBoard board) {
    for (int i = row - 1; i < next_row; i++) {
        for (int j = column - 1; j < next_column; j++) {
            if (board.isTherePiece(i, j)) {
                return false;
            }
        }
    }
    return true;
}

bool Bishop::isPossiblePath(int nextRow, int nextColumn, GameBoard &board, bool isWayClear) {
    return isWayClear && !board.isThereAnAllyPiece(nextRow, nextColumn, color);
}

bool Bishop::isMoveValid(int nextRow, int nextColumn, GameBoard &board) {
    bool isWayClear = false;

    if (row > nextRow && column > nextColumn) {
        isWayClear = isMoveToTheTopRightValid(nextRow, nextColumn, board);
    }
    if (row > nextRow && column < nextColumn) {
        isWayClear = isMoveToTheTopLeftValid(nextRow, nextColumn, board);
    }
    if (row < nextRow && column > nextColumn) {
        isWayClear = isMoveToTheButtomRightValid(nextRow, nextColumn, board);
    }
    if (row < nextRow && column < nextColumn) {
        isWayClear = isMoveToTheButtomLeftValid(nextRow, nextColumn, board);
    }

    if (isPossiblePath(nextRow, nextColumn, board, isWayClear)) {
        return true;
    }
    else {
        return false;
    }
}

bool Bishop::isCheckingKing(GameBoard &board)
{

}
