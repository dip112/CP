//https://leetcode.com/problems/leaf-similar-trees/
class Solution {
    vector<int>tree1;
public:
    void preorder(TreeNode* root){
        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){
            tree1.push_back(root->val);
        }
        preorder(root->left);
        preorder(root->right);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        preorder(root1);
        
        vector<int>tree2=tree1;
        tree1.clear();
        
        preorder(root2);
        
        if(tree1.size()==tree2.size()){
            for(int i=0;i<tree1.size();i++){
                if(tree1[i]!=tree2[i]){
                    return 0;
                }
            }
            return 1;
        }
        return 0;
    }
};
