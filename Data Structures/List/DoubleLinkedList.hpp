#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

#include <cstddef>
#include <iostream>

template <typename T>
class DoubleLinkedList
{
    public:

    typedef T value_type;
    typedef size_t size_type;
    typedef value_type& reference;
    typedef const value_type& const_reference;

    struct Node
    {
        value_type data = value_type();
        Node *prev = nullptr;
        Node *next = nullptr;
    };
    
    DoubleLinkedList() : head (nullptr), tail (nullptr) {}
    
    explicit DoubleLinkedList( size_type count, const value_type& val = value_type() )
    {
        if ( 1 == count)
        { 
            head = new Node();
            head->data = val;
            tail = head;
            return;
        }

        if ( 2 == count )
        {
            head = new Node();
            tail = new Node();

            head->next = tail;
            head->data = val;

            tail->prev = head;
            tail->data = val;

            return;
        }

        if ( 3 == count )
        {
            head = new Node();
            Node *mid = new Node();
            tail = new Node();

            head->next = mid;
            head->data = val;
            
            mid->prev = head;
            mid->next = tail;
            mid->data = val;

            tail->prev = mid;
            tail->data = val;

            return;
        }

        head = new Node();    
        Node *curr = new Node();
        Node *next = new  Node();
        tail = new Node();

        head->next = curr;
        head->data = val;

        curr->prev = head;
        curr->next = next; 
        curr->data = val;

        next->prev = curr;
        next->data = val;

        size_type remain = count - 4;

        while ( remain-- )
        {
            curr = next;
            next = new Node();
            curr->next = next;
            curr->data = val;
            next->prev = curr;
        }

        next->next = tail;
        next->data = val;

        tail->prev = next;
        tail->data = val;
    }

    DoubleLinkedList(const DoubleLinkedList<value_type>& rhs) 
    {
        if ( rhs.head == nullptr)
            head = tail = nullptr;
        else
        { 
            Node *curr = rhs.head;

            while (curr != nullptr)
            {
                push_back(curr->data),
                curr = curr->next;
            }
        }
    }

    DoubleLinkedList(DoubleLinkedList<value_type>&& rhs)
                                                        :   head(rhs.head),
                                                            tail(rhs.tail)
    {
        rhs.head = nullptr;
        rhs.tail = nullptr;
    }

    DoubleLinkedList<value_type>& operator=(const DoubleLinkedList<value_type>& rhs) 
    {
        if ( this != &rhs )
        {
            if ( rhs.head == nullptr )
                head = tail = nullptr;
            else
            { 
                Node *curr = rhs.head;

                while (curr != nullptr)
                {
                    push_back(curr->data),
                    curr = curr->next;
                }
            }
        }
        return *this;
    }
                                                                                    

    DoubleLinkedList<value_type>& operator=(DoubleLinkedList<value_type>&& rhs)
    {
        if ( this != &rhs )
        {
            head = rhs.head;
            tail = rhs.tail;
            rhs.head = nullptr;
            rhs.tail = nullptr;
        }
        return *this;
    }

    reference front() 
    {
        return head->data;
    }

    reference back()
    {
        return tail->data;
    }

    bool empty() const
    {
        return head == nullptr;
    }

    size_t size() const
    {
        Node *curr = head;
        size_t size = 0;

        while (curr != nullptr)
        {
            ++size;
            curr = curr->next;
        }

        return size;
    }

    void clear() noexcept
    {
        Node *curr = head;

        while ( curr != nullptr )
        {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }

        head = tail = nullptr;
    }

    void insert( size_t pos, const_reference value )
    {
        if ( 0 == pos )
        {
            push_front(value);
            return;
        }

        if ( size() == pos )
        {
            push_back(value);
            return;
        }

        Node *curr = head;
        size_t  i = 0;

        while ( curr->next != nullptr )
        {
            ++i;

            if ( i == pos)
            {
                Node *new_node = new Node();
                new_node->data = value;
                new_node->prev = curr;
                new_node->next = curr->next->next;
                curr->next = new_node;
                break;
            }

            curr = curr->next;
        }

    }

    void erase( size_t pos )
    {
        if ( 1 == pos )
        {
            pop_front();
            return;
        }

        if ( size() == pos )
        {
            pop_back();
            return;
        }

        Node *curr = head;
        size_t  i = 0;

        while ( curr->next != nullptr )
        {
            ++i;

            if ( i == pos)
            {
                curr->prev->next = curr->next;
                curr->next->prev = curr->prev;
                delete curr;
                break;
            }

            curr = curr->next;
        }

    }

    void erase( size_t first, size_t last )
    {

    }

    void push_back( const_reference value )
    {
        if ( tail == nullptr )
        {
            tail = new Node();
            tail->data = value;
            head = tail;
        }
        else
        {
            Node *new_node = new Node();
            new_node->data = value;
            new_node->prev = tail;
            new_node->next = nullptr;
            tail->next = new_node;
            tail = new_node;
        }
    }

    void pop_back()
    {
        if ( 1 == size() )
        {
            delete tail;
            tail = head = nullptr;
            return;
        }

        if ( !empty() )
        {
            Node *new_tail = tail;
            new_tail = tail;

            tail = tail->prev;
            tail->next = nullptr;

            delete new_tail;
        }
    }

    void push_front( const_reference value )
    {
        if ( head == nullptr )
        {
            head = new Node();
            head->data = value;
            tail = head;
        }
        else
        {
            Node *new_node = new Node();
            new_node->prev = nullptr;
            new_node->data = value;
            new_node->next = head;
            head = new_node;
        }
    }
    
    void pop_front()
    {
        if ( 1 == size() )
        {
            delete head;
            head = tail = nullptr;
            return;
        }

        if ( !empty() )
        {
            Node *new_head = head;
            new_head = head;

            head = head->next;
            head->prev = nullptr;

            delete new_head;
        }
    }

    void resize( size_type count, value_type value = value_type() )
    {
        size_t m_size = size();

        if ( m_size == count ) return;

        if ( m_size < count )
        {
            while ( m_size != count )
            {
                push_back(value);
                ++m_size;
            }
        }
        else 
        {
            while ( size() != count )
            {
                pop_back();
                --m_size;
            }
        }
    }

    void swap( DoubleLinkedList<value_type>& rhs )
    {
        auto temp = head;
        head = rhs.head;
        rhs.head = temp;
    
        temp = tail;
        tail = rhs.tail;
        rhs.tail = tail;
    }

    void print () const
    {
        Node *curr = head;

        while (curr != nullptr)
        {
            std::cout << curr->data << " ";
            curr = curr->next;
        }

        std::cout << std::endl;

    }

    ~DoubleLinkedList()
    {
        Node *curr = head;

        while ( curr != nullptr )
        {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
    }

    private:
        Node *head = nullptr;
        Node *tail = nullptr;
};

#endif // DOUBLE_LINKED_LIST_H
