#include <iostream>

class Test
{
    int& i;
    int& j;
    int& k;
};

int main()
{
    int i = 10;
    int *pi = &i;
    int &ri = i; 

    ++i;
    std::cout << i << " " << ri << " " << *pi << std::endl; // 11 11 11
    std::cout << &i << " " << &ri << " " << pi <<  std::endl; // 0x7ffe65daf1a4 0x7ffe65daf1a4 0x7ffe65daf1a4

    ++ri;
    std::cout << i << " " << ri << " " << *pi << std::endl; // 12 12 12
    std::cout << &i << " " << &ri << " " << pi <<  std::endl; // 0x7ffe65daf1a4 0x7ffe65daf1a4 0x7ffe65daf1a4

    ++(*pi);
    std::cout << i << " " << ri << " " << *pi << std::endl; // 13 13 13
    std::cout << &i << " " << &ri << " " << pi <<  std::endl; // 0x7ffe65daf1a4 0x7ffe65daf1a4 0x7ffe65daf1a4

    ri = 20;
    std::cout << i << " " << ri << " " << *pi << std::endl; // 20 20 20 
    std::cout << &i << " " << &ri << " " << pi <<  std::endl; // 0x7ffe65daf1a4 0x7ffe65daf1a4 0x7ffe65daf1a4

    ri = ++(*pi);
    std::cout << i << " " << ri << " " << *pi << std::endl; // 21 21 21
    std::cout << &i << " " << &ri << " " << pi <<  std::endl; // 0x7ffe65daf1a4 0x7ffe65daf1a4 0x7ffe65daf1a4

    *pi = 22;
    std::cout << i << " " << ri << " " << *pi << std::endl; // 22 22 22
    std::cout << &i << " " << &ri << " " << pi <<  std::endl; // 0x7ffe65daf1a4 0x7ffe65daf1a4 0x7ffe65daf1a4
    
    std::cout << sizeof(class Test) << std::endl; // 24 byte ( 8 + 8 + 8 )

    std::cout << sizeof(pi) << "  " << sizeof(&ri) << std::endl; // 8  8

    return 0;
}