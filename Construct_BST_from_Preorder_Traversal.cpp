#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class TreeNode{
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        ~TreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };

*************************************************************/
TreeNode<int>* f(int &idx, int ub, vector<int> &preOrder){

    if(idx>=preOrder.size() || preOrder[idx]>ub) return NULL;
    
    TreeNode<int>*root=new TreeNode<int>(preOrder[idx]);
    idx++;
    root->left = f(idx,root->data,preOrder);
    root->right = f(idx,ub,preOrder);
    
    return root;

}
TreeNode<int>* preOrderTree(vector<int> &preOrder){
    // Write your code here.
    
    int idx=0;
    
    return f(idx,INT_MAX,preOrder);

}
