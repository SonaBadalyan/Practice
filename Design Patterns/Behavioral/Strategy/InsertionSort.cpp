#include "InsertionSort.hpp"

void InsertionSort::sort(int arr[], const int SIZE)
{
    for (int i = 1; i < SIZE; ++i) 
        for (int j = i; j != 0; --j)
            if (arr[j - 1] > arr[j])
            {
                arr[j -1] = arr[j -1] ^ arr[j];
                arr[j] = arr[j -1] ^ arr[j];
                arr[j - 1] = arr[j -1] ^ arr[j];
            }
}