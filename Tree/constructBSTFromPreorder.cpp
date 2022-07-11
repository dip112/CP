//https://www.codingninjas.com/codestudio/problems/preorder-traversal-to-bst_893111?leftPanelTab=0
//https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
//Approach2
class Solution {
    TreeNode* preorderToBST(int s , int e , vector<int>&pre){
        if(s>e){
            return NULL;
        }
        int mid=(s+e)/2;
        TreeNode* root=new TreeNode(pre[mid]);
        root->left=preorderToBST(s , mid-1 , pre);
        root->right=preorderToBST(mid+1 , e , pre);
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        sort(preorder.begin() , preorder.end());
        return preorderToBST(0 , preorder.size()-1 , preorder);
    }
};
//Time: O(NlogN)
//approach3
BinaryTreeNode<int>* solve(int mini , int maxi , int &i , vector<int> &pre){
    if(i>=pre.size()){
        return NULL;
    }
    if(pre[i]<mini || pre[i]>maxi){
        return NULL;
    }
    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(pre[i++]);
    root->left=solve(mini , root->data , i , pre);
    root->right=solve(root->data , maxi , i , pre);
    return root;
}
BinaryTreeNode<int>* preorderToBST(vector<int> &preorder) {
    int mini=INT_MIN;
    int maxi=INT_MAX;
    int i=0;
    return solve(mini , maxi , i , preorder);
}
//Time: O(N)
