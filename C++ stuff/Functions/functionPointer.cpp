#include <iostream>

void foo()
{
    std::cout << "Inside foo" << std::endl;

}

void foo1()
{
    std::cout << "Inside foo1" << std::endl;
}

int bar (int arg)
{
    std::cout << "Inside bar" << std::endl;
}

double dbar(double arg)
{
    std::cout << "Inside dbar" << std::endl;
}

void callBack( void (*pFoo)())
{
    pFoo();
}

int main()
{
    void (*pFoo)() = foo;
    pFoo(); // call function via it`s pointer

    auto pFoo1 = foo1;
    
    callBack(pFoo);
    callBack(pFoo1);

    double (*pDbar)(double);
    pDbar = dbar;
    (*pDbar)(3.14);

    auto pBar = bar;
    pBar(34);

    void (*fpArray[2])() = {foo, foo1}; // function pointer`s array
    fpArray[0]();
    fpArray[1]();

    for (int i = 0; i < sizeof(fpArray)/ sizeof(fpArray[0]); ++i)
    {
        fpArray[i]();
    }

    auto fparray1 = &fpArray; // poiter to function pointer array 
    (*(*fpArray[0]))();
    
    typedef void (*fparray2)();

    fparray2 fooTypedef = foo;
    fparray2 foo1Typedef = foo1;

    fparray2 parr[2];
    parr[0] = fooTypedef;
    parr[1] = foo1Typedef;
    
    parr[0]();
    parr[1]();

    return 0;
}