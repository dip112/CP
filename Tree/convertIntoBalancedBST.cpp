//https://www.codingninjas.com/codestudio/problems/normal-bst-to-balanced-bst_920472?leftPanelTab=0
//https://leetcode.com/problems/balance-a-binary-search-tree/
//https://practice.geeksforgeeks.org/problems/normal-bst-to-balanced-bst/1
void inorder(TreeNode<int>* root , vector<int>&v){
    if(root==NULL){
        return;
    }
    inorder(root->left , v);
    v.push_back(root->data);
    inorder(root->right , v);
}
TreeNode<int>*inorderToBST(int s , int e , vector<int>&v){
    if(s>e){
        return NULL;
    }
    int mid=(s+e)/2;
    TreeNode<int>*newRoot=new TreeNode<int>(v[mid]);
    newRoot->left=inorderToBST(s , mid-1 , v);
    newRoot->right=inorderToBST(mid+1 , e , v);
    return newRoot;
}
TreeNode<int>* balancedBst(TreeNode<int>* root) {
    vector<int>v;
    inorder(root , v);
    return inorderToBST(0 , v.size()-1 , v);
}
