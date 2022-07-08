//https://leetcode.com/problems/binary-tree-inorder-traversal/
//https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion-and-without-stack/
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) { //moris traversal
        vector<int>ans;
        
        if(root==NULL){
            return ans;
        }
        
        TreeNode* current=root;
        TreeNode* pre;
        
        while(current!=NULL){
            if(current->left==NULL){
                ans.push_back(current->val);
                current=current->right;
            }
            else{
                pre=current->left;
                while(pre->right!=NULL && pre->right!=current){
                    pre=pre->right;
                }
                
                if(pre->right==NULL){
                    pre->right=current;
                    current=current->left;
                }
                else{
                    pre->right=NULL;
                    ans.push_back(current->val);
                    current=current->right;
                }
            }
        }
        return ans;
    }
};
//Time complexsity: O(n)
//Space complexsity; O(1)
