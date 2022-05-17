

int ans=0;
pair<int,int> solve(BinaryTreeNode<int> *root)
{
	if(!root)
		return {0,0};
	pair<int,int> left=solve(root->left);
	pair<int,int> right=solve(root->right);
	pair<int,int> p={1,1};
	if(root->left)
	{
		if(root->left->data+1==root->data)
		{
			p.first=max(p.first,left.first+1);
		}
		if(root->left->data==root->data+1)
		{
			p.second=max(p.second,left.second+1);
		}
	}
	if(root->right)
	{
		if(root->right->data+1==root->data)
		{
			p.first=max(p.first,right.first+1);
		}
		if(root->right->data==root->data+1)
		{
			p.second=max(p.second,right.second+1);
		}
	}
	ans=max(ans,p.first+p.second-1);
	return {p.first,p.second};
}
int maxPath(BinaryTreeNode<int> *root) {
    // Write your code here
	solve(root);
	return ans;
}
