#include "BubbleSort.hpp"

void BubbleSort::sort(int arr[], int SIZE)
{
    for (int i = 0; i < SIZE; ++i)
    {
        for(int j = i; j < SIZE; ++j)
        {
            if (arr[j] < arr [i])
            {
                arr[j] = arr[j] ^ arr [i];
                arr [i] = arr[j] ^ arr [i];
                arr[j] = arr[j] ^ arr [i];
            }
        }
    }
}