#ifndef CHESS_EMPTYCELL_H
#define CHESS_EMPTYCELL_H
#include "Figure.h"

class EmptyCell : public Figure
{
public:
    char getFigure() override;
};

#endif //CHESS_EMPTYCELL_H
