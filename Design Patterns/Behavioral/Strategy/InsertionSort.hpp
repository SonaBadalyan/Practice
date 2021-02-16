#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include "SortStrategy.hpp"

class InsertionSort : public SortStrategy
{
    public: 
        virtual void sort(int arr[], int SIZE) override;
};

#endif // INSERTION_SORT_H