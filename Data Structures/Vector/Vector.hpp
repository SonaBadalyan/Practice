#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <exception>

template <typename T>
class Vector
{ 
    public:

        class Iterator
        {
            public:
                Iterator() = delete;
                Iterator(T* elem);
                Iterator(const Iterator& rhs);
                Iterator& operator=(const Iterator& rhs);

                Iterator& operator++(); 
                Iterator operator++(int); 
                Iterator& operator--(); 
                Iterator operator--(int); 

                const T& operator*() const;

                bool operator==(const Iterator& rhs) const;
                bool operator!=(const Iterator& rhs) const;
                bool operator<(const Iterator& rhs) const;
                bool operator<=(const Iterator& rhs) const;
                bool operator>(const Iterator& rhs) const;
                bool operator>=(const Iterator& rhs) const;
                               
            private:
                T* m_elem = nullptr;
        };

    public: 

        Vector();
        Vector(T fill_elems, size_t size);
        Vector(size_t size);
        
        Vector(const Vector<T>& rhs); 
        Vector(Vector<T>&& rhs) noexcept;

        Vector<T>& operator=(const Vector<T>& rhs);
        Vector<T>& operator=(Vector<T>&& rhs) noexcept;
        
        void push_back(T elem);
        void insert(T elem, size_t index);
        void pop();
        
        const T& at(size_t index) const;
        const T& back() const;
        const T& front() const;
        const T& operator[](size_t index) const;

        size_t size() const;
        bool empty() const;
        size_t get_capacity() const;

        void print() const;

        void reserve(size_t capacity);

        Iterator begin() const;
        Iterator end() const;

        ~Vector();

    private:
        size_t m_capacity = 0;
        size_t m_index = -1;
        T *buffer = nullptr;   
};

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
        throw std::logic_error("WTF");

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
        throw std::logic_error("WTF");

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
        throw std::logic_error("WTF");

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
        throw std::logic_error("WTF");

    --m_index;
}

template <typename T>
const T& Vector<T>::at(size_t index) const
{
    if (index < 0 || index >= m_index)
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
void Vector<T>::reserve(size_t capacity)
{
    if (capacity < m_capacity)
        throw std::logic_error("WTF");

    T *temp_array = new T[capacity];

    for (size_t i = 0; i < m_capacity; ++i)
        temp_array[i] = buffer[i];

    delete[] buffer;
    m_capacity = capacity;
    buffer = temp_array;
}

template <typename T>
typename Vector<T>::Iterator Vector<T>::begin() const
{
    return Iterator(&buffer[0]);
}

template <typename T>
typename Vector<T>::Iterator Vector<T>::end() const
{
    return Iterator(&buffer[m_index]);
}

template <typename T>
Vector<T>::~Vector()
{
    m_capacity = 0;
    m_index = 0;
    delete[] buffer;
}

template <typename T>
Vector<T>::Iterator::Iterator(T* elem) 
                                    :   m_elem(elem)
{
}

template <typename T>
Vector<T>::Iterator::Iterator(const Iterator& rhs) 
                                                :   m_elem(rhs.m_elem)
{
}

template <typename T>
typename Vector<T>::Iterator& Vector<T>::Iterator::operator=(const Iterator& rhs)
{
    if (this != &rhs)
        m_elem = rhs.m_elem;
}

template <typename T>
typename Vector<T>::Iterator& Vector<T>::Iterator::operator++()
{
    ++m_elem;
    return *this;
}

template <typename T>
typename Vector<T>::Iterator Vector<T>::Iterator::operator++(int)
{
    Iterator temp = *this;
    operator++();
    return temp;
}

template <typename T>
typename Vector<T>::Iterator& Vector<T>::Iterator::operator--()
{
    --m_elem;
    return *this;
}

template <typename T>
typename Vector<T>::Iterator Vector<T>::Iterator::operator--(int) 
{
    Iterator temp = *this;
    operator--();
    return temp;
}

template <typename T>
const T& Vector<T>::Iterator::operator*() const
{
    return *m_elem;
}

template <typename T>
bool Vector<T>::Iterator::operator==(const typename Vector<T>::Iterator& rhs) const
{
    if (m_elem == rhs.m_elem)
        return true;
    return false;
}

template <typename T>
bool Vector<T>::Iterator::operator!=(const typename Vector<T>::Iterator& rhs) const
{
    return !operator==(rhs);
}

template <typename T>
bool Vector<T>::Iterator::operator<(const typename Vector<T>::Iterator& rhs) const
{
    if (m_elem < rhs.m_elem)
        return true;
    return false;
}

template <typename T>
bool Vector<T>::Iterator::operator<=(const typename Vector<T>::Iterator& rhs) const
{
    if (m_elem <= rhs.m_elem)
        return true;
    return false;
}

template <typename T>
bool Vector<T>::Iterator::operator>(const typename Vector<T>::Iterator& rhs) const
{
    if (m_elem > rhs.m_elem)
        return true;
    return false;
}

template <typename T>
bool Vector<T>::Iterator::operator>=(const typename Vector<T>::Iterator& rhs) const
{
    if (m_elem >= rhs.m_elem)
        return true;
    return false;
}

#endif // VECTOR_H