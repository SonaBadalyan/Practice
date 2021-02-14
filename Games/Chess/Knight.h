#ifndef CHESS_KNIGHT_H
#define CHESS_KNIGHT_H
#include "Figure.h"

class Knight : public Figure
{
public:
    Knight(bool color)
    {
        m_color = color;
    }
    char getFigure() override;

};
#endif //CHESS_KNIGHT_H
