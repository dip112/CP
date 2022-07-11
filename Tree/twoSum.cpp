//https://www.codingninjas.com/codestudio/problems/two-sum-in-a-bst_1062631?leftPanelTab=0
//https://practice.geeksforgeeks.org/problems/find-a-pair-with-given-target-in-bst/1#
//https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
void inorder(BinaryTreeNode<int>* root , vector<int>&temp){
    if(root==NULL){
        return;
    }
    inorder(root->left , temp);
    temp.push_back(root->data);
    inorder(root->right , temp);
}
bool twoSumInBST(BinaryTreeNode<int>* root, int target) {
	vector<int>temp;
    inorder(root , temp);
    int i=0 , j=temp.size()-1;
    while(i<j){
        int sum=temp[i]+temp[j];
        if(sum==target){
            return 1;
        }
        else if(sum>target){
            j--;
        }
        else{
            i++;
        }
    }
    return 0;
}
