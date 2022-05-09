/*Implement the BSTIterator class that represents an iterator over the in-order traversal of a binary search tree (BST):

BSTIterator(TreeNode root) Initializes an object of the BSTIterator class. The root of the BST is given as part of the constructor. The pointer should be initialized to a non-existent number smaller than any element in the BST.
boolean hasNext() Returns true if there exists a number in the traversal to the right of the pointer, otherwise returns false.
int next() Moves the pointer to the right, then returns the number at the pointer.*/


class BSTIterator {
public:
    stack<TreeNode *>st;
    TreeNode *root;
    int val;
    BSTIterator(TreeNode* root) {
        this->root=root;
    }
    
    int next() {
         while(root)
        {
            st.push(root);
            root=root->left;
        }
        root=st.top();
        st.pop();
        val=root->val;
        root=root->right;
        return val;
        
    }
    
    bool hasNext() {
        return (root!=NULL)||!st.empty();
    }
};
