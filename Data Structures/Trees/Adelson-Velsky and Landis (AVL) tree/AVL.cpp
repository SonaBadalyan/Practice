#include <iostream>
#include <vector>

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

        bool deleteNode(int val)
        {
            return deleteNode(val, root);
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

            if ( balanceFactor > 1) 
            {    
                bool isLR;

                std::vector<Node*> path = findLongestPath(criticalNode);

                int size = path.size();

                if (path[size - 2] == criticalNode->left &&
                    path[size - 3] == criticalNode->left->right)
                {
                    isLR = true;
                }


                if (path[size - 2] == criticalNode->left && 
                    path[size - 3] == criticalNode->left->left)
                {
                    isLR = false;
                }

                if (!isLR)  
                {       
                    rightRotate(criticalNode);
                    return;
                }
                else
                {
                    criticalNode->left = leftRotate(criticalNode->left);
                    rightRotate(criticalNode);
                    return;
                }
            }

            if ( balanceFactor < -1) 
            {
                bool isRL;

                std::vector<Node*> path = findLongestPath(criticalNode);

                int size = path.size();

                if (path[size - 2] == criticalNode->right &&
                    path[size - 3] == criticalNode->right->left)
                {
                    isRL = true;
                }


                if (path[size - 2] == criticalNode->right &&
                    path[size - 3] == criticalNode->right->right)
                {
                    isRL = false;
                }

                if (!isRL)
                {
                    leftRotate(criticalNode);
                    return;
                }
                else
                {
                    criticalNode->right = rightRotate(criticalNode->right);
                    leftRotate(criticalNode);
                    return;
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

        std::vector<Node*> findLongestPath(Node* startNode)
        {
            std::vector<Node*> longestPath;
            longestPath.clear();

            std::vector<Node*> leftPath;
            leftPath.clear();

            std::vector<Node*> rightPath;
            rightPath.clear();

            if(!startNode)
            {
                return longestPath;
            }

            if(startNode->left)
            {
                leftPath.push_back(startNode->left);
                leftPath = findLongestPath(startNode->left);
            }
            if(startNode->right)
            {
                rightPath.push_back(startNode->right);
                rightPath = findLongestPath(startNode->right); 
            }

            if (leftPath.size() > rightPath.size())
            {
                leftPath.push_back(startNode);
                return leftPath;
            }
            else
            {
                rightPath.push_back(startNode);
                return rightPath;
            }
        }

        bool deleteNode(int val, Node* startNode)
        {
            Node* temp = find(startNode, val);

            if (!temp)
            {
                return false;
            }

            if (!temp->left && !temp->right) 
            {
                if (!temp->parent)
                {
                    root = temp = nullptr;
                    return true; 
                }

                if (temp->parent->data > val)
                {
                    temp->parent->left = nullptr;
                    checkBalance(temp->parent);
                    return true;
                }
                if (temp->parent->data < val)
                {
                    temp->parent->right = nullptr;
                    checkBalance(temp->parent);
                    return true;
                } 
            }

            if (temp->left && !temp->right) 
            {
                if (temp->parent->left == temp)
                {
                    temp->parent->left = temp->left; 
                    temp->left->parent = temp->parent;
                    checkBalance(temp->parent);
                    return true;
                }
                else if (temp->parent->right == temp)
                {
                    temp->parent->right = temp->left;
                    temp->left->parent = temp->parent;
                    checkBalance(temp->parent);
                    return true;
                }
            }

            if (!temp->left && temp->right)
            {
                if (temp->parent->left == temp)
                {
                    temp->parent->left = temp->right;
                    temp->right->parent = temp->parent;
                    checkBalance(temp->parent);
                    return true;
                }
                else if (temp->parent->right == temp)
                {
                    temp->parent->right = temp->right;
                    temp->right->parent = temp->parent;
                    checkBalance(temp->parent);
                    return true;
                }
            }

            Node* maxElem = max(temp->left);

            temp->data = maxElem->data;

            if (maxElem->parent->left == maxElem)
            {
                maxElem->parent->left = nullptr;
                checkBalance(maxElem->parent);
                return true;
            }
            else if (maxElem->parent->right == maxElem)
            {
                maxElem->parent->right = nullptr;
                checkBalance(maxElem->parent);
                return true;
            }

            return false;
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

            if (leftSubtreeMax->data > rightSubtreeMax->data)
            {
                return leftSubtreeMax;
            }
            else
            {
                return rightSubtreeMax;
            }
        }

        Node* find(Node* temp, int val)
        {
            if (temp == nullptr)
            {
                return nullptr;
            }

            if (temp->data == val)
            {
                return temp;
            }
            else if (temp->data > val)
            {
                return find(temp->left, val);
            }
            else if (temp->data < val)
            {
                return find(temp->right, val);
            }

            return nullptr;
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

    tree.deleteNode(8);
    tree.deleteNode(7);
    tree.deleteNode(11);
    tree.deleteNode(14);
    tree.deleteNode(17);

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