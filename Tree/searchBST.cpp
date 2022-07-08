//https://www.codingninjas.com/codestudio/problems/search-in-bst_1402878?leftPanelTab=0
//https://leetcode.com/problems/search-in-a-binary-search-tree/

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root){
            return NULL;
        }
        if(root->val==val){
            return root;
        }
        
        if(root->val>val){
            return searchBST(root->left , val);
        }
        else{
            return searchBST(root->right , val);
        }
        
    }
};
//Time complexsity: O(logN)
//if it is skewed tree then it O(N)
//Space complexsity: O(H)

bool searchInBST(BinaryTreeNode<int> *root, int x) {
    BinaryTreeNode<int> *temp=root;
    
    while(temp!=NULL){
        if(temp->data==x){
            return 1;
        }
        if(temp->data>x){
            temp=temp->left;
        }
        else{
            temp=temp->right;
        }
    }
    return 0;
}
//Time complexsity: O(logN)
//if it is skewed tree then it O(N)
//Space complexsity: O(1)
