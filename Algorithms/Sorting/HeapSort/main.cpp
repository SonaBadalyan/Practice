/*
** Worst-case performance	    O(n\log n)
** Best-case performance	    O(n\log n)
** Average performance	        O(n\log n)
** Worst-case space complexity	O(n) 
*/

#include <iostream>

void heapify(int arr[], size_t n, size_t i)
{
    size_t largest = i; 
    size_t l = 2 * i + 1; 
    size_t r = 2 * i + 2; 

    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    if (largest != i) 
    {
        std::swap(arr[i], arr[largest]);

        heapify(arr, n, largest);
    }
}
 
void heapSort(int arr[], size_t n)
{
    for ( size_t i = n / 2 - 1; i >= 0; --i )
        heapify(arr, n, i);
 
    for ( size_t i = n - 1; i > 0; --i ) 
    {
        std::swap(arr[0], arr[i]);
 
        heapify(arr, i, 0);
    }
}
 
void printArray(int arr[], size_t n)
{
    for ( size_t i = 0; i < n; ++i )
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}
 
int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    size_t n = sizeof(arr) / sizeof(arr[0]);
 
    heapSort(arr, n);
 
    std::cout << "Sorted array is \n";
    printArray(arr, n);

    return 0;
}