#include <iostream>

class RBT
{
    class Node
    {
        public:

            Node(int data) : m_data{data}
            {}

            int m_data;
            Node* left = nullptr;
            Node* right = nullptr;
            Node* parent;

            // All newly created nodes must have red color, so I set up it 1 (red) by default.
            // false - black, ture - red
            bool color = true; 

    };

    public:
    
        void insert(int data)
        {
            return add(data, root);
        }

        bool deleteNode(int data)
        {
            return deleteNode(data, root);
        }

    private:

        void add(int data, Node* startNode)
        {
            if(!startNode)
            {
                // If tree is empty, create new node as root node with color black.
                root = new Node(data);
                // Root must be black always.
                root->color = false;   
            }
            // If tree is not empty, create new node as leaf node with color red.
            // New created nodes must be red always, by default I create red nodes.
            else if(startNode->m_data > data)
            {
                if (!startNode->left)
                {

                    startNode->left = new Node(data);
                    startNode->left->parent = startNode;

                    rebalance(startNode->left);
                }
                else
                {
                    add(data, startNode->left);
                }
                
            }
            else if(startNode->m_data < data)
            {
                if (!startNode->right)
                {
                    startNode->right = new Node(data);
                    startNode->right->parent = startNode;

                    rebalance(startNode->right);
                }
                else
                {
                    add(data, startNode->right);
                }
                
            }
        }

        void rebalance(Node* leaf)
        {
            Node* parent = leaf->parent;

            // If parent of new node is black than exit.
            if (false == parent->color) 
            {
                return;
            }

            // In this point we have red-red conflict.

            Node* grandParent = parent->parent;
            Node* uncle;
            
            if (grandParent)
            {
                if (grandParent->right == parent)
                {
                    uncle = grandParent->left;
                }
                else
                {
                    uncle = grandParent->right;
                }

            // If parent of new node is red, then 
            if (true == parent->color)   // In this point we know that it is true, we just check it in any case.
            {
                // check the color of parent`s sibling (or new created node uncle1s color) of new node.

                if (!uncle || false == uncle->color) 
                {
                    // if color is black or sibling is nullprt, then do suitable rotation and recolor.
                    
                    if (parent == grandParent->left && leaf == parent->left)
                    {
                        // Left left roation 
                        rightRotate(grandParent);

                        grandParent->color = !grandParent->color;
                        parent->color = !parent->color;
                    }

                    if (parent == grandParent->left && leaf == parent->right)
                    {
                        // Left right roation 
                        grandParent->left = leftRotate(grandParent->left);
                        rightRotate(grandParent);

                        grandParent->color = !grandParent->color;
                        leaf->color = !leaf->color;
                    }

                    if (parent == grandParent->right && leaf == parent->left)
                    {
                        // Right left roation 
                        grandParent->right = rightRotate(grandParent->right);
                        leftRotate(grandParent);

                        grandParent->color = !grandParent->color;
                        leaf->color = !leaf->color;

                    }

                    if (parent == grandParent->right && leaf == parent->right)
                    {
                        // Right right roation 
                        leftRotate(grandParent);

                        grandParent->color = !grandParent->color;
                        parent->color = !parent->color;
                    }
                }
                if(uncle && true == uncle->color)
                {
                    // if color is red then recolor
                    parent->color = !parent->color;
                    uncle->color = !uncle->color;

                    // and also check if parent`s parent of new node is not root node
                    if(grandParent != root)
                    {
                        //then recolor it
                        grandParent->color = !grandParent->color;

                        // And recheck.
                        rebalance(grandParent);
                    }
                }
                
                }
            }
        }

        Node* rightRotate(Node* y) 
        {
            Node* x = y->left;

            y->left = x->right;

            if(x->right)
            {
                x->right->parent = y;
            }

            x->parent = y->parent;

            if (!y->parent)
            {
                root = x;
            }
            else if( y == y->parent->right)
            {
                y->parent->right = x;
            }
            else
            {
                y->parent->left = x;
            }

            x->right = y;
            y->parent = x;

            return x;
        }

