#ifndef VECTOR_H
#define VECTOR_H

template <typename T>
class Vector
{ 
    public: 
        Vector();
        void push_back(T elem);
        void insert(T elem, size_t index);
        T get(size_t index);
        void pop();
        size_t size();
        size_t get_capacity();
        void print();
        void reserve(size_t how_many_times);

    private:
        T *m_array;
        size_t m_index;
        size_t m_capacity;
};

#endif // VECTOR_H