//https://www.codingninjas.com/codestudio/problems/find-k-th-smallest-element-in-bst_1069333?leftPanelTab=0
int solve(BinaryTreeNode<int>* root , int &i , int k){
    if(root==NULL){
        return -1;
    }
    int left=solve(root->left , i , k);
    if(left!=-1){
        return left;
    }
    i++;
    if(i==k){
        return root->data;
    }
    return solve(root->right , i , k);
}
int kthSmallest(BinaryTreeNode<int>* root, int k) {
    int i=0;
    int ans=solve(root , i , k);
    return ans;
}

///////////////////////////////////////////////////
class Solution {
public:
    void inorder(TreeNode* root , int &k , int &ans){
        if(root==NULL){
            return ;
        }
        inorder(root->left , k , ans);
        k--;
        if(k==0){
            ans=root->val;
        }
        inorder(root->right , k , ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        
        int ans=0;
        
        inorder(root , k , ans);
        
        return ans;
    }
};
//Time: O(N)
//Space: O(H) , Worst Case(skewed tree): O(N)
