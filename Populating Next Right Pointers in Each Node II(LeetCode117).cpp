/*Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.*/

class Solution {
public:
    Node *getNode(Node *cur)
    {
        while(cur&&(cur->left==NULL)&&(cur->right==NULL))
        {
            cur=cur->next;
        }
        if(!cur)
            return cur;
        if(cur->left)
            return cur->left;
        return cur->right;
    }
    Node* connect(Node* root) {
        if(!root)
            return root;
        Node *cur;
        Node *head=root;
        root->next=NULL;
        while(root)
        {
            cur=root;
            while(cur)
            {
                 if(cur->left)
                {
                    if(cur->right)
                    {
                        cur->left->next=cur->right;
                        cur->right->next=getNode(cur->next);
                    }
                    else
                    {
                        
                        cur->left->next=getNode(cur->next);
                    }

                }
                else
                {
                    if(cur->right)
                    {
                        cur->right->next=getNode(cur->next);
                    }
                    
                }
                cur=cur->next;
                while(cur&&(cur->left==NULL)&&(cur->right==NULL))
                {
                    cur=cur->next;
                }
            }
            cur=root;
            while(cur&&(cur->left==NULL)&&(cur->right==NULL))
                {
                    cur=cur->next;
                }
            root=cur;
            if(root)
            root=root->left?root->left:root->right;
           
        }
        return head;
        
        
    }
};
