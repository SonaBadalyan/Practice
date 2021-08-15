#include <iostream>
#include "List.hpp"

int main()
{
    List list;
    list.insert(10, 0);
    list.insert(20, 1);
    list.insert(30, 2);
    list.insert(40, 3);

    operator<<(std::cout, list);

    list.remove(2);

    operator<<(std::cout, list);

    std::cout << list.get(0) << std::endl;
    std::cout << list.find(20) << std::endl;
    std::cout << list.hasLoop() << std::endl;

    return 0;
}