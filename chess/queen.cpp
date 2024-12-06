#include "queen.h"
#include "gameboard.h"
Queen::Queen(Color color, const std::string &designation, int row, int column) : Piece(color, designation, row, column)
{}

bool Queen::isColumnMoveValid(int nextColumn, GameBoard &board, bool &value) {
    for (int i = column + 1; i < nextColumn; i++) {
        if (board.isTherePiece(row, i)) {
            value = false;
            return true;
        }
    }
    return false;
}

bool Queen::isRowMoveValid(int nextRow, GameBoard &board) {
    for (int i = row + 1; i < nextRow; i++) {
        if (board.isTherePiece(i, column)) {
            return false;
        }
    }
}

bool Queen::isPossiblePath(int nextRow, int nextColumn, GameBoard &board, bool isWayClear) {
    return isWayClear && !board.isThereAnAllyPiece(nextRow, nextColumn, color);
}

bool Queen::isMoveToTheTopRightValid(int next_row, int next_column, GameBoard board) {
    for (int i = row + 1; i < next_row; i++) {
        for (int j = column + 1; j < next_column; j++) {
            if (board.isTherePiece(i, j)) {
                return false;
            }
        }
    }
    return true;
}

bool Queen::isMoveToTheTopLeftValid(int next_row, int next_column, GameBoard board) {
    for (int i = row + 1; i < next_row; i++) {
        for (int j = column - 1; j < next_column; j++) {
            if (board.isTherePiece(i, j)) {
                return false;
            }
        }
    }
    return true;
}

bool Queen::isMoveToTheButtomRightValid(int next_row, int next_column, GameBoard board) {
    for (int i = row - 1; i < next_row; i++) {
        for (int j = column + 1; j < next_column; j++) {
            if (board.isTherePiece(i, j)) {
                return false;
            }
        }
    }
    return true;
}

bool Queen::isMoveToTheButtomLeftValid(int next_row, int next_column, GameBoard board) {
    for (int i = row - 1; i < next_row; i++) {
        for (int j = column - 1; j < next_column; j++) {
            if (board.isTherePiece(i, j)) {
                return false;
            }
        }
    }
    return true;
}

bool Queen::isMoveValid(int nextRow, int nextColumn, GameBoard &board) {
    bool isWayClear{};

    if (row == nextRow) {
        bool value;
        isWayClear = isColumnMoveValid(nextColumn, board, value);
    }
    if (column == nextColumn) {
        isWayClear = isRowMoveValid(nextRow, board);
    }
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

bool Queen::isCheckingKing(GameBoard &board)
{

}
