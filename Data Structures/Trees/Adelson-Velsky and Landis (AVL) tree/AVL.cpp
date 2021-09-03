#include <iostream>

class AVL
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

                Node* left = nullptr;
                Node* right = nullptr;
                Node* parent = nullptr;
        };

        void insert(int val)
        {
            return add(val, root);
        }

        bool isBalanced()
        {
            auto result = isBalanced(root);
            
            if(result.second)
            {
                bool isUnbalanced = result.first < -1 || result.first > 1;

                if (isUnbalanced)
                {
                    return false;
                }
            }

            return true;
        }

    private:

        void add(int val, Node* temp)
        {
            if(temp == nullptr)
            {
                root = new Node(val);
            }
            else if(temp->data > val)
            {
                if (temp->left == nullptr)
                {
                    temp->left = new Node(val);
                    temp->left->parent = temp;

                    checkBalance(temp->left);
                }
                else
                {
                    add(val, temp->left);
                }
                
            }
            else if(temp->data < val)
            {
                if (temp->right == nullptr)
                {
                    temp->right = new Node(val);
                    temp->right->parent = temp;
                    
                    checkBalance(temp->right);
                }   
                else
                {
                    add(val, temp->right);
                }
                
            }
        }

        void checkBalance(Node* leaf)
        {
            auto const& result = findCriticalNode(leaf);

            int banalceFactor = result.first;
            Node* criticalNode = result.second;

            while (criticalNode && (banalceFactor <-1 || banalceFactor > 1))
            {
                balance(std::make_pair(banalceFactor, criticalNode));
                auto const& result = findCriticalNode(leaf);

                banalceFactor = result.first;
                criticalNode = result.second;
            }
        }

        std::pair<int, Node*> findCriticalNode(Node* temp)
        {
            std::pair<int, Node*> result;

            while (temp != root)
            {
                result = isBalanced(temp);

                if ((result.first < -1 || result.first > 1) && result.second)
                {
                    return result;
                }

                temp = temp->parent;
            }

            return std::make_pair(0, nullptr);
        }

        std::pair<int, Node*> isBalanced(Node* startNode)
        {
            if (!startNode)
            {
                return std::make_pair(0, nullptr);
            }

            int leftHeight;

            if (!startNode->left)
            {
                leftHeight = 0;
            }
            else
            {
                leftHeight = height(startNode->left);
            }

            int rightHeight;
            
            if (!startNode->right)
            {
                rightHeight = 0;
            }
            else
            {
                rightHeight = height(startNode->right);
            }

            int balanceFactor = leftHeight - rightHeight;
            bool isUnbalanced = balanceFactor < -1 || balanceFactor > 1;

            if (isUnbalanced)
            {
                return std::make_pair(balanceFactor, startNode);
            }
            else
            {
                auto result = isBalanced(startNode->left);
                int leftSubtreeBalanceFactor = result.first;
                bool isLeftUnbalanced = leftSubtreeBalanceFactor <-1 || leftSubtreeBalanceFactor > 1;

                if (isLeftUnbalanced)
                {
                    return std::make_pair(leftSubtreeBalanceFactor, result.second);
                }
                else
                {
                    auto result = isBalanced(startNode->right);
                    int rightSubtreeBalanceFactor = result.first;
                    bool isRightUnbalanced = rightSubtreeBalanceFactor < -1 || rightSubtreeBalanceFactor > 1;

                    if(isRightUnbalanced)
                    {
                        return std::make_pair(rightSubtreeBalanceFactor, result.second);
                    }
                }  
            }

            return std::make_pair(balanceFactor, startNode);
        }

        int height(Node* startNode)
        {
            if (!startNode)
            {
                return 0;
            }

            int leftHight;

            if (!startNode->left)
            {
                leftHight = 0;
            }
            else
            {
                leftHight = height(startNode->left);
            }

            int rightHight;

            if (!startNode->right)
            {
                rightHight = 0;
            }
            else
            {
                rightHight = height(startNode->right);
            }

            int max = leftHight > rightHight ? leftHight : rightHight;
            
            return ++max;
        }

        void balance(std::pair<int, Node*> pair)
        {
            int balanceFactor = pair.first;
            Node* criticalNode = pair.second;

            if ( balanceFactor > 1 && criticalNode->data > criticalNode->left->data) 
            {
                rightRotate(criticalNode);
                return;
            }

            if ( balanceFactor > 1 && criticalNode->data < criticalNode->left->data) 
            {
                criticalNode->left = leftRotate(criticalNode->left);
                rightRotate(criticalNode);
                return;
            }

            if ( balanceFactor < -1 && criticalNode->data > criticalNode->right->data) 
            {
                leftRotate(criticalNode);
                return;
            }

            if ( balanceFactor < -1 && criticalNode->data < criticalNode->right->data) 
            {
                criticalNode->right = rightRotate(criticalNode->right);
                leftRotate(criticalNode);
                return;
            }
        }

        Node* rightRotate(Node* maximum) 
        {
            Node* mid = maximum->left;

            maximum->parent->left = mid;
            mid->parent = maximum->parent;

            mid->right = maximum;
            maximum->parent = mid;

            maximum->right = nullptr;
            maximum->left = nullptr;

            return mid;
        }

        Node* leftRotate(Node* minimum) 
        {
            Node* mid = minimum->right;

            minimum->parent->right = mid;
            mid->parent = minimum->parent;

            mid->left = minimum;
            minimum->parent = mid;

            minimum->right = nullptr;
            minimum->left = nullptr;

            return mid;
        }

    private:

        Node* root = nullptr;
};

int main()
{
    AVL tree;

    tree.insert(14);
    tree.insert(17);
    tree.insert(11);
    tree.insert(7);
    tree.insert(53);

    if(tree.isBalanced())
    {
        std::cout << "Tree is balanced!" << std::endl;
    }
    else
    {
        std::cout << "Tree is not balanced!" << std::endl;
    }


    tree.insert(4);

    
    tree.insert(13);
    tree.insert(12);
    tree.insert(8);
    tree.insert(60);
    tree.insert(19);
    tree.insert(16);
    tree.insert(20);

    if(tree.isBalanced())
    {
        std::cout << "Tree is balanced!" << std::endl;
    }
    else
    {
        std::cout << "Tree is not balanced!" << std::endl;
    }

    return 0;

}