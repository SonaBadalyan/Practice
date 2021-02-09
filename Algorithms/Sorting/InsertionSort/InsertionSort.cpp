/*
** Worst-case performance	    О(n2) comparisons and swaps
** Best-case performance	    O(n) comparisons, O(1) swaps
** Average performance	        О(n2) comparisons and swaps
** Worst-case space complexity	О(n) total, O(1) auxiliary
*/

#include <iostream>

void fill(int arr[], const int SIZE)
{
    srand(time(0));

    for (int i = 0; i < SIZE; ++i)
        arr[i] = rand() % 100;

}

void print(int arr[], const int SIZE)
{
    for (int i = 0; i < SIZE; ++i)
        std::cout << arr[i] << "  ";

    std::cout << std::endl;
}

void swap(int &value1, int &value2)
{
    value1 = value1 ^ value2;
    value2 = value1 ^ value2;
    value1 = value1 ^ value2;
}

void insertion_sort(int arr[], const int SIZE)
{
    for (int i = 1; i < SIZE; ++i) 
        for (int j = i; j != 0; --j)
            if (arr[j - 1] > arr[j])
                swap(arr[j -1], arr[j]);
}

int main()
{
    const int SIZE = 10;
    int *arr = new int[SIZE];

    fill(arr, SIZE);

    std::cout << "Before sorting." << std::endl;
    print(arr, SIZE);

    insertion_sort(arr, SIZE);

    std::cout << "After sorting." << std::endl;
    print(arr, SIZE);

    delete[] arr;

    return 0;
}