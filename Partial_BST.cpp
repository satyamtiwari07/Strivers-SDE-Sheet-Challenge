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
bool f(BinaryTreeNode<int> *root,int l,int r){
    if(root==NULL) return true;

    if(root->data < l or root->data> r) return false;

    if(!f(root->left,l,root->data) || !f(root->right,root->data,r)) return false;
    return true;
}
bool validateBST(BinaryTreeNode<int> *root) {
    // Write your code here
    return f(root,INT_MIN,INT_MAX);
}
