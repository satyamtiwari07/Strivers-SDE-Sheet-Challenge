/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node* removeKthNode(Node* head, int k)
{
    // Write your code here.
    int len=0;
    Node*temp=head;
    while(temp){
        len++;
        temp=temp->next;
    }
    //1 2 3 4 5 6 7 k=2 -->7-2=5
    
    int pos=len-k+1;
    int cnt=0;
    temp=head;
    if(pos==1){
        return head->next;
    }
    Node*prev=NULL;
    while(temp){
        cnt++;
        // prev=temp;
        if(cnt==pos){
            //delete karna hai node
            prev->next=temp->next;
            break;
        }
         prev=temp;
        temp=temp->next;

    }
    return head;

}
