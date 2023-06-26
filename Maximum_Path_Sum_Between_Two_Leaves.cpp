#include <bits/stdc++.h> 
/************************************************************

    Following is the Tree node structure
	
	template <typename T>
    class TreeNode 
    {
        public : 
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) 
        {
            this -> val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
long long int ans=-1; 

long long int f(TreeNode<int> *root){

    if(root==NULL) return 0;

    long long int l=f(root->left);
    long long int r=f(root->right);
   
    ans = max(ans, max({l,r,l + r + root->val}));
    return root->val + max(l, r);
}
long long int findMaxSumPath(TreeNode<int> *root)
{
    // Write your code here.
    ans=-1;
    if(root==NULL || root->right==NULL || root->left==NULL) return ans;
    f(root);
    return ans;
}
