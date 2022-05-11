/*Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).*/

class Solution {
public:
    vector<vector<int>> ans;
    int depth(TreeNode *root)
    {
        if(!root)
            return 0;
        return 1+max(depth(root->left),depth(root->right));
    }
    void inorder(TreeNode *root,int l)
    {
        if(!root)
            return ;
        inorder(root->left,l+1);
        ans[l].push_back(root->val);
        inorder(root->right,l+1);
        
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        int d=depth(root);
        ans.resize(d);
        inorder(root,0);
        for(int i=0;i<d;i++)
        {
            if(i%2==1)
                reverse(ans[i].begin(),ans[i].end());
        }
        return ans;
    }
};
