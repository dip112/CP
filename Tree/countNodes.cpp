//https://leetcode.com/problems/count-complete-tree-nodes/
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int ans=1+countNodes(root->left)+countNodes(root->right);
        return ans;
    }
};
