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

    // Vector<int> v1(std::move(v));
    // Vector<int> v2;
    // v2 = v1;
    // Vector<int> v3;
    // v3 = std::move(v2);
 
    std::cout << "Vector size : " << v.size() << std::endl;
    std::cout << "Vector capacity : " << v.get_capacity() <<  std::endl;
 
    std::cout << "Vector elements : ";
    v.print();
 
    v.insert(60, 3);

    std::cout << "\nAfter updating 4th index" <<  std::endl;
    v.print();

    v.pop();
    std::cout << "\nAfter pop " <<  std::endl;
    v.print();
 
    std::cout << "Vector size of type int: " << v.size() <<  std::endl;
    std::cout << "Vector capacity of type int : " << v.get_capacity() <<  std::endl;

    // std::cout << "Element at 1st index of type int: " << v3.at(3) <<  std::endl;

    std::cout << "Vector elements of type int: ";
    v.print();
    std::cout << "v.size(): " << v.size() << std::endl;
    v.pop();
    std::cout << "v.size(): " << v.size() << std::endl;
    std::cout << "v.at(2): " << v.at(2) << std::endl;
    std::cout << "v[2]: " << v[2] << std::endl;
    std::cout << "v.empty() " << v.empty() << std::endl;
    std::cout << "v.front(): " << v.front() << std::endl;
    std::cout << "v.back(): " << v.back() << std::endl;


    return 0;
}