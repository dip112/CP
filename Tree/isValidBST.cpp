//https://www.codingninjas.com/codestudio/problems/validate-bst_799483?leftPanelTab=0
//https://leetcode.com/problems/validate-binary-search-tree/
//https://practice.geeksforgeeks.org/problems/check-for-bst/1#

//approach1
void inorder(BinaryTreeNode<int> *root , vector<int>&temp){
    if(root==NULL){
        return;
    }
    inorder(root->left , temp);
    temp.push_back(root->data);
    inorder(root->right , temp);
}
bool validateBST(BinaryTreeNode<int> *root) {
    vector<int>temp;
    inorder(root , temp);
    for(int i=1;i<temp.size();i++){
        if(temp[i]<temp[i-1]){
            return 0;
        }
    }
    return 1;
}
//Time complexsity: O(n)
//space complexsity: O(n)

//approach2
bool isValid(BinaryTreeNode<int> *root , int min , int max){
    if(root==NULL){
        return 1;
    }
    if(root->data>=min && root->data<=max){
        bool left=isValid(root->left , min , root->data);
        bool right=isValid(root->right , root->data , max);
        return left&&right;
    }
    return 0;
}
bool validateBST(BinaryTreeNode<int> *root) {
    return isValid(root , INT_MIN , INT_MAX);
}
//Time Complexsity: O(n)
//Space complexsity: O(h)   worst case (skewed tree): O(n)
