#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:

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


************************************************************/

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    // Write your code here.
    if(root==NULL)
      return {};
    vector<int>preorder;
    vector<int>inorder;
    vector<int>postorder;

    stack<pair<BinaryTreeNode<int> *,int>>st;
    st.push({root,1});

    while(!st.empty()){
        if(st.top().second==1){
            BinaryTreeNode<int> *temp=st.top().first;
            preorder.push_back(temp->data);
            st.top().second+=1;
            if(temp->left){
              st.push({temp->left,1});
            }
        }
        else if(st.top().second==2){
            
            BinaryTreeNode<int> *temp=st.top().first;
            inorder.push_back(temp->data);
            st.top().second+=1;
            if(temp->right){
              st.push({temp->right, 1});
            }
        } 
        else {
          postorder.push_back(st.top().first->data);
          st.pop();
        }
    }
    vector<vector<int>>ans;
    ans.push_back(inorder);
    ans.push_back(preorder);
    ans.push_back(postorder);
    return ans;
    
}
