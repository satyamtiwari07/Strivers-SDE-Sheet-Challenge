#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

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

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/

pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    // Write your code here.
    BinaryTreeNode<int>* temp=root;
    pair<int,int>ans;
    if(root==NULL) return ans;
    int val=-1;
    while(temp){
        if(temp->data>=key){
            temp=temp->left;
        }
        else{
            val=temp->data;
            temp=temp->right;
        }
    }

    ans.first=val;
    val=-1;
    temp=root;
    
    while(temp){
        if(temp->data>key){
            val=temp->data;
            temp=temp->left;
        }
        else{
            temp=temp->right;
        }
    }
    ans.second=val;
    return ans;


}
