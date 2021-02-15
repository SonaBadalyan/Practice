#ifndef VECTOR_H
#define VECTOR_H

template <typename T>
class Vector
{ 
    public:
        class Iterator
        {
            public:
                Iterator(const Vector<T> *vector, size_t iter_Intex) : m_pVector(vector), m_iter_Intex(iter_Intex){}
                Iterator(const Iterator& rhs);
                Iterator(const Iterator&& rhs);
                Iterator& operator=(const Iterator& rhs);
                Iterator& operator=(const Iterator&& rhs);
                const T& operator*() const;
                Iterator& operator++(); // prefix
                Iterator operator++(int); // postfix
                Iterator& operator--(); // prefix
                Iterator operator--(int); // postfix
                bool operator!=(const Iterator& rhs) const;
                bool operator==(const Iterator& rhs) const;
                bool operator<(const Iterator& rhs) const;
                bool operator<=(const Iterator& rhs) const;
                bool operator>(const Iterator& rhs) const;
                bool operator>=(const Iterator& rhs) const;
            private:
                const Vector<T> *m_pVector;
                size_t m_iter_Intex = -1;
        };

    public: 
        Vector();
        // Vector(const Vector& rhs);
        // Vector(const Vector&& rhs);
        // Vector& operator=(const Vector& rhs);
        // Vector& operator=(const Vector&& rhs);
        void push_back(T elem);
        void insert(T elem, size_t index);
        T get(size_t index) const;
        void pop();
        size_t size() const;
        size_t get_capacity() const;
        void print() const;
        void reserve(size_t how_many_times);
        const T& operator[](size_t index);
        Iterator begin() const;
        Iterator end() const;

    private:
        T *m_array = nullptr;
        size_t m_index = 0;
        size_t m_capacity = 0;
};

#endif // VECTOR_H