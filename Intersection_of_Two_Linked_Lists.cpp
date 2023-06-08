/****************************************************************

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

*****************************************************************/

Node* findIntersection(Node *firstHead, Node *secondHead)
{
    //Write your code here
    Node*t1=firstHead;
    int len1=0;
    while(t1){
        len1++;
        t1=t1->next;
    }
    
    Node*t2=secondHead;
    int len2=0;
    while(t2){
        len2++;
        t2=t2->next;
    }
    
    t1 = firstHead;
    t2 = secondHead;
    
    while(len1!=0 and len2!=0){
        
        while (len1 > len2) {
            len1--;
            t1 = t1->next;
        } 
        while(len2 > len1) {
          t2 = t2->next;
          len2--;
        } 

        if(t1==t2){
            return t1;
        }

        len1--;
        len2--;
        t1 = t1->next;
        t2 = t2->next;
        
    }
    
    return NULL;
    
}
