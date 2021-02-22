#include "ForwardList.hpp"

int main()
{
    ForwardList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);
    list.print();

    std::cout << list.front();

    
    // ForwardList<int> list1(std::move(list));
    // ForwardList<int> list3;

    // list3 = std::move(list1);
    // list3.print();
    // list3.clear();
    // list3.print();

    // list.print();


    return 0;
}