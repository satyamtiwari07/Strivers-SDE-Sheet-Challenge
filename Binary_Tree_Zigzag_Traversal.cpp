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

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    // Write your code here!
    vector<int>ans;
    if(root==NULL) return ans;

    queue<BinaryTreeNode<int> *>q;
    q.push(root);
    
    //if flag is 1 reverse
    int flag=0;

    while(!q.empty()){
        int sz=q.size();
        vector<int>temp;
        while(sz--){
            auto root=q.front();
            q.pop();
            temp.push_back(root->data);
            if(root->left) q.push(root->left);
            if(root->right) q.push(root->right);
        }
        if(flag) reverse(temp.begin(),temp.end());
        for(auto it:temp) ans.push_back(it);
        flag=1-flag;
    }
    return ans;
}
