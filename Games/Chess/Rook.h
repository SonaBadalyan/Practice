#ifndef CHESS_ROOK_H
#define CHESS_ROOK_H
#include "Figure.h"

class Rook : public Figure
{
public:
    Rook(bool color)
    {
        m_color = color;
    }
    char getFigure() override;

};
#endif //CHESS_ROOK_H
