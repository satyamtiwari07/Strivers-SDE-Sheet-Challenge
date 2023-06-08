#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

void deleteNode(LinkedListNode<int> * node) {
    // Write your code here.
    // 1 2 3 4 5
    if(node->next)
        node->data = node->next->data;
        
    LinkedListNode<int> *temp=NULL;
    if(node->next)
      temp =  node->next->next;
    
    node->next = temp;
    
}
