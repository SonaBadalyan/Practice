#include <iostream>
#include <exception>
#include "Vector.hpp"

template <typename T>
Vector<T>::Vector()
                :   m_capacity(1),   
                    m_index(0),
                    buffer(new T[m_capacity]) 
{}

template<typename T>
Vector<T>::Vector(T fill_elems, size_t size) 
                                            :   m_capacity(size),
                                                m_index(size),
                                                buffer(new T[m_capacity])
{
    if (size < 0)
        throw std::logic_error("WFT");

    for (size_t i = 0; i < m_capacity; ++i)
        buffer[i] = fill_elems;
}

template <typename T>
Vector<T>::Vector(size_t size) 
                            :   m_capacity(size),
                                m_index(size),
                                buffer(new T[m_capacity])
{
    if (size < 0)
        throw std::logic_error("WFT");

    for (size_t i = 0; i < m_capacity; ++i)
        buffer[i] = 0;
}

template <typename T>
Vector<T>::Vector(const Vector<T>& rhs)
                                        :   m_capacity(rhs.m_capacity),
                                            m_index(rhs.m_index),
                                            buffer(new T[m_capacity])
{
    for (size_t i = 0; i < m_index; ++i)
        buffer[i] = rhs.buffer[i];
}

template <typename T>
Vector<T>::Vector(Vector<T>&& rhs) noexcept
                                                :   m_capacity(rhs.m_capacity),
                                                    m_index(rhs.m_index),
                                                    buffer(rhs.buffer)
                                                    

{
    rhs.buffer = nullptr;
    rhs.m_capacity = 0;
    rhs.m_index = 0;
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& rhs)
{
    if (this != &rhs)
    {
        if (buffer != nullptr)
            delete[] buffer;

        buffer = new T[rhs.m_capacity];
        m_capacity = rhs.m_capacity;
        m_index = rhs.m_index;

        for (size_t i = 0; i < m_index; ++i)
            buffer[i] = rhs.buffer[i];
    }

    return *this;
}

template <typename T>
Vector<T>& Vector<T>::operator=(Vector<T>&& rhs) noexcept
{
    if (this != &rhs)
    {
        if (buffer != nullptr)
            delete[] buffer;

        buffer = rhs.buffer;
        m_capacity = rhs.m_capacity;
        m_index = rhs.m_index;

        rhs.buffer = nullptr;
        rhs.m_capacity = 0;
        rhs.m_index = 0;  
    }

    return *this;
}

template <typename T>
void Vector<T>::push_back(T elem)
{
    if (m_index == m_capacity)
        reserve(2 * m_capacity); 

    buffer[m_index] = elem;
    ++m_index;
}

template <typename T>
void Vector<T>::insert(T elem, size_t index)
{
    if (index < 0)
        throw std::logic_error("WFT");

    if (index > m_index)
        throw std::out_of_range("trying insert into an incorrect position");

    if (m_index == index)
    {
        push_back(elem);
    }
    else 
    {
        if (m_index == m_capacity)
            reserve(2 * m_capacity); 

        for (size_t i = m_index + 1; i != -1; --i)
        {
            if(i == index)
            {
                buffer[i] = elem;
                break;
            }

            buffer[i] = buffer[i - 1];
        }

        ++m_index;
    }
}


template <typename T>
void Vector<T>::pop()
{
    if (m_index == -1)
        throw std::logic_error("WFT");

    --m_index;
}

template <typename T>
const T& Vector<T>::at(size_t index) const
{
    if (index < -1 || index >= m_index)
        throw std::logic_error("WTF");
    
    return buffer[index];
}

template <typename T>
const T& Vector<T>::back() const
{
    return buffer[m_index - 1];
}

template <typename T>
const T& Vector<T>::front() const
{
    return buffer[0];
}

template <typename T>
const T& Vector<T>::operator[](size_t index) const
{
    return buffer[index];
}

template <typename T>
size_t Vector<T>::size() const 
{
    return m_index;
}

template <typename T>
bool Vector<T>::empty() const
{
    if (m_index == -1)
        return true;

    return false;
}

template <typename T>
size_t Vector<T>::get_capacity() const
{
    return m_capacity;
}

template <typename T>
void Vector<T>::print() const 
{
    for(size_t i = 0; i < m_index; ++i)
        std::cout << buffer[i] << " ";

    std::cout << std::endl;
}

template <typename T>
void Vector<T>::reserve(size_t size)
{
    if (size < m_capacity)
        throw std::logic_error("WTF");

    T *temp_array = new T[size];

    for (size_t i = 0; i < m_capacity; ++i)
        temp_array[i] = buffer[i];

    delete[] buffer;
    m_capacity = size;
    buffer = temp_array;
}

template <typename T>
typename Vector<T>::Iterator Vector<T>::begin() const
{
    return Iterator(this, 0);
}

template <typename T>
typename Vector<T>::Iterator Vector<T>::end() const
{
    return Iterator(this, m_index + 1);
}

template <typename T>
Vector<T>::~Vector()
{
    delete[] buffer;
    m_capacity = 0;
    m_index = 0;
}

// Iterator& Vector:Iterator::operator++()
// {

// }

//If you put a template implementation into a .cpp file you need to make sure that it gets instantiated: the compiler won't do it automatically for you.
// Explicitly instantiate only the classes you want to be defined.
template class Vector<int>;


