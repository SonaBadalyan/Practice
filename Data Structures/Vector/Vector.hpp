#ifndef VECTOR_H
#define VECTOR_H

template <typename T>
class Vector
{ 
    public:
        class Iterator
        {
            public:
                Iterator();
                Iterator(const Vector<T> *vector, size_t iter_Intex) 
                                                                    :   m_pVector(vector), 
                                                                        m_iter_Intex(iter_Intex)
                {}
                Iterator(const Iterator& rhs) 
                                            :   m_pVector(rhs.m_pVector),
                                                m_iter_Intex(rhs.m_iter_Intex)
                {}
                Iterator(Iterator&& rhs);
                Iterator& operator=(const Iterator& rhs);
                Iterator& operator=(Iterator&& rhs);

                Iterator& operator++(); 
                Iterator operator++(int); 
                Iterator& operator--(); 
                Iterator operator--(int); 

                const T& operator*() const;
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

#endif // VECTOR_H