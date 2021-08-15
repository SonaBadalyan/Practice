#include <iostream>

int main()
{
    int array[6] = { 1, 2, 3, 4, 5, 6};

    int* ptrarr;
    ptrarr = array;

    std::cout <<"array : " <<  array << std::endl;
    std::cout <<"&array : " <<  &array << std::endl;
    std::cout <<"ptrarr : " <<  ptrarr << std::endl;
    std::cout <<"++ptrarr : " <<  ++ptrarr << std::endl;
    std::cout <<"&ptrarr : " <<  &ptrarr << std::endl;

    std::cout << "array[2] : " << array[2] << std::endl;
    std::cout << "*(array + 2) : " << *(array + 2) << std::endl;
    std::cout << "*array + 2 : " << *array + 2 << std::endl;
    std::cout << "*(ptrarr + 1) : " << *(ptrarr + 1) << std::endl;

    std::cout << "2[array] : " << 2[array] << std::endl;
    std::cout << "*(2 + array) : " << *(2 + array) << std::endl;
    std::cout << "*(1 + ptrarr) : " << *(1 + ptrarr) << std::endl;
    std::cout << "1[ptrarr] : " << 1[ptrarr] << std::endl;
    std::cout << "ptrarr[1] : " << ptrarr[1] << std::endl;

    std::cout << "*array : " << *array << std::endl;

    std::cout << "array + 1 : " << array + 1 << std::endl;
    std::cout << "&array + 1 : " << &array + 1 << std::endl;
    std::cout << "&array[0] + 1 : " << &array[0] + 1 << std::endl;

    
    for (int* i = array, size = 0; size < sizeof(array)/sizeof(array[0]); ++i, ++size)
    {
        std::cout << *i << "   ";
    }
    std::cout <<std::endl;

    for (int i = 0; i < sizeof(array)/sizeof(array[0]); ++i)
    {
        std::cout << *(array + i) << "   ";
    }
    std::cout <<std::endl;

    return 0;
}