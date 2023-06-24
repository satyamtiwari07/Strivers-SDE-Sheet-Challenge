#include <bits/stdc++.h> 
/************************************************************

Following is the Binary Tree node class
    
template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

************************************************************/

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    //    Write your code here.
    map<int,vector<int>>mpp;
    if(root==NULL) return {};
    queue<pair<TreeNode<int> *,int>>q;
    q.push({root,0});

    while(!q.empty()){
        auto it=q.front();
        q.pop();
        auto node=it.first;
        int idx=it.second;
        mpp[idx].push_back(node->data);
        if(node->left) q.push({node->left,idx-1});
        if(node->right) q.push({node->right,idx+1});
    }
    vector<int>ans;
    for(auto it:mpp){
        for(auto i:it.second) ans.push_back(i);
    }
    return ans;
}
