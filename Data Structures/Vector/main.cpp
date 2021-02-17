#include <iostream>
#include "Vector.hpp"

int main()
{
    Vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);

    Vector<int> v2(v1);

    std::cout << "v1 vector elements : ";
    v1.print();
 
    std::cout << "v2 vector elements : ";
    v2.print();
 
    Vector<int> v3(std::move(v1));

    std::cout << "v1 vector elements : ";
    v1.print();
 
    std::cout << "v3 vector elements : ";
    v3.print();

    Vector<int> v4(2);
    Vector<int> v5(5, 10);
    
    std::cout << "v5 vector elements : ";
    v5.print();
 
    std::cout << "v4 vector elements : ";
    v4.print();

    v4 = v5;

    std::cout << "v4 vector elements : ";
    v4.print();

    v4 = std::move(v5);

    std::cout << "v5 vector elements : ";
    v5.print();
 
    std::cout << "v4 vector elements : ";
    v4.print();

    Vector<int> v(v2.size());
    v = std::move(v2);
 
    std::cout << "v vector" << std::endl;
    std::cout << "Vector size : " << v.size() << std::endl;
    std::cout << "Vector capacity : " << v.get_capacity() <<  std::endl;
 
    std::cout << "Vector elements : ";
    v.print();
 
    v.insert(60, 3);

    std::cout << "\nAfter updating 4th index" <<  std::endl;
    v.print();
 
    std::cout << "Vector size of type int: " << v.size() <<  std::endl;
    std::cout << "Vector capacity of type int : " << v.get_capacity() <<  std::endl;

    std::cout << "Vector elements of type int: ";
    v.print();
    std::cout << "v.size(): " << v.size() << std::endl;
    v.pop();
    std::cout << "\nAfter pop " <<  std::endl;
    v.print();
    std::cout << "v.size(): " << v.size() << std::endl;
    std::cout << "v.at(2): " << v.at(2) << std::endl;
    std::cout << "v[2]: " << v[2] << std::endl;
    std::cout << "v.empty() " << v.empty() << std::endl;
    std::cout << "v.front(): " << v.front() << std::endl;
    std::cout << "v.back(): " << v.back() << std::endl;

    auto begin = v.begin();
    auto end = v.end();

    for (auto const& elem : v)
        std::cout << elem << " ";
    std::cout << std::endl;

    for (auto iter = v.begin(); iter != v.end(); iter++)
            std::cout << *iter << " ";
    std::cout << std::endl;

    return 0;
}