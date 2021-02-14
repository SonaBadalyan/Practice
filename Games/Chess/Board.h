#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H
#include "Figure.h"
#include "Player.h"

class Board
{

public:
    Board();
    void draw();
    bool doStep(std::pair<std::string, std::string> const& from_to, bool& stepValidity);

public:
    Figure* board[8][8];
    Player *m_whitePlayer;
    Player *m_blackPlayer;

};

#endif //CHESS_BOARD_H
