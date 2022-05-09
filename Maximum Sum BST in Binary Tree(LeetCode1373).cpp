/*Given a binary tree root, return the maximum sum of all keys of any sub-tree which is also a Binary Search Tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class prop{
public:
    bool bst;       //to check if tree is bst
    int ma;         //max value in a tree
    int mi;         //min value in an tree
    int ms;         //current maximum sum
    prop(){
        bst=true;
        ma=INT_MIN;
        mi=INT_MAX;
        ms=0;
    }
};
class Solution {
public:
    int ans=0;
    prop calcSum(TreeNode *root)
    {
        if(!root)
        {
            return prop();
        }
        prop pl=calcSum(root->left);
        prop pr=calcSum(root->right);
        prop p=prop();
        if(pl.bst==true&&pr.bst==true&&pl.ma<root->val&&root->val<pr.mi)
        {
            p.mi=min(root->val,min(pl.mi,pr.mi));
            p.ma=max(root->val,max(pl.ma,pr.ma));
            p.ms=root->val+pl.ms+pr.ms;
        }
        else
        {
            p.bst=false;
            p.ms=0;
        }
        if(p.bst)
            ans=max(ans,p.ms);
        return p;
    }
    int maxSumBST(TreeNode* root) {
        
        calcSum(root);
        return ans;
    }
};
