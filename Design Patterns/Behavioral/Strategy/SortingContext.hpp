#ifndef SORTING_CONTEXT_H
#define SORTING_CONTEXT_H

class SortStrategy;

class SortingContext
{
    public:
    
        enum SortingType
        {
            Bubble = 1, Insertion = 2, Selection = 3,
        };

        SortingContext();
        void setSorting(int type);
        void doSort();

    private:
        SortStrategy* strategy;
};

#endif // SORTING_CONTEXT_H

