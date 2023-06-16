#include <bits/stdc++.h>

/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    // Write your code here.
    if(first==NULL) return second;
    if(second==NULL) return first;

    Node<int>*t1 = first;
    Node<int>*t2 = second;
    Node<int>*temp;
    
    while(t1!=NULL and t2!=NULL){
        if(t1->data<=t2->data){
          while (t1!=NULL and t1->data <= t2->data) {
            temp = t1;
            t1 = t1->next;
          }
          temp->next=t2;
        }
        else{
          while (t2!=NULL and t2->data < t1->data) {
            temp = t2;
            t2 = t2->next;
          }
          temp->next=t1;
        }
    }

    if(t1!=NULL) temp->next=t1;
    else if(t2!=NULL) temp->next=t2;
    
    if(first->data<=second->data) return first;
    return second;
}
