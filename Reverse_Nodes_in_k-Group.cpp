#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/
pair<Node*,Node*> reverse(Node*head,int k){
	Node*prev=NULL;
	Node*cur=head;
	Node*next=NULL;
	int count=0;
        while (cur != NULL and count < k) {
          next = cur->next;
          cur->next = prev;
          prev = cur;
          cur = next;
          count++;
        }
        return { prev, cur };
}
Node *getListAfterReverseOperation(Node *head, int n, int b[]){
	// Write your code here.
	Node*t=new Node(-1);
	t->next=head;
	head=t;
	Node*prev=t;

	for(int x=0;x<n and t and t->next;x++){
		if(b[x]==0) continue;
		Node*nxt=t->next;
		//{prev,cur}
		pair<Node*,Node*>temp = reverse(t->next,b[x]);
		t->next=temp.first;
		nxt->next=temp.second;
		t=nxt;

	}
	return head->next;

}
