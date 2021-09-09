/*
** Worst-case performance	О(n2) comparisons, О(n2) swaps
** Best-case performance	О(n) comparisons,  O(1)  swaps
** Average performance	    О(n2) comparisons, О(n2) swaps
** Worst-case space complexity	O(1) total, O(1) auxiliary
*/

#include <iostream>

void swap(int &value1, int &value2)
{
    value1 = value1 ^ value2;
    value2 = value1 ^ value2;
    value1 = value1 ^ value2;
    
}

void bubble_sort(int arr[], int SIZE)
{
    for (size_t i = 0; i < SIZE; ++i)
    {
        for(size_t j = i; j < SIZE; ++j)
        {
            if (arr[j] < arr [i])
                swap(arr[i], arr[j]);
        }
    }
}

int main ()
{
    const int SIZE = 10;
    int *arr = new int [SIZE];

    srand(time(0));
    for(size_t i = 0; i < SIZE; ++i)
        arr[i] = rand() % 100;

    std::cout << "\nBefore sorting." << std::endl;
    for(size_t i = 0; i < SIZE; ++i)
        std::cout << arr[i] << " ";

    bubble_sort(arr, SIZE);

    std::cout << "\nAfter sorting." << std::endl;
    for(size_t i = 0; i < SIZE; ++i)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    delete[] arr;
    
    return 0;
}