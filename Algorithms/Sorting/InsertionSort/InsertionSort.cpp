#include <iostream>

void fill(int arr[], const int SIZE)
{
    srand(time(0));

    for (int i = 0; i < SIZE; ++i)
        arr[i] = rand() % 1000;

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
    {
        int k = i;
        int j = i - 1;
            
        while (k != 0)
        {
            if (arr[k] < arr[j])
                swap(arr[k], arr[j]);
            k = j;
            --j;
        }
    }

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