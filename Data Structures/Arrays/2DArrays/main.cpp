#include<iostream>

int main()
{
    int array[2][3];

    // Row major implementation 
    // Random access is possible by using this formula` Array base address (array name) + ((i * n ) + j) * sizeof(element) // a[i][j] access, n is number of columns
    // Address of a[i][j] = Base address + ((i * n) + j) * sizeof(a[i][j])

    // Column major implementation 
    // Address of a[i][j] = Base address + ((j * m) + i) * sizeof(a[i][j]),  m is a number of rows

    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            // std::cout << "Enter element: ";
            // std::cin >> array[i][j];

            // std::cout << std::endl;

            array[i][j] = ((i + 1) + (j + 1)) * 10;
        }
    }

    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 3; ++ j)
        {
            std::cout << array[i][j] << "  ";
        }
    }

    std::cout << std::endl;
    std::cout << "sizeof(array[0][0]) : " << sizeof(array[0][0]) << std::endl;

    int* parr = &array[0][0];

    std::cout << "array : " << array << std::endl;
    std::cout << "parr : " << parr << std::endl;

    parr = array[0];

    std::cout << "parr : " << parr << std::endl;

    std::cout << "&array[0] : " << &array[0] << std::endl;
    std::cout << "&array[0][0] : " << &array[0][0] << std::endl;
    std::cout << "&array : " << &array << std::endl;
    std::cout << "*array : " << *array << std::endl;
    std::cout << "array[0] : " << array[0] << std::endl;

    std::cout << " array + 1 : " << (array + 1) << std::endl;
    std::cout << " *(array + 1) : " << *(array + 1 ) << std::endl;
    std::cout << "&array[1] : " << &array[1] << std::endl;
    std::cout << "array[1] : " << array[1] << std::endl;
    std::cout << "&array[1][0] : " << &array[1][0] << std::endl;
    
    std::cout << "*(array + 1) + 2 : " << *(array + 1) + 2 << std::endl;
    std::cout << "*(*(array + 1) + 2) : " << *(*(array + 1) + 2) << std::endl;
    std::cout << "array[1][2] : " << array[1][2] << std::endl;
    std::cout << "*(array[1] + 2) : " << *(array[1] + 2) << std::endl;
    // array[i][j] = *(*(array + i) + j) = * (array[i] + j) = parr[i][j] = *(*(parr + i) + j) = * (parr[i] + j)
    std::cout << "*(*array + 1) : " << *(*array + 1)  << std::endl;
    std::cout << "**array : "  << **array << std::endl;
    //std::cout << "**parr : "  << **parr << std::endl;
    std::cout << "array[1] + 1: " << array[1] + 1 << std::endl;
    std::cout << "&array[1] + 1: " << &array[1] + 1 << std::endl;
    std::cout << std::endl;

    return 0;
}