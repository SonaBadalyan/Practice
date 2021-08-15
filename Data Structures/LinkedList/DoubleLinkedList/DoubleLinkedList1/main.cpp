#include "DoubleLinkedList.hpp"
#include  <string>
 #include <list>

int main()
{
    std::list<int> l(10, 4);
    std::list<int> l1(10, 3);
    l.swap(l1);

    DoubleLinkedList<int> list;
    DoubleLinkedList<int> list1(10, 3);
    DoubleLinkedList<int> list2(list1);
    DoubleLinkedList<int> list3(std::move(list2));
    list = list1;
    list2 = std::move(list);


    list1.print();

    std::string result;
    if (list1.empty())
        result = "empty";
    else
        result = "non empty";

    std::cout << result <<  std::endl;

    list1.push_front(9);
    list1.push_back(10);
    list1.print();
    list1.pop_front();
    list1.print();
    list1.pop_back();
    list1.print();

    list1.clear();

    std::cout << list1.size() << std::endl;
    list.resize(10, 2);
    list.print();

    DoubleLinkedList<int> list4;
    list4.swap(list);
    list.print();
    list4.print();

    list4.insert(1, 10);
    list4.print();

    DoubleLinkedList<int> list5;
    list5.push_back(1);
    list5.push_back(2);
    list5.push_back(3);
    list5.push_back(4);
    list5.push_back(5);
    list5.print();
    
    list5.erase(3);
    list5.print();


    return 0;
}