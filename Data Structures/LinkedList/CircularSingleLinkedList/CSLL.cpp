#include <iostream>

class CSLL
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
                Node* next = nullptr;
        };

        CSLL()
        {
            head = nullptr;
        }

        void insertFront(int data)
        {
            if (isEmpty())
            {
                head = new Node (data);
                head->next = head;
                return;
            }

            Node* curr = head;

            while(curr->next != head)
            {
                curr = curr->next;
            }

            Node* newNode = new Node(data);
            newNode->next = head;
            curr->next = newNode;
            head = newNode;
        }

        void insertIndex(int data, int index)
        {
            if (index <= 0 || index > getLength() + 1)
            {
                return;
            }

            if (isEmpty())
            {
                head = new Node (data);
                head->next = head;
                return;
            }

            if (1 == index)
            {
                insertFront(data);
                return;
            }

            if (getLength() + 1 == index)
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
            curr->next = newNode;
        }

        void insertBack(int data)
        {
            if (isEmpty())
            {
                head = new Node (data);
                head->next = head;
                return;
            }

            Node* curr = head;

            while(curr->next != head)
            {
                curr = curr->next;
            }

            Node* newNode = new Node(data);
            curr->next = newNode;
            newNode->next = head;
        }

        bool removeFront()
        {
            if (isEmpty())
            {
                return false;
            }

            Node* curr = head;

            while(curr->next != head)
            {
                curr = curr->next;
            }

            curr->next = head->next;
            head = head->next;

        }

        bool removeIndex(int index)
        {
            if (index <= 0 || index > getLength())
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

            if (getLength() == index)
            {
                return removeBack();
            }

            Node* curr = head;
            Node* prev = head;

            while(curr->next != head && --index)
            {
                prev = curr;
                curr = curr->next;
            }

            prev->next = curr->next;
        }

        bool removeBack()
        {
            if (isEmpty())
            {
                return false;
            }

            Node* curr = head;

            while (curr->next->next != head)
            {
                curr = curr->next;
            }

            curr->next = head;
        }

        int getLength()
        {
            if (isEmpty())
            {
                return 0;
            }

            int size = 1;

            Node* curr = head;

            while (curr->next != head)
            {
                ++size;
                curr = curr->next;
            }

            return size;
        }

        bool isEmpty()
        {
            if(!head)
            {
                return true;
            }

            return false;
        }

        void print()
        {
            std::cout << "________________CSLL_______________" << std::endl;

            Node* curr = head;

            while(curr->next != head)
            {
                std::cout << curr->data << "    ";
                curr = curr->next;
            }
            std::cout << curr->data;
            std::cout << std::endl;
        }

    private:
        Node* head = nullptr;

};


int main()
{
    CSLL list;
    list.insertBack(12);
    list.insertFront(2);
    list.insertFront(3);
    list.insertIndex(67, 2);
    list.insertFront(23);
    list.insertBack(45);
    list.print();

    list.reverse();
    list.print();

    list.removeBack();
    list.print();

    list.removeFront();
    list.print();

    list.removeIndex(3);
    list.print();

    return 0;
}