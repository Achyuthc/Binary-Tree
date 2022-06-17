
/*You are given the root of a binary tree. We install cameras on the tree nodes where each camera at a node can monitor its parent, itself, and its immediate children.

Return the minimum number of cameras needed to monitor all nodes of the tree.*/

class Solution {
public:
    int ans=0;
    
    int minCameraCover(TreeNode* root) {
        
        return (dfs(root)<1?1:0)+ans;
    }
    
    int dfs(TreeNode *root)
    {
        if(!root)
            return 2;
        
        int left=dfs(root->left),right=dfs(root->right);
        
        if(left==0||right==0)
        {
            ans++;
            return 1;
        }    
        
        return left==1||right==1?2:0;
    }
};
