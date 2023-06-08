/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

Node *rotate(Node *head, int k) {
     // Write your code here.
     Node*t=head;
     int cnt=1;
     while(t->next!=NULL){
          cnt++;
          t=t->next;
     }

     t->next=head;
     k=cnt-(k%cnt);
     t=head;
     Node*prev=head;
     // if(k==0) return 
     while(t){
       if (k == 0) {
         prev->next = NULL;
         break;
       }
       prev=t;
       t=t->next;
       k--;
     }
     return t;

}
