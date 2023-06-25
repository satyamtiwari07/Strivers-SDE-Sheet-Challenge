/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };
 */
Node*merge(Node*a,Node*b){
    
    if(a==NULL) return b;
    
    if(b==NULL) return a;
    
    Node*prev=new Node(-1);
    Node*temp=prev;
    
    while(a!=NULL && b!=NULL){
        
        if(a->data<=b->data){
            temp->child=a;
            // temp=a;
            a=a->child;
        }
        else{
            temp->child=b;
            // temp=b;
            b=b->child;
        }
        temp=temp->child;
    }
    
    if(a==NULL)
       temp->child=b;
    
    else if(b==NULL)
       temp->child=a;
    
    return prev->child;
}

Node* flattenLinkedList(Node* head) 
{
	// Write your code here
	if(head==NULL || head->next==NULL) return head;
	Node*temp=flattenLinkedList(head->next);
	Node*start=head;
	start->next=NULL;
	if(temp==NULL) return start;
	temp->next=NULL;
	if(start==NULL) return temp;
    
	
	Node*prev=new Node(-1);
	Node*p=prev;

	while(start!=NULL and temp!=NULL){
		if(start->data<=temp->data){
			p->child=start;
			start=start->child;
		}
		else{
			p->child=temp;
			temp=temp->child;
		}
		p=p->child;
	}

	if(start!=NULL) p->child=start;
	if(temp!=NULL)  p->child=temp;
	
	// prev->next=NULL;
	prev->child->next=NULL;
	
	return prev->child;

// 	if(head==NULL)
//        return NULL;
//    // Your code here
//     merge(head,flattenLinkedList(head->next));
// 	head->next=NULL;
//    return h
}
