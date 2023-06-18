#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int getMaxWidth(TreeNode<int> *root)
{
    // Write your code here.
    if(root==NULL) return 0;
    queue<TreeNode<int>*>q;
    q.push(root);
    int ans=0;
    while(!q.empty()){
        int sz=q.size();
        ans=max(ans,sz);
        while(sz--){
          auto it = q.front(); 
          q.pop();
          if (it->left) q.push(it->left);

          if (it->right) q.push(it->right);
        }
    }
    return ans;
}
