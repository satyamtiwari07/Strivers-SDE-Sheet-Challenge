#include <bits/stdc++.h> 
/*   
    template <typename T = int>
	class TreeNode
	{
		public:
		T data;
		TreeNode<T> *left;
		TreeNode<T> *right;

		TreeNode(T data)
		{
			this->data = data;
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
*/
int f(TreeNode<int> *root,int x,vector<int>&ans){
	if(root==NULL) return 0;
	if(root->data==x){
		ans.push_back(root->data);
		return 1;
	}

	ans.push_back(root->data);
	if(f(root->left,x,ans)) return 1;
	if(f(root->right,x,ans)) return 1;
	ans.pop_back();
	return 0;
}

vector<int> pathInATree(TreeNode<int> *root, int x)
{
    // Write your code here.
	vector<int>ans;
	f(root,x,ans);
	return ans;
}
