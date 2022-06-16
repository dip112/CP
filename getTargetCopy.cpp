//https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/
class Solution {
public:
    void inorder(TreeNode* cloned , TreeNode* target , TreeNode* &ans){
        if(cloned==NULL){
            return;
        }
        inorder(cloned->left , target , ans);
        
        if(cloned!=NULL && cloned->val==target->val){
            ans=cloned;
            return;
        }
        
        inorder(cloned->right , target , ans);
    }
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode* ans;
        inorder(cloned , target , ans);
        return ans;
    }
};
