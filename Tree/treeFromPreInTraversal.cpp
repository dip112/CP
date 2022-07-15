//https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

class Solution {
    TreeNode* constructTree(vector<int>& preorder, vector<int>& inorder , int &indx , int left ,int right){
        if(left>right){
            return NULL;
        }
        int pivot=left;
        while(inorder[pivot]!=preorder[indx]){
            pivot++;
        }
        indx++;
        TreeNode* root=new TreeNode(inorder[pivot]);
        root->left=constructTree(preorder , inorder , indx , left , pivot-1);
        root->right=constructTree(preorder , inorder , indx , pivot+1 , right);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int indx=0;
        return constructTree(preorder , inorder , indx , 0 , inorder.size()-1);
    }
};
