[1mdiff --git a/Data Structures/LinkedList/CircularSingleLinkedList/CSLL.cpp b/Data Structures/LinkedList/CircularSingleLinkedList/CSLL.cpp[m
[1mindex 7a2f644..964ef4d 100644[m
[1m--- a/Data Structures/LinkedList/CircularSingleLinkedList/CSLL.cpp[m	
[1m+++ b/Data Structures/LinkedList/CircularSingleLinkedList/CSLL.cpp[m	
[36m@@ -118,7 +118,8 @@[m [mclass CSLL[m
             }[m
 [m
             curr->next = head->next;[m
[31m-            head = head->next;[m
[32m+[m[32m            delete head;[m
[32m+[m[32m            head = curr->next;[m
 [m
         }[m
 [m
[36m@@ -154,6 +155,9 @@[m [mclass CSLL[m
             }[m
 [m
             prev->next = curr->next;[m
[32m+[m
[32m+[m[32m            delete curr;[m
[32m+[m[32m            curr = nullptr;[m
         }[m
 [m
         bool removeBack()[m
[36m@@ -170,6 +174,9 @@[m [mclass CSLL[m
                 curr = curr->next;[m
             }[m
 [m
[32m+[m[32m            delete curr->next;[m
[32m+[m[32m            curr->next = nullptr;[m
[32m+[m
             curr->next = head;[m
         }[m
 [m
[36m@@ -239,6 +246,20 @@[m [mclass CSLL[m
             }[m
         }[m
 [m
[32m+[m[32m        ~CSLL()[m
[32m+[m[32m        {[m
[32m+[m[32m            Node* curr = head;[m
[32m+[m[32m            Node* prev = head;[m
[32m+[m
[32m+[m[32m            while(curr->next != head)[m
[32m+[m[32m            {[m
[32m+[m[32m                prev = curr;[m
[32m+[m[32m                curr = curr->next;[m
[32m+[m[32m                delete prev;[m
[32m+[m[32m                prev = nullptr;[m
[32m+[m[32m            }[m
[32m+[m[32m        }[m
[32m+[m
     private:[m
         Node* head = nullptr;[m
 [m
[1mdiff --git a/Data Structures/LinkedList/DoubleLinkedList/DoubleLinkedlist2/DoubleLinkedList.cpp b/Data Structures/LinkedList/DoubleLinkedList/DoubleLinkedlist2/DoubleLinkedList.cpp[m
[1mindex a0bea1b..fc49128 100644[m
[1m--- a/Data Structures/LinkedList/DoubleLinkedList/DoubleLinkedlist2/DoubleLinkedList.cpp[m	
[1m+++ b/Data Structures/LinkedList/DoubleLinkedList/DoubleLinkedlist2/DoubleLinkedList.cpp[m	
[36m@@ -192,11 +192,13 @@[m [mclass DoubleLikedList[m
 [m
             if (1 == getLength())[m
             {[m
[32m+[m[32m                delete head;[m
                 head = nullptr;[m
                 return true;[m
             }[m
 [m
             head = head->next;[m
[32m+[m[32m            delete head->prev;[m
             head->prev = nullptr;[m
             return true;[m
         }[m
[36m@@ -232,6 +234,8 @@[m [mclass DoubleLikedList[m
             [m
             curr->prev->next = curr->next;[m
             curr->next->prev = curr->prev;[m
[32m+[m[32m            delete curr;[m
[32m+[m[32m            curr = nullptr;[m
         }[m
 [m
         bool removeBack()[m
[36m@@ -248,6 +252,7 @@[m [mclass DoubleLikedList[m
                 curr = curr->next;[m
             }[m
 [m
[32m+[m[32m            delete curr->prev->next;[m
             curr->prev->next = nullptr;[m
         }[m
 [m
[36m@@ -366,6 +371,15 @@[m [mclass DoubleLikedList[m
             return size;[m
         }[m
 [m
[32m+[m[32m        ~DoubleLikedList()[m
[32m+[m[32m        {[m
[32m+[m[32m            while(head->next)[m
[32m+[m[32m            {[m
[32m+[m[32m                head = head->next;[m
[32m+[m[32m                delete head->prev;[m
[32m+[m[32m            }[m
[32m+[m[32m        }[m
[32m+[m
     private:[m
 [m
         Node* head = nullptr;[m
[1mdiff --git "a/Data Structures/Trees/Red\342\200\223black tree/RBT.cpp" "b/Data Structures/Trees/Red\342\200\223black tree/RBT.cpp"[m
[1mindex b317097..773debc 100644[m
[1m--- "a/Data Structures/Trees/Red\342\200\223black tree/RBT.cpp"[m	
[1m+++ "b/Data Structures/Trees/Red\342\200\223black tree/RBT.cpp"[m	
[36m@@ -32,6 +32,12 @@[m [mclass RBT[m
             return deleteNode(data, root);[m
         }[m
 [m
[32m+[m[32m        ~RBT()[m
[32m+[m[32m        {[m
[32m+[m[32m            destroy(root);[m
[32m+[m
[32m+[m[32m        }[m
[32m+[m
     private:[m
 [m
         void add(int data, Node* startNode)[m
[36m@@ -463,6 +469,16 @@[m [mclass RBT[m
             return nullptr;[m
         }[m
 [m
[32m+[m[32m        void destroy(Node* startNode)[m
[32m+[m[32m        {[m
[32m+[m[32m            if (startNode)[m
[32m+[m[32m            {[m
[32m+[m[32m                destroy(startNode->left);[m
[32m+[m[32m                destroy(startNode->right);[m
[32m+[m[32m                delete startNode;[m
[32m+[m[32m            }[m
[32m+[m[32m        }[m
[32m+[m
     private:[m
         Node* root = nullptr;[m
 };[m
[36m@@ -484,7 +500,7 @@[m [mint main()[m
     rbt.insert(1);[m
     rbt.insert(70);[m
 [m
[31m-    rbt.deleteNode(25);[m
[32m+[m[32m    //rbt.deleteNode(25);[m
 [m
     return 0;[m
 }[m
\ No newline at end of file[m
