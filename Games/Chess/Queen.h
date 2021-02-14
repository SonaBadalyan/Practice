#ifndef CHESS_QUEEN_H
#define CHESS_QUEEN_H
#include "Figure.h"

class Queen : public Figure
{
public:
    Queen(bool color)
    {
        m_color = color;
    }
    char getFigure() override;
};
#endif //CHESS_QUEEN_H
