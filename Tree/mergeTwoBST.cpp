//https://www.codingninjas.com/codestudio/problems/h_920474?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
//https://practice.geeksforgeeks.org/problems/merge-two-bst-s/1#
//approach1
void inorder(TreeNode<int>*root , vector<int>&v){
    if(root==NULL){
        return;
    }
    inorder(root->left , v);
    v.push_back(root->data);
    inorder(root->right , v);
}
vector<int> merge(vector<int>&v1 , vector<int>v2){
    vector<int>ans(v1.size()+v2.size());
    int i=0 , j=0 , k=0;
    while(i<v1.size() && j<v2.size()){
        if(v1[i]<v2[j]){
            ans[k++]=v1[i++];
        }
        else{
            ans[k++]=v2[j++];
        }
    }
    while(i<v1.size()){
        ans[k++]=v1[i++];
    }
    while(j<v2.size()){
        ans[k++]=v2[j++];
    }
    return ans;
}
TreeNode<int>* inorderToBST(int s , int e , vector<int>&v){
    if(s>e){
        return NULL;
    }
    int mid=(s+e)/2;
    TreeNode<int>* root=new TreeNode<int>(v[mid]);
    root->left=inorderToBST(s , mid-1 , v);
    root->right=inorderToBST(mid+1 , e , v);
    return root;
}
TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){
    vector<int>v1 , v2;
    inorder(root1,  v1);
    inorder(root2 , v2);
    
    vector<int>mergedArray=merge(v1 , v2);
    return inorderToBST(0 , mergedArray.size()-1 , mergedArray);
}
//Time: O(m+n)
//Space: O(m+n)
