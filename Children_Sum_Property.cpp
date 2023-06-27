#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode < T > *left;
        BinaryTreeNode < T > *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
void f(BinaryTreeNode<int>* root){
    if(root==NULL) return ;

    int sum=0;
    if(root->left)  sum+=root->left->data;
    if(root->right) sum+=root->right->data;

    if(root->data<sum) root->data=sum;
    else{
         if(root->left) root->left->data = root->data;
         if(root->right) root->right->data = root->data;
    }
 
    f(root->left);
    f(root->right);

    if(root->left && root->right) root->data = root->left->data+root->right->data;
    else if(root->left) root->data = root->left->data;
    else if(root->right) root->data = root->right->data; 

}
void changeTree(BinaryTreeNode < int > * root) {
    // Write your code here.
    f(root);
    // return root;
}  
