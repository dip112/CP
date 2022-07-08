//https://practice.geeksforgeeks.org/problems/flatten-binary-tree-to-linked-list/1/#
//https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
class Solution
{
    public:
    void flatten(Node *root)
    {
        Node* curr=root;
        while(curr!=NULL){
            if(curr->left!=NULL){
                Node* pre=curr->left;
                
                while(pre->right!=NULL){
                    pre=pre->right;
                }
                
                pre->right=curr->right;
                curr->right=curr->left;
                curr->left=NULL;
            }
            curr=curr->right;
        }
    }
};
