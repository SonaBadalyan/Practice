#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H

#include "SortStrategy.hpp"

class SelectionSort : public SortStrategy
{
    public: 
        virtual void sort(int arr[], int SIZE) override;
};

#endif // SELECTION_SORT_H