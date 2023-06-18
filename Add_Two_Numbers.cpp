/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next) {
 *          this->data = data;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

Node *addTwoNumbers(Node *num1, Node *num2)
{
    // Write your code here.
    if(num1==NULL) return num2;
    if(num2==NULL) return num1;

    int rem=0;
    Node*temp=new Node(-1);
    Node*t=temp;

    while(num1!=NULL and num2!=NULL){
        int a = num1->data + num2->data + rem;
        t->next=new Node(a%10);
        rem=a/10;
        num1=num1->next;
        num2=num2->next;
        t=t->next;
    }

    while(num1!=NULL){
        int a=rem+num1->data;
        t->next=new Node(a%10);
        rem=a/10;
        num1=num1->next;
        t=t->next;
    }
    while(num2!=NULL){
        int a=rem+num2->data;
        t->next=new Node(a%10);
        rem=a/10;
        num2=num2->next;
        t=t->next;
    }
    if(rem) t->next=new Node(rem);
    return temp->next;
}
