/*
**    Worst-case performance	    О(n2) comparisons, О(n) swaps
**    Best-case performance	        О(n2) comparisons, O(1) swaps
**    Average performance	        О(n2) comparisons, О(n) swaps
**    Worst-case space complexity	O(1) auxiliary
*/

#include <iostream>

void swap(int &value1, int &value2)
{
    value1 = value1 ^ value2;
    value2 = value1 ^ value2;
    value1 = value1 ^ value2;
    
}

void selection_sort(int arr[], const int SIZE)
{
    for (size_t i = 0; i < SIZE; ++i)
    {
        int min = i;

        for (size_t j = i + 1; j < SIZE; ++j)
        {
            if (arr[j] < arr[min])
                min = j;

        }
        if (min != i)
            swap(arr[i], arr[min]);
    } 


}

int main()
{
    const int SIZE = 10;
    int *arr = new int[SIZE];

    srand(time(0));

    for (size_t i = 0; i < SIZE; ++i)
        arr[i] = rand() % 100;

    std::cout << "Before sorting." << std::endl;
    for (size_t i = 0; i < SIZE; ++i)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    selection_sort (arr, SIZE);

    std::cout << "After sorting." << std::endl;
    for (size_t i = 0; i < SIZE; ++i)
        std::cout << arr[i] << " ";
    std::cout << std::endl;


    return 0;
}