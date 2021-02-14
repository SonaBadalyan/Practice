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
    std::cout << "\t Trying to cover all possible conversion cases in C ++.\n" << std::endl;

    std::cout << "Implicit (automatic) conversions done by the compiler on its own automatically, when we use an object of one type where an object of another type is expected.\n " << std::endl;

    std::cout << "Let's try conversions using void type. Because void itself is an incomplete type, we can try conversions to void pointer.\n" << std::endl;

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
    //delete vp; // deleting ‘void*’ is undefined [-Wdelete-incomplete]

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

    b = ch;
    b = i;
    b = d;
    b = f;
    b = vp;
    b = &udt;
    b = 'A';
    b = -1;
    b = 0.2;
    b = "String";
    b = 1 + 1.0;
    //b = nullptr; // error :  a value of type "std::nullptr_t" cannot be assigned to an entity of type "bool", converting to ‘bool’ from ‘std::nullptr_t’ requires direct-initialization [-fpermissive]

    std::cout << "Let's try conversions using char type." << std::endl;

    ch = b;
    ch = i;
    ch = d;
    ch = f;
    //ch = &udt; // error: a value of type "UDT *" cannot be assigned to an entity of type "char"
    //ch = vp; // error: a value of type "void *" cannot be assigned to an entity of type "char"
    ch = 10;
    ch = 10 + 'a';
    ch = 2.34;
    ch = -2;
    //ch = "String"; // error: a value of type "const char *" cannot be assigned to an entity of type "char"

    std::cout << "Let's try conversions using integer type." << std::endl;

    i = b;
    i = ch;
    i = d;
    i = f;
    //i = vp; // error: a value of type "void *" cannot be assigned to an entity of type "int"
    i = -10 - 20.90;
    //i = "A"; // error: a value of type "const char *" cannot be assigned to an entity of type "int"
    i = 'A';

    std::cout << "Let's try conversions using floating point type." << std::endl;

    return 0;
}