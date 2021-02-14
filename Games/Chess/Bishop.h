#ifndef CHESS_BISHOP_H
#define CHESS_BISHOP_H
#include "Figure.h"

class Bishop : public Figure
{
public:
    Bishop(bool color)
    {
        m_color = color;
    }
    char getFigure() override;
};

#endif //CHESS_BISHOP_H
