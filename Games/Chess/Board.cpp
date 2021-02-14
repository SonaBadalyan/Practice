#include <iostream>
#include "Game.h"
#include "Board.h"
#include "EmptyCell.h"

Board::Board() :
                m_whitePlayer(new Player(board, true)),
                m_blackPlayer(new Player(board, false))
{
    for (int i = 2; i != 6; ++i)
        for (int j = 0; j != 8; ++j)
            board[i][j] = new EmptyCell();
}

void Board::draw()
{
    std::cout << "\t";
    for (char ch = 65; ch != 73; ++ch)
        std::cout << std::string(3, ' ') << ch << std::string(3, ' ');
    std::cout << std::endl;

    for (int i = 1; i != 9; ++i) {
        std::cout << "\t";
        std::cout << std::string(56, '-');
        std::cout << std::endl;
        std::cout << i;
        std::cout << "\t";
        for (int j = 1; j != 9; ++j) {
            std::cout << "|" << std::string(3, ' ');
            std::cout << board[i - 1][j - 1]->getFigure();
            std::cout << std::string(2, ' ');
        }
        std::cout << "|\t";
        std::cout << i;
        std::cout << std::endl;
    }

    std::cout << "\t";
    std::cout << std::string(56, '-');
    std::cout << std::endl;

    std::cout << "\t";
    for (char ch = 65; ch != 73; ++ch)
        std::cout << std::string(3, ' ') << ch << std::string(3, ' ');
    std::cout << std::endl;
}

bool Board::doStep(const std::pair<std::string, std::string> &from_to, bool& stepValidity)
{
    auto index_from = Game::position_to_index.at(from_to.first);
    auto index_to = Game::position_to_index.at(from_to.second);

    stepValidity = board[index_from.first][index_from.second].isStepValid(index_from, index_to, this);
    if (!stepValidity)
        return false;

    delete board[index_to.first][index_to.second];
    board[index_to.first][index_to.second] = board[index_from.first][index_from.second];
    board[index_from.first][index_from.second] = new EmptyCell();

    return true;
}
