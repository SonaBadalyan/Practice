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
void Vector<T>::push_back(T elem)
{
    if (m_index == m_capacity)
        reserve(2); 

    m_array[m_index] = elem;
    ++m_index;
}

template <typename T>
void Vector<T>::insert(T elem, size_t index)
{
    if (m_index == index)
    {
        push_back(elem);
    }
    else 
    {

        if (m_index == m_capacity)
            reserve(2); 

        for (size_t i = ++m_index; i != -1; --i)
        {
            if(i == index)
            {
                m_array[i] = elem;
                break;
            }

            m_array[i] = m_array[i - 1];
        }

    }
        
}

template <typename T>
T Vector<T>::get(size_t index)
{
    if (index < m_index)
        return m_array[index];
    
    return -1;
}

template <typename T>
void Vector<T>::pop()
{
    --m_index;
}
        
template <typename T>
size_t Vector<T>::size()
{
    return m_index;
}

template <typename T>
size_t Vector<T>::get_capacity()
{
    return m_capacity;
}

template <typename T>
void Vector<T>::print()
{
    for(size_t i = 0; i < m_index; ++i)
        std::cout << m_array[i] << " ";

    std::cout << std::endl;
}

template <typename T>
void Vector<T>::reserve(size_t how_many_times)
{
    T *temp_array = new T[how_many_times * m_capacity];

    for (size_t i = 0; i < m_capacity; ++i)
        temp_array[i] = m_array[i];

    delete[] m_array;
    m_capacity *= how_many_times;
    m_array = temp_array;
}

//If you put a template implementation into a .cpp file you need to make sure that it gets instantiated: the compiler won't do it automatically for you.
// Explicitly instantiate only the classes you want to be defined.
template class Vector<int>;

