/*Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.*/


class Solution {
public:
    bool valid(TreeNode *root,TreeNode * &prev)
    {
        if(!root)
            return true;
        bool left=valid(root->left,prev);
        if(prev!=NULL&&prev->val>=root->val)
            return false;
        prev=root;
        bool right=valid(root->right,prev);
        return left&&right;
        
    }
    bool isValidBST(TreeNode* root) {
        TreeNode *prev=NULL;
        return valid(root,prev);
    }
};
