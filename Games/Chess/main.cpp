#include <iostream>
#include "Game.h"

int main()
{
    std::cout << "Type command: (N)ew game, (E)xit: ";
    char command;
    std::cin >> command;

    switch (command)
    {
        case 'N':
        {
            Game *chess = new Game();
            do
                chess->draw();
            while (chess->doStep());

            delete chess;
            
            break;
        }
        case 'E':
        {
            exit(EXIT_SUCCESS);
        }
    }

    return 0;
}
