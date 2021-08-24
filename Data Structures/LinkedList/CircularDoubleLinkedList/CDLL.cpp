#include <iostream>

class CDLL
{
    public:
        class Node 
        {
            public:

                Node(int data)
                {
                    this->data = data;
                }

                int data;
                Node* prev = nullptr;
                Node* next = nullptr;
        };

    void insertFront(int data)
    {
        if (isEmpty())
        {
            head = new Node(data);
            head->next = head;
            head->prev = head;

            ++length;
            return;
        }

        Node* newNode = new Node(data);
        newNode->next = head;
        newNode->prev = head->prev;
        head->prev->next = newNode;
        head->prev = newNode;

        ++length;

    }

    void insertBack(int data)
    {
        if (isEmpty())
        {
            head = new Node(data);
            head->next = head;
            head->prev = head;

            ++length;
            return;
        }

        Node* curr = head;

        while(curr->next != head)
        {
            curr = curr->next;
        }

        Node* newNode = new Node(data);
        curr->next = newNode;
        newNode->prev = curr;
        newNode->next = head;
        head->prev = curr;

        ++length;

    }

    void insertIndex(int data, int index)
    {
        if (index <= 0 || getLength() > index + 1)
        {
            return;
        }

        if (isEmpty())
        {
            head = new Node(data);
            head->next = head;
            head->prev = head;
            ++length;
            return;
        }

        if (1 == index)
        {
            insertFront(data);
            return;
        }

        if (index == length + 1)
        {
            insertBack(data);
            return;
        }

        Node* curr = head;

        while(curr->next != head && --index)
        {
            curr = curr->next;
        }

        Node* newNode = new Node(data);

        newNode->next = curr->next;
        newNode->prev = curr;

        curr->next->prev = newNode;
        curr->next = newNode;
    
        ++length;
    }


    bool removeFront()
    {
        if (isEmpty())
        {
            return false;
        }

        if (1 == length)
        {
            head = nullptr;
            return true;
        }

        head->prev->next = head->next;
        head->next->prev = head->prev;
        head = head->next;

        --length;
    }

    bool removeBack()
    {
        if (isEmpty())
        {
            return false;
        }

        if (1 == length)
        {
            head = nullptr;
            return true;
        }

        head->prev->prev->next = head;
        head->prev = head->prev->next;

        --length;
    }

    bool removeIndex(int index)
    {
        if (index <= 0 || getLength() > index)
        {
            return false;
        }

        if (isEmpty())
        {
            return false;
        }

        if (1 == index)
        {
            return removeFront();
        }

        if (length == index)
        {
            return removeBack();
        }

        Node* curr= head;

        while(curr->next != head && --index)
        {
            curr = curr->next;
        }

        curr->next = curr->next->next;
        curr->next->prev = curr;

        --length;

    }

    void print()
    {
        std::cout << " ______CDLL________" << std::endl;

        if (isEmpty())
        {
            std::cout << "List is empty!" << std::endl;
            return;
        }

        Node* curr = head;

        while (curr->next != head)
        {
            std::cout << curr->data << "  ";
            curr = curr->next;
        }

        std::cout << curr->data << "  " << std::endl; 

    }

    bool isEmpty()
    {
        if(!head)
        {
            return true;
        }
        return false;
    }

    void reverse()
    {
        if (isEmpty())
        {
            return;
        }
        
        Node* curr = head;
        Node* next;

        while(curr->next != head)
        {
            head = curr;
            next = curr->next;
            curr->next = curr->prev;
            curr->prev = next;
            curr = next;
        }

    }

    int getLength()
    {
        return length;
    }

    private:
        int length = 0;
        Node* head = nullptr;
};

int main()
{
    CDLL list;

    list.insertFront(2);
    list.insertBack(4);

    list.insertIndex(3, 2);
    list.insertIndex(45, 2);
    list.print();

    list.reverse();
    list.print();

    list.removeFront();
    list.print();
    list.removeBack();
    list.print();
    list.removeIndex(2);
    list.print();
    list.removeIndex(1);
    list.print();

    return 0;
}