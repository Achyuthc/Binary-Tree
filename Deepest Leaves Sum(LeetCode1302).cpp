/*Given the root of a binary tree, return the sum of values of its deepest leaves.*/

class Solution {
public:
    int sum=0;

void inorder(TreeNode *root,int level,int &maxHeight)
{
	if(!root)
	    return;
	if(level==maxHeight)
	   sum+=root->val;
	if(level>maxHeight)
	{
	     sum=root->val;
	     maxHeight=level;
	}
	inorder(root->left,level+1,maxHeight);
	
	inorder(root->right,level+1,maxHeight);
}

    int deepestLeavesSum(TreeNode* root) {
    
	int maxHeight=0;
	inorder(root,1,maxHeight);
	return sum;

        
    }
};
