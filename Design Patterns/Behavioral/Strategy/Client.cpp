#include <iostream>
#include "SortingContext.hpp"

int main()
{
    SortingContext sorting;

    int type;
    std::cout << "Please select sorting type: Bubble(1), Insertion(2), Selection(3)." << std::endl;
    std::cin >> type;

    sorting.setSorting(type);
    sorting.doSort();

    return 0;
}