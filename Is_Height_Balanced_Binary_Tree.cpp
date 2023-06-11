#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
int f(BinaryTreeNode<int>*root){
    if(root==NULL) return 0;

    int l=f(root->left);
    int r=f(root->right);
    if(l==-1 || r==-1) return -1;
    if(abs(l-r)>1) return -1;
    return max(l,r)+1;
}
bool isBalancedBT(BinaryTreeNode<int>* root) {
    // Write your code here.
    return f(root)!=-1;
}
