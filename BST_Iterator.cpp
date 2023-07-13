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

class BSTiterator
{
    stack<TreeNode<int>*>st;
    public:
    BSTiterator(TreeNode<int> *root)
    {
        // write your code here
        st.push(root);
        while(root->left){
            st.push(root->left);
            root=root->left;
        }
    }

    int next()
    {
        // write your code here
        TreeNode<int>* node = st.top();
        int data = node->data;
        st.pop();
        if(node->right){
            st.push(node->right);
            TreeNode<int>* curNode = st.top();
            while(curNode->left){
                st.push(curNode->left);
                curNode=curNode->left;
            }
            
        }
        return data;
        
    }

    bool hasNext()
    {
        // write your code here
        return st.size();
    }
};


/*
    Your BSTIterator object will be instantiated and called as such:
    BSTIterator iterator(root);
    while(iterator.hasNext())
    {
       print(iterator.next());
    }
*/
