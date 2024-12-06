#include "king.h"
#include "gameboard.h"

King::King(Color color, const std::string &designation, int row, int column) : Piece(color, designation, row, column)
{
    isCheck = false;
}

bool King::isPossibleToMove(int nextRow, int nextColumn, bool isTherePiece, int i, int j) {
    return nextRow == row + i && nextColumn == column + j && !isTherePiece;
}

bool King::isMoveValid(int nextRow, int nextColumn, GameBoard &board) {
    bool isThereAnAllyPiece = board.isThereAnAllyPiece(nextRow, nextColumn, color);

    for(int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++) {
            if (isPossibleToMove(nextRow, nextColumn, isThereAnAllyPiece, i, j)) {
                return true;
            }
        }
    }
    return false;
}

bool King::isCheckingKing(GameBoard &board)
{

}

