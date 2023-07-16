#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
class info{
 
 public:

    int maxi;
    int mini;
    int count;
 
    info(){
        maxi = INT_MIN;
        mini = INT_MAX;
        count = 0;
    }

    info(int mini, int maxi, int count){
        this->mini = mini;
        this->maxi = maxi;
        this->count = count;
    }

};

info f(TreeNode<int>* root){
    if(root==NULL){
        info f ;
        return f;
    }

    info left = f(root->left);
    info right = f(root->right);

    if(left.maxi<root->data and root->data<right.mini){

        info f(min(left.mini,root->data),max(right.maxi,root->data),left.count+right.count+1);
        return f;
    }

    info f(INT_MIN,INT_MAX,max(left.count,right.count));
    return f;
}
int largestBST(TreeNode<int>* root) 
{
    // Write your code here.
    return f(root).count;
}
