#include <bits/stdc++.h>

/*************************************************************

    Following is the LinkedListNode class structure

    template <typename T>   
    class LinkedListNode
    {
        public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode<T> *random;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*************************************************************/

LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    // Write your code here.
    unordered_map<LinkedListNode<int> *,LinkedListNode<int> *>mpp;
    LinkedListNode<int> *cur=head;

    while(cur != NULL){

        mpp[cur] = new LinkedListNode<int>(cur->data);
        cur = cur->next;
    }

    cur=head;
    while(cur!=NULL){
        mpp[cur]->next = mpp[cur->next];
        mpp[cur]->random = mpp[cur->random];
        cur = cur->next; 
    }

    return mpp[head];
  
}

/**

1>. TC->O(n) SC->O(n) using unordered_map

2>. this probllem can also be solved with time Complexity = O(n) and space complexity = O(1)

*/
