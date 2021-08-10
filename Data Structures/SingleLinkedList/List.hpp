#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>

class List
{      
    public:
    class Node
    {
        public:
        Node* next = nullptr; 
        int data;
    };

    List();
    ~List();

    void insert(int val, int pos);
    void remove(int pos);
    int get(int pos);
    int find(int value);
    int size();
    bool hasLoop();

    private:
    Node* head = nullptr;
};

std::ostream& operator<<(std::ostream& os, List& list);

#endif //LIST_HPP

