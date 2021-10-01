#include <iostream>
#include <string>

// The same name may be applied for function, 
//                                  template function, 
//                                  template, oridinary and template specialization functions overloaded versions,
//                                  and template function specialization.

void swap(int, int); // ordinary function

template <typename AnyType> // template function
void swap(AnyType&, AnyType&);

template <typename AnyType>
void swap(AnyType*, AnyType*, int); // template function overloaded version

struct job
{
    std::string name;
    double salary;
    int floor;
};

template<>
void swap(job&, job&); // template function specialization

template void swap<char>(char&, char&); // This line force the compiler explicitly generate code for the char version, if we don`t write this it will be generated only when we call the char version in the main.
// If we specify the swap function for the char version and have this line, it will be a compile error.

template<typename T>
T max(T a, T b)
{
    return a > b ? a : b;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

template<class T1, class T2>
void add(T1 x, T2 y)
{
    // We don't know the type of c, without decltype we can not write code like this;
    // decltype deduce type as specified as mentioned in the argument, if there is const, & or * ther become part of type.
    // We can write the function as an argument to decltype, and deduced type will be function return type, the function will not call.
    // If we apply parentheses to the lvalue type, the resulting type will have a reference type.
    typedaef decltype(x + y) c;
    c result  = x + y;
}

template<typename T1, typename T2>
auto add(T1 x, T2 y) -> decltype(x + y) // trailing return type
{
    // We can't do this without trailing return type, because we don't have x and y at the beginning of the function.
    return x + y;
}

int main()
{
    int a = 4;
    int b = 5;

    swap(a, b); // compiler call oridinary function

    std::cout << a << " : " << b << std::endl;

    double c = 3;
    double d = 5.7;

    swap(c, d); // comiler generate template double version and call it 

    std::cout << c << " : " << d << std::endl;

    const int SIZE = 6;

    int arr1[SIZE] = {0};
    int arr2[SIZE] = {1};

    swap(arr1, arr2, SIZE); // call template overloaded verson

    job j1;
    j1.name = "Programmer";
    j1.salary = 250000.90;
    j1.floor = 10;

    job j2;
    j2.name = "Singer";
    j2.salary = 4000.80;
    j2.floor = 14;

    swap(j1, j2); // call template specialization

    swap('a', 'b'); // call alredy ganarated char version

    std::cout << max<double>(2, 4.7) << std::endl; // we force the compiler ganarate double version
    max(4, 5); // call non-tamplate version
    max<>(3, 5); // we force the compiler to generate argument deduced type template function
    max<int>(20.4, 34); /// we explicitly say compiler call template int version

    // If we have a non-template function, the compiler will call that.
    // If we have template specialization, the compiler will call that.
    // If non of the above mentioned exist, and we have a template function, the compiler will generate the corresponding function.
    // We can change this passing to function type arguments like max function.

    return 0;
}

void swap(int a, int b)
{
    std::cout << "ordinary function" << std::endl;

    int c = a;
    a = b;
    b = c;
}

template <typename AnyType>
void swap(AnyType& a, AnyType& b)
{
    std::cout << "template function overloaded version" << std::endl;

    AnyType temp = a;
    a = b;
    b = temp;
}

template <typename AnyType>
void swap(AnyType* arr1, AnyType* arr2, int size) 
{
    std::cout << "template function" << std::endl;

    AnyType temp;

    for (int i = 0; i < size; ++i)
    {
        temp = arr1[i];
        arr1[i] = arr2[i];
        arr2[i] = temp;
    }
}

template<>
void swap(job& a, job& b)
{
    std::cout << "template function specialization" << std::endl;

    double salary = a.salary;
    a.salary = b.salary;
    b.salary = salary;

    int floor = a.floor;
    a.floor = b.floor;
    b.floor = floor;
}