#ifndef CHESS_PLAYER_H
#define CHESS_PLAYER_H
#include <string>
#include "Figure.h"

class Player
{

public:
    Player(Figure* board[8][8], bool color);
};

#endif //CHESS_PLAYER_H
