#ifndef PIECE_H
#define PIECE_H


#include <string>

enum Color{
    BLACK, WHITE
};

class GameBoard;

class Piece
{
public:

    Piece(Color color, const std::string &designation, int row, int column);
    std::string getDesignation() const;

    virtual bool isMoveValid(int nextRow, int nextColumn, GameBoard &board) = 0;
    virtual bool isCheckingKing(GameBoard &board) = 0;
    Color getColor() const;
    void setRow(int newRow);
    void setColumn(int newColumn);
protected:
    Color color;
    const std::string designation;
    int row;
    int column;
};

#endif // PIECE_H
