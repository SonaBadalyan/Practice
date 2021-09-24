#include<iostream>

class DoubleLikedList
{
    class Node 
    {
        public:

            Node (int data)
            {
                this->data = data;
            }

            int data;
            Node* prev = nullptr;
            Node* next = nullptr;
    };

    public:

        DoubleLikedList()
        {
            head = nullptr;
        }

        DoubleLikedList(const DoubleLikedList& rhs)
        {
            if (this == &rhs || rhs.isEmpty())
            {
                return;
            }

            Node* rhsCurr = rhs.head;

            while(rhsCurr)
            {
                insertBack(rhsCurr->data);
                rhsCurr = rhsCurr -> next;
            }
        }

        DoubleLikedList& operator=(const DoubleLikedList& rhs)
        {
            if (this == &rhs || rhs.isEmpty())
            {
                return *this;
            }

            Node* rhsCurr = rhs.head;

            while(rhsCurr)
            {
                insertBack(rhsCurr->data);
                rhsCurr = rhsCurr -> next;
            }

            return *this;
        }

        bool operator==(const DoubleLikedList& rhs)
        { 
            if ( this == &rhs)
            {
                return true;
            }

            if (rhs.getLength() != getLength())
            {
                return false;
            }

            Node* curr = head;
            Node* rhsCurr = rhs.head;

            while (curr && rhsCurr)
            {
                if (curr->data != rhsCurr->data)
                {
                    return false;
                }

                curr = curr->next;
                rhsCurr = rhsCurr->next;
            }

            return true;
        }

        int operator[](int index)
        {
            if (0 >= index || index > getLength() || 0 == getLength())
            {
                return -1;
            }

            Node* curr = head;

            while(curr && --index)
            {
                curr = curr ->next;
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
            head->prev = newNode;

            head = newNode;

        }

        void insert(int data, int index)
        {
            if (0 >= index || index > getLength() + 1)
            {
                return;
            }

            if (isEmpty())
            {
                head = new Node(data);
                return;
            }

            if( 1 == index)
            {
                insertFront(data);
                return;
            }

            if (index + 1 == getLength())
            {
                insertBack(data);
                return;
            }

            Node* curr = head;

            while(curr && --index)
            {
                curr = curr->next;
            }

            Node* newNode = new Node(data);

            curr->next->prev = newNode;
            newNode->next = curr->next;

            curr->next = newNode;
            newNode->prev = curr;

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
                curr = curr -> next;
            }

            Node* newNode = new Node(data);

            curr->next = newNode;
            newNode->prev = curr;

        }

        bool removeFront()
        {
            if (isEmpty())
            {
                return false;
            }

            if (1 == getLength())
            {
                delete head;
                head = nullptr;
                return true;
            }

            head = head->next;
            delete head->prev;
            head->prev = nullptr;
            return true;
        }

        bool remove(int index)
        {
            if (0 >= index || index > getLength())
            {
                return false;
            }

            if (isEmpty())
            {
                return false;
            }

            if ( 1 == index )
            {
                return removeFront();
            }

            if (index == getLength())
            {
                return removeBack();
            }

            Node* curr = head;

            while(curr && --index)
            {
                curr = curr->next;
            }
            
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            delete curr;
            curr = nullptr;
        }

        bool removeBack()
        {
            if (isEmpty())
            {
                return false;
            }

            Node* curr = head;

            while(curr->next)
            {
                curr = curr->next;
            }

            delete curr->prev->next;
            curr->prev->next = nullptr;
        }

        bool removeByValue(int data)
        {
            if (isEmpty())
            {
                return false;
            }

            if (1 == getLength())
            {
                head = nullptr;
                return true;
            }

            Node* curr = head;

            int index = 1;
            while(curr)
            {
                if (curr->data == data)
                {
                    return remove(index);
                }

                curr = curr->next;
                ++index;
            }
            return false;
        }

        bool isEmpty() const
        {
            if (!head)
            {
                return true;
            }
            return false;
        }

        void print()
        {
            std::cout << "__________Print double linked list__________" << std::endl;

            if (isEmpty())
            {
                std::cout << " Double linked list is empty! Nothing to print." << std::endl;
                return;
            }

            Node* curr = head;
            while(curr)
            {
                std::cout << curr->data << "   ";
                curr =  curr->next;
            }
            std::cout << std::endl;

        }

        void reverse()
        {
            if (isEmpty())
            {
                return;
            }
            
            Node* curr = head;
            Node* next;

            while(curr)
            {
                head = curr;
                next = curr->next;
                curr->next = curr->prev;
                curr->prev = next;
                curr = next;
            }
        }

        bool find(int data)
        {
            if (isEmpty())
            {
                return false;
            }

            Node* curr = head;

            while(curr)
            {
                if (curr->data == data)
                {
                    return true;
                }
                
                curr = curr->next;
            }

            return false;
        }

        int getLength() const
        {
            int size = 0;

            Node* curr = head;

            while(curr)
            {
                ++size;
                curr = curr -> next;
            }

            return size;
        }

        ~DoubleLikedList()
        {
            while(head->next)
            {
                head = head->next;
                delete head->prev;
            }
        }

    private:

        Node* head = nullptr;
};

int main()
{
    DoubleLikedList list;

    list.insert(3, 1);
    list.print();

    list.insertFront(2);
    list.print();

    list.insertFront(3);
    list.print();

    list.insertBack(2);
    list.print();

    if (list.find(2))
    {
        std::cout << "found" <<std::endl;
    }

    list.insert(5, 7);
    list.print();

    std::cout << list[1] << std::endl;

    DoubleLikedList list2 = list;
    DoubleLikedList list3(list2);

    list2.print();
    list3.print();

    if(list2 == list3)
    {
        std::cout << "Equal " << std::endl;
    }

    list.insertFront(1);

    list.reverse();
    list.print();

    list.removeBack();
    list.print();

    list.removeByValue(2);
    list.print();

    list.removeFront();
    list.print();

    list.remove(1);
    list.print();


    return 0;
}