#include "SelectionSort.hpp"

void SelectionSort::sort(int arr[], const int SIZE)
{
    for (int i = 0; i < SIZE; ++i)
    {
        int min = i;

        for (int j = i + 1; j < SIZE; ++j)
        {
            if (arr[j] < arr[min])
                min = j;

        }

        if (min != i)
        {
            arr[i] = arr[i] ^ arr[min];
            arr[min] = arr[i] ^ arr[min];
            arr[i] = arr[i] ^ arr[min];
        }
    } 
}
