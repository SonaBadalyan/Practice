#include "Figure.h"

bool Figure::getColor()
{
    return m_color;
}

void Figure::setColor(bool color)
{
    m_color = color;
}

bool Figure::isStepValid(std::pair<int, int>, std::pair<int, int>, Board *board)
{
    return false;
}

std::pair<bool, std::vector<std::pair<int, int> > Figure::isCorrectMove(std::pair<int, int>, std::pair<int, int>)
{
    std::pair<bool, std::vector<std::pair<int, int> > result;
    return result;
}
