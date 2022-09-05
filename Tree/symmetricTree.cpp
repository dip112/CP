//https://leetcode.com/problems/symmetric-tree/
class Solution {
    bool solve(TreeNode* root1 , TreeNode* root2){
        if(root1==NULL && root2==NULL){
            return true;
        }
        if(root1==NULL && root2!=NULL){
            return false;
        }
        if(root1!=NULL && root2==NULL){
            return false;
        }
        if(root1->val!=root2->val){
            return false;
        }
        
        bool ans1=solve(root1->left , root2->right);
        bool ans2=solve(root1->right , root2->left);
        
        return ans1&ans2;
    }
public:
    bool isSymmetric(TreeNode* root) {
        return solve(root->left , root->right);
    }
};
