#include <iostream>

#include "SortingContext.hpp"

#include "BubbleSort.hpp"
#include "InsertionSort.hpp"
#include "SelectionSort.hpp"

SortingContext::SortingContext() : strategy (nullptr) {}

void SortingContext::setSorting(int type)
{
    delete strategy;
    
    switch (type)
    {
    case Bubble:
    {
        strategy = new BubbleSort();
        break;
    }
    case Insertion:
    {
        strategy = new InsertionSort();
        break;
    }
    case Selection:
    {
        strategy = new SelectionSort();
        break;
    }
    }

}

void SortingContext::doSort()
{
    const int SIZE = 10;
    int *arr = new int [SIZE];

    srand(time(0));

    for(int i = 0; i < SIZE; ++i)
        arr[i] = rand() % 100;

    std::cout << "Before sorting." << std::endl;
    for (int i = 0; i < SIZE; ++i)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    strategy->sort(arr, SIZE);

    std::cout << "After sorting." << std::endl;
    for (int i = 0; i < SIZE; ++i)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

}