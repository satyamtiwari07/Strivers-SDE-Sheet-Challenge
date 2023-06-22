/************************************************************
   
   Following is the TreeNode class structure
   
   class TreeNode<T>
   { 
   public:
        T data; 
        TreeNode<T> *left;
        TreeNode<T> *right;
   
        TreeNode(T data) 
  		{ 
            this -> data = data; 
            left = NULL; 
            right = NULL; 
        }
   };
   
   
 ************************************************************/
TreeNode<int>*f(vector<int>& postOrder, vector<int>& inOrder, int &idx, int l, int r){
     if(l>r) return NULL;
     
     int x=0;
     for(x=l;x<=r;x++){
          if(inOrder[x]==postOrder[idx])break;
     }

     TreeNode<int>*root=new TreeNode<int>(postOrder[idx]);
     idx--;

     root->right = f(postOrder,inOrder,idx,x+1,r);
     root->left = f(postOrder,inOrder,idx,l,x-1);
     
     return root;

}
TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder) 
{
	// Write your code here.
     int n=postOrder.size();
     int idx = n-1;
     return f(postOrder,inOrder,idx,0,n-1);
}
