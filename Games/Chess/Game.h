#ifndef CHESS_GAME_H
#define CHESS_GAME_H
#include <map>
#include "Board.h"

class Game
{

public:
    Game() : board (new Board()){};
    void draw();
    bool doStep();
    const static std::map<std::string, std::pair<int, int>> position_to_index;

private:
    Board *board;
    static bool whiteTurn;
    std::pair<std::string, std::string> askMovement();
    static std::string getPosition();
    std::string inputValidation(std::string position);
    bool isValidFigure(std::pair<int, int> index);

};

#endif //CHESS_GAME_H
