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
int f(TreeNode<int> *root,int &ans){
    if(root==NULL) return 0;
    int l=f(root->left,ans);
    int r=f(root->right,ans);
    ans=max(ans,l+r);
    return max(l,r)+1;
}
int diameterOfBinaryTree(TreeNode<int> *root)
{
	// Write Your Code Here.
    int ans=0;
    f(root,ans);
    return ans;
}
