#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

TreeNode<int> *f(vector<int> &inorder, vector<int> &preorder,int &idx,int l,int r){
    if(l>r) return NULL;
    int x=0;
    for(x=l; x<=r; x++){
        if(inorder[x]==preorder[idx]) break;
    }

    TreeNode<int>*root=new TreeNode<int>(preorder[idx]);
    idx++;
    root->left = f(inorder,preorder,idx,l,x-1);
    root->right = f(inorder,preorder,idx,x+1,r);

    return root;
}

TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
	//    Write your code here
    int n=inorder.size();
    int idx=0;
    return f(inorder,preorder,idx,0,n-1);
}
