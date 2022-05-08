/*Given the root of a binary tree, flatten the tree into a "linked list":

The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.*/


class Solution {
public:
        TreeNode *flattoll(TreeNode *root,TreeNode *next)
        {
            if(!root)
                return next;
                TreeNode *right=flattoll(root->right,next);
                TreeNode *left=flattoll(root->left,right);
            root->left=NULL;
            root->right=left;
            return root;
        }
    void flatten(TreeNode* root) {
           flattoll(root,NULL);
            
        
    }
};