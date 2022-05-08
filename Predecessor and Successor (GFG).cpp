/*There is BST given with root node with key part as integer only.
You need to find the inorder successor and predecessor of a given key. In case, if the either of predecessor or successor is not found print -1.*/


void inorder(Node *root,Node *&pre,Node *& suc,int key,Node *&prev)
{
    if(!root)
        return ;
    inorder(root->left,pre,suc,key,prev);
    if(root->key<key)
        pre=root;
    if(root->key>key)
    {
        if(!suc||(suc)&&suc->key>root->key)
        {
            suc=root;
        }
    }
        
    prev=root;
    inorder(root->right,pre,suc,key,prev);
}
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{

// Your code goes here
        pre=NULL;
        suc=NULL;
        Node *prev=NULL;
        inorder(root,pre,suc,key,prev);
        
        

}
