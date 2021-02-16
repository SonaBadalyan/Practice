#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

#include "SortStrategy.hpp"

class BubbleSort : public SortStrategy
{
    public: 
       virtual void sort(int arr[], int SIZE) override;
};

#endif // BUBBLE_SORT_H