        Node* leftRotate(Node* x) 
        {
            Node* y = x->right;

            x->right = y->left;

            if(y->left)
            {
                y->left->parent = x;
            }

            y->parent = x->parent;

            if (!x ->parent)
            {
                root = y;
            }
            else if( x == x->parent->left)
            {
                x->parent->left = y;
            }
            else
            {
                 x->parent->right = y;
            }

            y->left = x;
            x->parent = y;

            return y;
        }

        bool deleteNode(int data, Node* startNode)
        {
            Node* temp = find(startNode, data);

            if (!temp)
            {
                return false;
            }

            if (true == temp->color)
            {
                if (!temp->left && !temp->right) 
                {
                    if (!temp->parent) 
                    {
                        root = temp = nullptr;

                        return true; 
                    }

                    if (temp->parent->m_data > data)
                    {
                        if (false == temp->color) // if we want to delete black node
                        {

                        }

                        temp->parent->left = nullptr;
                        return true;
                    }
                    if (temp->parent->m_data < data) 
                    {
                        if (false == temp->color) // if we want to delete black node
                        {

                        }
                         
                        temp->parent->right = nullptr;
                        return true;
                    } 
                }

                if (temp->left && !temp->right)
                {
                    if (temp->parent->left == temp)
                    {


                        temp->parent->left = temp->left; 
                        temp->left->parent = temp->parent;


                        return true;
                    }
                    else if (temp->parent->right == temp)
                    {
                        temp->parent->right = temp->left;
                        temp->right->parent = temp->parent;

                        return true;
                    }
                }

                if (!temp->left && temp->right)
                {
                    if (temp->parent->left == temp)
                    {
                        temp->parent->left = temp->right;
                        temp->left->parent = temp->parent;

                        return true;
                    }
                    else if (temp->parent->right == temp) 
                    {
                        temp->parent->right = temp->right;
                        temp->right->parent = temp->parent;

                        return true;
                    }
                }

                Node* maxElem = max(temp->left); // inorder predecessor

                temp->m_data = maxElem->m_data;

                if (maxElem->parent->left == maxElem)
                {
                    maxElem->parent->left = nullptr;
                    return true;
                }
                else if (maxElem->parent->right == maxElem)
                {
                    maxElem->parent->right = nullptr;
                    return true;
                }

                return false;
            }
        }

        Node* max(Node* startNode)
        {
            Node* leftSubtreeMax;

            if (!startNode->left)
            {
                leftSubtreeMax = startNode;
            }
            else
            {
                leftSubtreeMax = max( startNode->left );
            }

            Node* rightSubtreeMax;

            if (!startNode->right)
            {
                rightSubtreeMax = startNode;
            }
            else
            {
                rightSubtreeMax = max( startNode->right );
            }

            if (leftSubtreeMax->m_data > rightSubtreeMax->m_data)
            {
                return leftSubtreeMax;
            }
            else
            {
                return rightSubtreeMax;
            }
        }

        Node* find(Node* startNode, int data)
        {
            if (startNode == nullptr)
            {
                return nullptr;
            }

            if (startNode->m_data == data)
            {
                return startNode;
            }
            else if (startNode->m_data > data)
            {
                return find(startNode->left, data);
            }
            else if (startNode->m_data < data)
            {
                return find(startNode->right, data);
            }

            return nullptr;
        }

    private:
        Node* root = nullptr;
};

int main()
{
    RBT rbt;

    rbt.insert(10);
    rbt.insert(18);
    rbt.insert(7);
    rbt.insert(15);
    rbt.insert(16);
    rbt.insert(30);
    rbt.insert(25);
    rbt.insert(40);
    rbt.insert(60);
    rbt.insert(2);
    rbt.insert(1);
    rbt.insert(70);
    

    return 0;
}