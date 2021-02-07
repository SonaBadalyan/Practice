/*
** Worst-case performance	    O(n logn)
** Best-case performance	    O(n logn)
** Average performance	        O(n logn)
** Worst-case space complexity	O(n)
*/

#include <iostream>

void print(int arr[], int SIZE)
{
    for (size_t i = 0; i < SIZE; ++i)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

void Merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int *R = new int [n1];

    int n2 = right - mid;
    int *L = new int [n2];

    for (int i = 0; i <= n1; ++i)
        R[i] = arr[left + i];

    for (int j = 0; j <= n2; ++j)
        L[j] = arr[mid + 1 + j];

    int i = 0; 
    int j = 0;
    int k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            ++i;
        }
        else
        {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        ++i;
        ++k;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        ++j;
        ++k;
    }
}

void MergeSort(int arr[], int left, int right)
{
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;

    MergeSort(arr, left, mid);
    MergeSort(arr, mid + 1, right);
    Merge(arr, left, mid, right);
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

    MergeSort(arr, 0, SIZE - 1);

    std::cout << "After sorting." << std::endl;
    print(arr, SIZE);

    delete[] arr;

    return 0;
}