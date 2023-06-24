#include<bits/stdc++.h>
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

string serializeTree(TreeNode<int> *root)
{
 //    Write your code here for serializing the tree
 string str="";
 if(root==NULL) return str;
 queue<TreeNode<int>*>q;
 q.push(root);

 while(!q.empty()){
    int sz = q.size();
    while(sz--){
        auto it = q.front();
        q.pop();
        if(it){
            str += to_string(it->data);
            str += ",";
            q.push(it->left);
            q.push(it->right);
        }
        else str+="#,";
    }
 }
//  cout<<str<<" ";
 return str;
}

TreeNode<int>* deserializeTree(string &serialized)
{
 //    Write your code here for deserializing the tree
  if(serialized.size()==0) return NULL;
  string t;
  stringstream ss(serialized);
  getline(ss,t,',');
  
  TreeNode<int> *root = new TreeNode<int>(stoi(t));
  
  queue<TreeNode<int> *>q;
  q.push(root);
  
  while(!q.empty()){
      auto it=q.front();
      q.pop();

      getline(ss,t,',');
      if(t=="#"){
          it->left=NULL;
      }
      else{
          it->left = new TreeNode<int>(stoi(t));
          q.push(it->left);
      }

      getline(ss,t,',');
      if(t=="#"){
          it->right=NULL;
      }
      else{
          it->right = new TreeNode<int>(stoi(t));
          q.push(it->right);
      }
  }
  return root;
}



