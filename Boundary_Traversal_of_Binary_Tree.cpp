#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:
    
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
void left(TreeNode<int>* root,vector<int>&ans){
    if(root==NULL) return ;
    if(root->left){
        ans.push_back(root->data);
        left(root->left,ans);
    }
    else if(root->right){
        ans.push_back(root->data);
        left(root->right,ans);
    }
}

void right(TreeNode<int>* root,vector<int>&ans){
    if(root==NULL) return ;
    if(root->left==NULL and root->right==NULL) return ;
    if(root->right){
        ans.push_back(root->data);
        right(root->right,ans);
    }
    else if(root->left){
        ans.push_back(root->data);
        right(root->left,ans);
    }
}

void leaf(TreeNode<int>* root,vector<int>&ans){
    if(root==NULL) return ;
    if(root->left==NULL and root->right==NULL) {
        ans.push_back(root->data);
    }
    leaf(root->left,ans);
    leaf(root->right,ans);
}

vector<int> traverseBoundary(TreeNode<int>* root){
    // Write your code here.
    vector<int>ans;
    if(root==NULL) return ans;
    if(root->left==NULL and root->right==NULL) return {root->data};
    ans.push_back(root->data);

    left(root->left, ans);

    leaf(root,ans);

    int idx=ans.size();

    right(root->right,ans);

    reverse(ans.begin()+idx,ans.end());
    
    return ans;
}
