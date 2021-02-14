#include <iostream>
#include "Vector.hpp"

template <typename T>
Vector<T>::Vector()
{
    m_array = new T[1];
    m_capacity = 1;
    m_index = 0;
}

template <typename T>
void Vector<T>::push(T *data)
{
    if (m_index == m_capacity)
    {
        T *temp_array = new T[2 * m_capacity];

        for (int i = 0; i < m_capacity; ++i)
            temp_array[i] = m_array[i];

        delete[] m_array;
        m_capacity *= 2;
        m_array = temp_array;
    }

    m_array[m_index] = data;
    ++m_index;
}

template <typename T>
void Vector<T>::push(T *data, int index)
{
    if (m_capacity == index)
    {
        push(data);
    }
    else 
        m_array[index] = data;
}

template <typename T>
T Vector<T>::get(int index)
{
    if (index < m_index)
        return m_array[index];
}

template <typename T>
void Vector<T>::pop()
{
    --m_capacity;
}
        
template <typename T>
int Vector<T>::size()
{
    return m_index;
}

template <typename T>
int Vector<T>::get_capacity()
{
    return m_capacity;
}

template <typename T>
void Vector<T>::print()
{
    for(int i = 0; i < m_index; ++i)
        std::cout << i << " ";

    std::cout << std::endl;
}