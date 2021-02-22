#ifndef FORWARD_LIST_H
#define FORWARD_LIST_H

#include <iostream>
#include <cstddef>
#include <exception>

template <typename T>
class ForwardList
{
    public:

    typedef T value_type;
    typedef size_t size_type;

    struct Node
    {
        value_type data = value_type();
        Node *next = nullptr;
    };
 
    ForwardList() : head(nullptr) {}

    explicit ForwardList(size_type count, const value_type& value = value_type())
    {
        if ( count <= 0 ) 
            throw std::logic_error("WTF");

        head = new Node();
        head->data = value;

        if ( 1 == count )
        {
            head->next = nullptr; 
            return;
        }

        --count;

        Node *prev = new Node();
        prev->data = value;
        head->next = prev;
        prev->next = nullptr;

        while ( --count )
        {
            Node *next = new Node();
            next->data = value;
            prev->next = next;
            next->next = nullptr;
            prev = next;
        }
    }

    void print () const
    {
        Node *curr = head;

        while ( curr != nullptr )
        {
            std::cout << curr->data << " ";
            curr = curr->next;
        }

        std::cout << std::endl;

    }

    ForwardList(const ForwardList& rhs)
    {
        if ( rhs.head == nullptr )
        {
            head = nullptr;
            return;
        }

        Node *curr = rhs.head;

        while ( curr != nullptr )
        {
            push_back(curr->data);
            curr = curr->next;
        }
    }

    ForwardList(ForwardList&& rhs) : head(rhs.head)
    {   
        rhs.head = nullptr;
    }

    ForwardList& operator=(const ForwardList& rhs)
    {
        if ( &rhs != this)
        {
            if ( rhs.head == nullptr )
            {
                head = nullptr;
                return *this;
            }

            Node *curr = rhs.head;

            while ( curr != nullptr )
            {
                push_back(curr->data);
                curr = curr->next;
            }
        }
        return *this;
    }

    ForwardList& operator=(ForwardList&& rhs)
    {
        head = rhs.head;
        rhs.head = nullptr;
        return  *this;
    }

    void clear()
    {
        Node *curr = head;

        while ( curr != nullptr )
        {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }

        head = nullptr;
    }

    void insert_after(size_type pos, value_type value)
    {
        if ( pos < 0 )
            throw std::logic_error("WTF");

        if ( pos == 0 )
        {
            push_front(value);
            return;
        }

        size_type i = 0;

        Node *prev = head;
        Node *next = prev->next;

        while ( ++i < pos )
        {
            prev = next;
            next = next->next;
        }

        Node *new_node = new Node();
        new_node->data = value;
        prev->next = new_node;
        new_node->next = next;
        
    }

    void emplace_after(size_type pos, value_type value)
    {
        if ( pos < 0 )
            throw std::logic_error("WTF");

        if ( pos == 1 )
        {
            emplace_front(value);
            return;
        }

        size_type i = 0;

        Node *prev = head;
        Node *next = prev->next;

        while ( ++i < pos )
        {
            prev = next;
            next = next->next;
        }

        Node *new_node = new Node();
        new_node->data = value;
        prev->next = new_node;
        new_node->next = next->next;
        delete next;
    }

    void erase_after(size_type pos)
    {
        if ( pos < 0 )
            throw std::logic_error("WTF");

        if ( pos == 0 )
            pop_front();

        size_type i = 0;

        Node *prev = head;
        Node *next = prev->next;

        while ( ++i < pos )
        {
            prev = next;
            next = next->next;
        }

        prev->next = next->next;
        delete next;
    }

    void push_front(value_type value)
    {
        Node *new_node = new Node();
        new_node->data = value;
        new_node->next = head;
        head = new_node;
    }

    void push_back(value_type value)
    {
        if ( head == nullptr )
        {
            push_front(value);
            return;
        }

        Node *curr = head;

        while ( curr->next != nullptr )
            curr = curr->next;

        Node *new_node = new Node();
        new_node->data = value;
        new_node->next = nullptr;
        curr->next = new_node;
    }

    void emplace_front(value_type value)
    {
        Node *new_node = new Node();
        new_node->data = value;
        new_node->next = head->next;
        delete head;
        head = new_node;
    }

    void pop_front()
    {
        Node *new_head = head->next;
        delete head;
        head = new_head;
    }

    size_type size() const 
    {
        size_type i = 0;

        Node *curr = head;

        while ( curr != nullptr )
        {
            ++i;
            curr = curr->next;
        }

        return i;
    }

    value_type front()
    {
        return head->data;
    }

    ~ForwardList()
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
};

#endif // FORWARD_LIST_H