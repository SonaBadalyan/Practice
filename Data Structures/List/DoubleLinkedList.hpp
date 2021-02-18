#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

#include <cstddef>

template <typename T>
class DoubleLinkedList
{
    public:
        struct Node
        {
            T data;
            Node *prev;
            Node *next;
        };

        class Iterator
        {

        };

    typedef T value_type;
    typedef size_t size_type;
    typedef value_type& reference;
    typedef const value_type& const_reference;
    typedef Iterator iterator;
    typedef const Iterator const_iterator;
    
    DoubleLinkedList();
    explicit DoubleLinkedList( size_type count );
    DoubleLinkedList(size_t size, T elem);
    DoubleLinkedList(const DoubleLinkedList<T>& rhs);
    DoubleLinkedList(DoubleLinkedList<T>&& rhs);

    DoubleLinkedList& operator=(const DoubleLinkedList<T>& rhs);
    DoubleLinkedList& operator=(DoubleLinkedList<T>&& rhs);

    iterator begin();
    const_iterator begin() const;
    const_iterator cbegin() const;

    iterator end();
    const_iterator end() const;
    const_iterator cend() const;

    // reverse_iterator rbegin();
    // reverse_iterator rbegin() noexcept;
    // const_reverse_iterator rbegin() const;
    // const_reverse_iterator rbegin() const noexcept;
    // const_reverse_iterator crbegin() const noexcept;

    // reverse_iterator rend();
    // reverse_iterator rend() noexcept;
    // const_reverse_iterator rend() const;
    // const_reverse_iterator rend() const noexcept;
    // const_reverse_iterator crend() const noexcept;

    reference front();
    const_reference front() const;
    reference back();
    const_reference back() const;

    bool empty() const;
    size_t size() const;

    void clear() noexcept;
    iterator insert( iterator pos, const_reference value );
    iterator erase( iterator pos );
    iterator erase( iterator first, iterator last );
    void push_back( const_reference value );
    void pop_back();
    void push_front( const_reference value );
    void pop_front();
    void resize( size_type count );
    void resize( size_type count, T value = T() );
    void resize( size_type count, const value_type& value );
    void swap( DoubleLinkedList& other );

    ~DoubleLinkedList();

    private:
        size_type m_index = 0;
        Node *head = nullptr;
        Node *tail = nullptr;

};

template< typename T >
bool operator==( const DoubleLinkedList<T>& lhs,
                 const DoubleLinkedList<T>& rhs );

template< typename T >
bool operator!=( const DoubleLinkedList<T>& lhs,
                 const DoubleLinkedList<T>& rhs );

template< typename T >
bool operator<( const DoubleLinkedList<T>& lhs,
                 const DoubleLinkedList<T>& rhs );

template< typename T >
bool operator<=( const DoubleLinkedList<T>& lhs,
                 const DoubleLinkedList<T>& rhs );

template< typename T >
bool operator>( const DoubleLinkedList<T>& lhs,
                 const DoubleLinkedList<T>& rhs );

template< typename T >
bool operator>=( const DoubleLinkedList<T>& lhs,
                 const DoubleLinkedList<T>& rhs );

#endif // DOUBLE_LINKED_LIST_H
