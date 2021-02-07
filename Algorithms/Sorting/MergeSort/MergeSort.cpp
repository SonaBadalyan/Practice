#include <iostream>

void print(int arr[], int SIZE)
{
    for (size_t i = 0; i < SIZE; ++i)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

void MergeSort(int arr[], int SIZE)
{


}

int main()
{
    const int SIZE = 10;
    int *arr = new int[SIZE];

    srand(time(0));
    for (size_t i = 0; i < SIZE; ++i)
        arr[i] = rand() % 100;

    std::cout << "Before sorting. " << std::endl;
    print(arr, SIZE);

    MergeSort(arr, SIZE);

    std::cout << "After sorting." << std::endl;
    print(arr, SIZE);

    delete[] arr;

    return 0;
}