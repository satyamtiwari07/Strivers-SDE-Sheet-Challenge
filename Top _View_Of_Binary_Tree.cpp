#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

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

vector<int> getTopView(TreeNode<int> *root) {
    if(root==NULL)
      return {};
    // Write your code here.
    queue<pair<TreeNode<int>*,int>>q;
    q.push({root, 0});
    
    //idx,value
    map<int,int>mpp;
    // mpp[root->val]=0;
    
    while(!q.empty()){
        int sz=q.size();
        while(sz--){
            auto it= q.front();
            q.pop();
            int idx=it.second;
            int val=it.first->val;

            if(mpp[idx]==0) mpp[idx]=val;
            
            if(it.first->left)
              q.push({it.first->left, idx - 1});
            
            if (it.first->right) 
              q.push({it.first->right,idx+1});
        }
    }
    vector<int>ans;
    // ans.clear();
    for(auto &it:mpp) ans.push_back(it.second);
    return ans;

}
