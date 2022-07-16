//https://www.codingninjas.com/codestudio/problems/convert-bst-to-min-heap_920498?leftPanelTab=0
void inorder(BinaryTreeNode* root , vector<int>&in){
    if(root==NULL){
        return;
    }
    inorder(root->left , in);
    in.push_back(root->data);
    inorder(root->right ,in);
}
void fillPreorder(BinaryTreeNode* &root , vector<int>&in , int &i){
    if(root==NULL){
        return;
    }
    root->data=in[i++];
    fillPreorder(root->left , in ,i);
    fillPreorder(root->right , in , i);
}
BinaryTreeNode* convertBST(BinaryTreeNode* root)
{
	vector<int>in;
    inorder(root , in);
    int i=0;
    fillPreorder(root , in , i);
    return root;
}
