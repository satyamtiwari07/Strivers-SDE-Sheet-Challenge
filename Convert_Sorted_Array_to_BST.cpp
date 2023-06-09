#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;
        
        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
TreeNode<int>* f(vector<int>&arr,int l,int h){
    if(l>h) return NULL;
    int mid=(l+h)/2;
    TreeNode<int>* node=new TreeNode<int>(arr[mid]);
    node->left = f(arr,l,mid-1);
    node->right = f(arr,mid+1,h);
    return node;
}
TreeNode<int>* sortedArrToBST(vector<int> &arr, int n)
{
    // Write your code here.
    return f(arr,0,n-1);
}
