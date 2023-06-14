#include <bits/stdc++.h> 
/**********************************************************

    Following is the Binary Tree Node structure:

    template <typename T>
    class BinaryTreeNode {
        public: 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };
***********************************************************/
unordered_set<int>s;
bool f(BinaryTreeNode<int> *root, int k){
    if(root==NULL) return false;
    int rem = k-root->data;
    if(s.count(rem)) return true;
    s.insert(root->data);
    return f(root->left,k) || f(root->right,k);
}
bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    // Write your code here
    s.clear();
    return f(root,k);

}
