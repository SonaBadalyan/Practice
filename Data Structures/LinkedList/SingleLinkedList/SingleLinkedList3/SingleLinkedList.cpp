#include <iostream>

class SingleLinkedList
{
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

    public:

        SingleLinkedList()
        {
            head = nullptr;
        }

        SingleLinkedList(const SingleLinkedList& rhs)
        {
            if (this == &rhs)
            {
                return;
            }

            Node* rhs_curr = rhs.head;

            while(rhs_curr)
            {
                insertBack(rhs_curr->data);
                rhs_curr = rhs_curr->next;
            }

        }

        bool operator==(const SingleLinkedList& rhs)
        {
            if (this == &rhs)
            {
                return true;
            }

            if(rhs.getLenght() != getLenght())
            {
                return false;
            }

            Node* curr = head;
            Node* rhs_curr = rhs.head;

            while(curr && rhs_curr)
            {
                if (curr->data != rhs_curr->data)
                {
                    return false;
                }

                curr = curr->next;
                rhs_curr = rhs_curr->next;
            }
            return true;
        }

        bool isEmpty() const
        {
            if (!head)
            {
                return true;
            }
            return false;
        }

        int getLenght() const
        {
            if (isEmpty())
            {
                return 0;
            }

            Node* curr = head;
            int lenght = 0;

            while(curr)
            {
                ++lenght;
                curr = curr->next;
            }

            return lenght;
        }

        int operator[](int index)
        {
            if (index <= 0 || index > getLenght())
            {
                return -1;
            }

            if (isEmpty())
            {
                return -1;
            }

            Node* curr = head;

            while(curr && --index)
            {
                curr = curr->next;
            }

            return curr->data;
        }

        void insertFront(int data)
        {
            if (isEmpty())
            {
                head = new Node(data);
                return;
            }

            Node* newNode = new Node(data);
            newNode->next = head;

            head = newNode;
        }

        void insert(int data, int index)
        {
            if (index <= 0 || index > getLenght())
            {
                return;
            }

            if (isEmpty())
            {
                head = new Node(data);
                return;
            }

            Node* curr = head;

            while(curr && index--)
            {
                curr = curr->next;
            }

            Node* next = curr->next;
            Node* newNode = new Node(data);
            curr->next = newNode;
            newNode->next = next;

        }

        void insertBack(int data)
        {
            if (isEmpty())
            {
                head = new Node(data);
                return;
            }

            Node* curr = head;

            while(curr->next)
            {
                curr = curr->next;
            }

            curr->next = new Node(data);
        }

        bool removeFront()
        {
            if (isEmpty())
            {
                return false;
            }

            head = head->next;
            return true;

        }

        bool remove(int index)
        {
            if (index <= 0 || index > getLenght())
            {
                return false;
            }

            if (isEmpty())
            {
                return false;
            }

            Node* curr = head;

            while(curr && --index)
            {
                curr = curr->next;
            }

            curr->next = curr->next->next;
            return true;
        }

        bool removeBack()
        {
            if (isEmpty())
            {
                return false;
            }

            Node* curr= head;

            while(curr->next->next)
            {
                curr = curr->next;
            }
            curr->next = nullptr;

            return true;
        }

        bool removeByValue(int data)
        {
            if (isEmpty())
            {
                return false;
            }

            Node* curr = head;

            while(curr->next)
            {
                if ( curr->next->data == data)
                {
                    curr->next = curr->next->next;
                    return true;
                }
            }

            return false;
        }

        void print()
        {
            std::cout << "________Single linked list print_________" << std::endl;

            Node* curr = head;

            while(curr)
            {
                std::cout << curr->data << "   ";
                curr = curr->next;
            }

            std::cout << std::endl;
        }

        SingleLinkedList* reverse()
        {
            SingleLinkedList* newList(this);

            Node* prev = nullptr;
            Node* curr = head;
            Node* next = head;

            while(next)
            {
                next = next->next;
                curr->next = prev;

                prev = curr;
                curr = next;
            }

            head = prev;
            return newList;
        }

        void reversePrint()
        {

            SingleLinkedList* newList = reverse();

            newList->print();

        }

        bool findByValue(int data)
        {
            if (isEmpty())
            {
                return false;
            }

            Node* curr = head;

            while (curr)
            {
                if(curr->data == data)
                {
                    return true;
                }

                curr = curr->next;
            }

            return false;
        }

    private:
        Node* head = nullptr;
};

int main()
{
    SingleLinkedList list;

    list.insertFront(1);
    list.insertFront(2);
    list.insertBack(4);
    list.insertBack(7);
    list.insert(9, 2);

    list.print();
    list.reversePrint();

    std::cout << list.findByValue(9) << std::endl;
    std::cout << list.getLenght() << std::endl;

    list.remove(3);
    list.print();

    list.removeBack();
    list.print();

    list.removeFront();
    list.print();

    list.removeByValue(4);
    list.print();

    std::cout << list[1] <<std::endl;

    SingleLinkedList list1(list);

    std::cout << (list1 == list) << std::endl;

    return 0;
}