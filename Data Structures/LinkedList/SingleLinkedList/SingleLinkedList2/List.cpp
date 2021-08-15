#include <iostream>
#include "List.hpp"

List::List()
{
    head = nullptr;
}

List::~List()
{
    Node *curr = head;

    while ( curr != nullptr )
    {
        Node* next = curr->next;
        delete curr;
        curr = next;
    }
}

void List::insert(int val, int pos)
{
    int i = 0;

    if ( pos == 0 )
    {
        Node *new_node = new Node();
        new_node->data = val;
        new_node->next = head;
        head = new_node;
        return;
    }

    Node *prev = head;
    Node *next = prev->next;

    while ( ++i < pos )
    {
        prev = next;
        next = next->next;
    }

    Node *new_node = new Node();
    new_node->data = val;
    prev->next = new_node;
    new_node->next = next;
}

void List::remove(int pos)
{
    if ( pos == 0 )
    {
        Node *new_head = head->next;
        delete head;
        head = new_head;
        return;
    }

    int i = 0;

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

int List::get(int pos)
{
    int i = 0;

    Node* curr = head;

    while ( curr != nullptr )
    {
        if ( i == pos )
        {
            return curr->data;
        }
        else
        {
            Node* next = curr->next;
            curr = next;
            ++i;
        }
    }

    return -1;
}

int List::find(int value)
{
    Node *prev = head;
    Node *next = prev->next;

    int i = 0;

    while ( prev->next != nullptr )
    {
        if (prev->data == value)
            return i;

        prev = next;
        next = next->next;
        ++i;
    }

    return next->data;
}

int List::size()
{
    Node *curr = head;
    int i = 0;

    while ( curr != nullptr )
    {
        Node* next = curr->next;
        curr = next;
        ++i;
    }

    return i;
}

bool List::hasLoop()
{
    Node *tortoise = head;
    Node *hare = head;
 
    while (tortoise && hare && hare->next) 
    {
        tortoise = hare->next;
        hare = hare->next->next;
        
        if (tortoise == hare) 
        {
            return 1;
        }
    }

    return 0;
}

std::ostream& operator<<(std::ostream& os, List& list)
{
    int i = 0;
    int size = list.size();
    
    while (i < size)
    {
        os << list.get(i) << std::endl;
        ++i;
    }

    return os;
}