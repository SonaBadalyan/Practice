#ifndef CHESS_PAWN_H
#define CHESS_PAWN_H
#include "Figure.h"

class Pawn : public Figure
{
public:
    Pawn(bool color)
    {
        m_color = color;
    }
    char getFigure() override;

};
#endif //CHESS_PAWN_H
