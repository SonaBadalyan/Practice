#ifndef FORWARD_LIST_H
#define FORWARD_LIST_H
#include <cstddef>

template <typename T>
class ForwardList
{
    public:

    typedef T value_type;
    typedef value_type&  reference;
    typedef const reference const_reference;
    typedef size_t size_type;

    class Node
    {
        value_type *data = value_type();
        Node *next = nullptr;
    };
 
    ForwardList() : head(nullptr) {}

    ForwardList(size_type count, const value_type& value = value_type())
    {
        head->data = value;

        if ( 1 = count )
        {
            head->next = nullptr; 

        }


    }

    ForwardList(const ForwardList& rhs)
    {

    }

    ForwardList(ForwardList&& rhs)
    {

    }

    ForwardList& operator=(const ForwardList& rhs)
    {

    }

    ForwardList operator=(ForwardList&& rhs)
    {

    }

    void clear()
    {

    }

    void insert_after(const_reference value)
    {

    }

    void emplace_after(const_reference value)
    {

    }

    void erase_after()
    {

    }

    void push_front(const_reference value)
    {

    }

    void emplace_front(const_reference value)
    {

    }

    void pop_front()
    {

    }

    void resize(size_type size)
    {

    }

    void swap(const ForwardList& rhs)
    {

    }

    reference front()
    {

    }

    reference before_begin()
    {

    }

    reference cbegin()
    {

    }

    reference cend()
    {

    }

    ~ForwardList()
    {

    }

    private:

    Node *head = nullptr;
};

#endif // FORWARD_LIST_H