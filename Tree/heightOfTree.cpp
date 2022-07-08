//https://leetcode.com/problems/maximum-depth-of-binary-tree/
//https://practice.geeksforgeeks.org/problems/height-of-binary-tree/1#

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        
        int left=maxDepth(root->left);
        int right=maxDepth(root->right);
        
        int ans=max(left,right)+1;
        return ans;
    }
};
