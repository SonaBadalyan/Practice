#include <iostream>
#include "Vector.cpp"

int main()
{
    Vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
 
    std::cout << "Vector size : " << v.size() << std::endl;
    std::cout << "Vector capacity : " << v.get_capacity() <<  std::endl;
 
    std::cout << "Vector elements : ";
    v.print();
 
    v.insert(60, 3);

    std::cout << "\nAfter updating 1st index" <<  std::endl;
    v.print();

    v.pop();
    std::cout << "\nAfter pop " <<  std::endl;
    v.print();
 
    std::cout << "Vector size of type int: " << v.size() <<  std::endl;
    std::cout << "Vector capacity of type int : " << v.get_capacity() <<  std::endl;

    std::cout << "Element at 1st index of type int: " << v.get(0) <<  std::endl;

    std::cout << "Vector elements of type int: ";
    v.print();

    return 0;
}