#include <iostream>

class A{};

int main()
{
    std::cout << "\t\t Size of primitive built-in types for x86_64 (this) architecture." << std::endl;
    std::cout << std::endl;

    std::cout << "\t Primitive built-in types are divided into two categories: arithmetic types and void type." << std::endl;
    std::cout << "\t Arithmetic types are divided into two categories: integral types and floating-point types." << std::endl;
    std::cout << "\t Integral category is contain boolean, character and integer types." << std::endl;
    std::cout << std::endl;

    std::cout << "Size of boolean type is " << sizeof(bool) << " byte." << std::endl; // 1 byte
    std::cout << std::endl;

    std::cout << "\t Charachter types are divided into two categories: one category is guaranteed to be big enough to hold numeric values corresponding to the characters in the machine’s basic character set (char). " << std::endl;
    std::cout << "\t Remaining character types are used for extended character sets (wchar_t and Uncode charachters(char16_t, char32_t))." << std::endl;
    std::cout << std::endl;

    std::cout << "\t Plain char can be either signed or unsigned, depending on architecture." << std::endl;
    std::cout << std::endl;

    std::cout << "\t Size of charachter types." << std::endl;
    std::cout << std::endl;

    std::cout << "Size of charachter type is " << sizeof(char) << " byte." << std::endl; // 1 byte
    std::cout << std::endl;

    std::cout << "Size of wide charachter type is " << sizeof(wchar_t) << " byte." << std::endl; // 4 byte
    std::cout << std::endl;

    std::cout << "size of unicode charachter 16 type is " << sizeof(char16_t) << " byte." << std::endl; // 2 byte
    std::cout << "size of unicode charachter 32 type is " << sizeof(char32_t) << " byte." << std::endl; // 4 byte
    std::cout << std::endl;

    std::cout << "\t Size of integer types." << std::endl;
    std::cout << std::endl;

    std::cout << "Size of short integer type is " << sizeof(short) << " byte." << std::endl; // 2 byte
    std::cout << "Size of integer type is " << sizeof(int) << " byte." << std::endl; // 4 byte
    std::cout << "Size of long integer type is " << sizeof(long) << " byte." << std::endl; // 8 byte
    std::cout << "size of long long integer type is " << sizeof(long long) << " byte." << std::endl; // 8 byte
    std::cout << std::endl;

    std::cout << "\t The standard specifies that short <= int <= long <= long long. " << sizeof(short) << " <= " << sizeof(int) << " <= " << sizeof(long) << " <= " << sizeof(long long) << std::endl;
    std::cout << std::endl;

    std::cout << "\t Floating-point category is contain single, double and extanded precision types." << std::endl;
    std::cout << "\t The standard specifies a minimum number of significant digits: float - 6 digits, double - 10 digits, long double - 10 digits." << std::endl;
    std::cout << std::endl;

    std::cout << "Size of single-precision floating point type is " << sizeof(float) << " byte." << std::endl; // 4 byte
    std::cout << "Size of double-precision floating point type is " << sizeof(double) << " byte." << std::endl; // 8 byte
    std::cout << "Size of extended-precision floating point type is " << sizeof(long double) << " byte." << std::endl; // 16 byte
    std::cout << std::endl;

    std::cout << "\t Void is the incomplete type and it is can not have size by standard, however, gcc set size for void equal to the size of character, for supporting pointer arithmetic." << std::endl;
    std::cout << std::endl;

    std::cout << "Size of void type is " << sizeof(void) << " byte." << std::endl; // 1 byte
    std::cout << std::endl;

    std::cout << "\t And for completeness let's check the size of the pointer." << std::endl;
    std::cout << std::endl;

    std::cout << "Size of void* type is " << sizeof(void*) << " byte." << std::endl; // 8 byte
    std::cout << std::endl;

    std::cout << "\t Size of empty class is " << sizeof(A) << " byte. It is done for addressing the object of an empty class. " << std::endl; // 1 byte
    std::cout << std::endl;

    return 0;
}