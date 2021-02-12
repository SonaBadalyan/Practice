#include <iostream>
#include "Wrapper.hpp"

// void foo(Integer i)
// {
//     std::cout << i.get_value() << std::endl;  
// }

// void foo(Integer &i)
// {
//     std::cout << i.get_value() << std::endl;  
// }

void foo(const Integer &i)
{
    std::cout << i.get_value() << std::endl;  
}

int main()
{
    Integer integer(0);
    foo(++integer);
    foo(integer++); //error: initial value of reference to non-const must be an lvalue, cannot bind non-const lvalue reference of type ‘Integer&’ to an rvalue of type ‘Integer’, when void foo(Integer &i)
    foo(--integer);
    foo(integer--); //error: initial value of reference to non-const must be an lvalue, cannot bind non-const lvalue reference of type ‘Integer&’ to an rvalue of type ‘Integer’, when void foo(Integer &i)
    return 0;
}