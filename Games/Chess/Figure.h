#ifndef CHESS_FIGURE_H
#define CHESS_FIGURE_H
#include <utility>
#include <vector>
#include "Board.h"

class Figure
{

public:
    virtual char getFigure() = 0;
    bool getColor();
    void setColor(bool color);
    bool isStepValid(std::pair<int, int>, std::pair<int, int>, Board *board);
    std::pair<bool, std::vector<std::pair<int, int>> isCorrectMove(std::pair<int, int>, std::pair<int, int>);
    bool m_color; // white == true
};

#endif //CHESS_FIGURE_H
