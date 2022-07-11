//https://www.codingninjas.com/codestudio/problems/flatten-bst-to-a-sorted-list_1169459?leftPanelTab=0
void inorder(TreeNode<int>* root , vector<int>&v){
    if(root==NULL){
        return;
    }
    inorder(root->left , v);
    v.push_back(root->data);
    inorder(root->right , v);
}
TreeNode<int>* flatten(TreeNode<int>* root)
{
    vector<int>v;
    inorder(root , v);
    TreeNode<int>* newRoot=new TreeNode<int>(v[0]);
    TreeNode<int>* curr=newRoot;
    for(int i=1;i<v.size();i++){
        TreeNode<int>* temp=new TreeNode<int>(v[i]);
        curr->left=NULL;
        curr->right=temp;
        curr=temp;
    }
    curr->left=NULL;
    curr->right=NULL;
    return newRoot;
}
