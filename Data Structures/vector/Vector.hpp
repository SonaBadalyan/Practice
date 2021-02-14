#ifndef VECTOR_H
#define VECTOR_H

template <typename T>
class Vector
{ 
    public: 
        Vector();
        void push(T *data);
        void push(T *data, int index);
        T get(int index);
        void pop();
        int size();
        int get_capacity();
        void print();

    private:
        T *m_array;
        int m_index;
        int m_capacity;
};

#endif // VECTOR_H