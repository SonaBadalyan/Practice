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
    std::cout << i << " " << ri << " " << *pi << std::endl;
    std::cout << &i << " " << &ri << " " << pi <<  std::endl;

    ++ri;
    std::cout << i << " " << ri << " " << *pi << std::endl;
    std::cout << &i << " " << &ri << " " << pi <<  std::endl;

    ++(*pi);
    std::cout << i << " " << ri << " " << *pi << std::endl;
    std::cout << &i << " " << &ri << " " << pi <<  std::endl;

    ri = 20;
    std::cout << i << " " << ri << " " << *pi << std::endl;
    std::cout << &i << " " << &ri << " " << pi <<  std::endl;

    ri = ++(*pi);
    std::cout << i << " " << ri << " " << *pi << std::endl;
    std::cout << &i << " " << &ri << " " << pi <<  std::endl;

    *pi = 22;
    std::cout << i << " " << ri << " " << *pi << std::endl;
    std::cout << &i << " " << &ri << " " << pi <<  std::endl;
    
    std::cout << sizeof(class Test) << std::endl;

    std::cout << sizeof(pi) << "  " << sizeof(&ri) << std::endl;


    return 0;
}