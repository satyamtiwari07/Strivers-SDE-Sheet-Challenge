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

LinkedListNode<int>*reverse(LinkedListNode<int>*head){
LinkedListNode<int>*cur=head;
LinkedListNode<int>*prev=NULL;
LinkedListNode<int>*next;

while(cur!=NULL){
    next=cur->next;
    cur->next=prev;
    prev=cur;
    cur=next;
}
return prev;

}


bool isPalindrome(LinkedListNode<int> *head) {
    // Write your code here.
    
    LinkedListNode<int>*slow=head;
    LinkedListNode<int>*fast=head;
    while(fast and fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }

    LinkedListNode<int>*ed = reverse(slow);
    LinkedListNode<int>*st=head;

    while(st and ed){
        if(st->data!=ed->data) return false;
        st=st->next;
        ed=ed->next;
    }
    return true;
}
