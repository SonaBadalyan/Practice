#include <iostream>
class UDT // user defined type
{
    public:
    void UDT_foo(int i)
    {
        std::cout << i << std::endl;
    }
    int i;

};

static void foo(int i)
{
    std::cout << i << std::endl;
}

int main()
{
    std::cout << "Trying to cover all possible conversion cases in C ++." << std::endl;

    std::cout << "Implicit (automatic) conversions done by the compiler on its own automatically, when we use an object of one type where an object of another type is expected. " << std::endl;

    std::cout << "Let's try conversions using void type. Because void itself is an incomplete type, we can try conversions to void pointer." << std::endl;

    void* vp;

    bool b = true;
    vp = &b;

    char ch = 'A';
    vp = &ch;

    int i = 7;
    vp = &i;

    double d = 2.4;
    vp = &d;

    float f = -2.5;
    vp = &f;

    vp = new int[10];
    delete vp; // deleting ‘void*’ is undefined [-Wdelete-incomplete]

    vp = nullptr;

    // void (*vp)(int);
    // vp = &foo;
    // (*vp)(2); // error: void *vp, expression must be a pointer to a complete object type


    UDT udt;
    vp = &udt;

    UDT &ref_udt = udt;
    vp = &ref_udt;

    // vp = 1; // error. rvalue reference, a value of type "int" cannot be assigned to an entity of type "void *"
    // vp = ref_udt; // error no suitable conversion function from "UDT" to "void *" exists

    int UDT::*pv = &UDT::i; // declare pointer to data member
    udt.i = 1;
    udt.*pv = 2;
    std::cout << udt.*pv << " " << udt.i << std::endl; // 2 2

    // void (UTD::* pv)(int) = &UTD::UDT_foo; // declare a pointer to member function
    // (udt.*pv)(2); // WTF my compiler doesn't create a function pointer to a member function

    std::cout << "Let's try conversions using bool type." << std::endl;

    return 0;
}