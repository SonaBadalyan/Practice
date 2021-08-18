#include<iostream>

int main()
{
    int array[2][3];

    // Row major implementation 
    // Random access is possible by using this formula` Array base address (array name) + ((i * n ) + j) * sizeof(element) // a[i][j] access, n is number of columns
    // Address of a[i][j] = Base address + ((i * n) + j) * sizeof(a[i][j])

    // Column major implementation 
    // Address of a[i][j] = Base address + ((j * m) + i) * sizeof(a[i][j])

    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j <3; ++ j)
        {
            std::cout << "Enter element: ";
            std::cin >> array[i][j];

            std::cout << std::endl;
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

    return 0;
}