#ifndef CHESS_KING_H
#define CHESS_KING_H
#include "Figure.h"

class King : public Figure
{
public:
    King(bool color)
    {
        m_color = color;
    }
    char getFigure() override;

};
#endif //CHESS_KING_H
