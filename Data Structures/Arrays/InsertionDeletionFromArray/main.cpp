#include<iostream>

void fillArray(int array[], int filledSize)
{
    for(int i = 0; i < filledSize; ++i)
    {
        array[i] = i * 10;
    }
}

void printArray(int array[], int filledSize)
{
    for(int i = 0; i < filledSize; ++i)
    {
        std::cout << array[i] << "  ";
    }

    std::cout << std::endl;
}

bool insert (int array[], int& filledSize, int pos, int num)
{
    // We can also swap pos-th and filedSize-th elements, if array continuity dose not interest us.

    if (pos < 0 || pos > filledSize)
    {
        return false;
    }

    for (int i = filledSize; i > pos; --i)
    {
        array[i] = array[i - 1];
    }

    array[pos] = num;
    ++filledSize;
    return true;
}

int remove(int array[], int& filledSize, int pos)
{
    // We can also swap pos-th and filedSize-th elements, if array continuity dose not interest us.

    if (pos < 0 || pos > filledSize)
    {
        return -1;
    }

    int deletedNum = array[pos];

    for (int i = pos; i < filledSize - 1; ++i)
    {
        array[i] = array[i + 1];
    }

    --filledSize;

    return deletedNum;
}

int main()
{
    int array[10];
    int size = sizeof(array)/sizeof(array[0]);
    int filledSize = 5;

    fillArray(array, filledSize);
    printArray(array, filledSize);

    int pos = filledSize / 2;
    int num = 5;

    std::cout << "Is insertied? ";

    if(insert(array, filledSize, pos, num) )
    {
        std::cout << "Yes! " << std::endl;
    }
    else
    {
        std::cout <<"No! " << std::endl;
    }

    printArray(array, filledSize);

    std::cout << "Is deleted? ";

    int deletedNum = remove(array, filledSize, pos);

    if( -1 != deletedNum )
    {
        std::cout << "Yes! We are deleted " << deletedNum << " value from array!" <<  std::endl;
    }
    else
    {
        std::cout <<"No! " << std::endl;
    }

    printArray(array, filledSize);


    return 0;
}