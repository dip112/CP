Node* deleteFromBST(Node* root , int x){
  if(root==NULL){
    return NULL;
  }
  if(root->data==x){
    //0 child
    if(root->left==NULL && root->right==NULL){
      delete root;
      return NULL;
    }
    //1 child
    //-left child
    if(root->left!=NULL && root->right==NULL){
      Node* temp=root->left;
      delete root;
      return temp;
    }
    //-right child
    if(root->left==NULL && root->right!=NULL){
      Node* temp=root->right;
      delete root;
      return temp;
    }
    //2 child
    if(root->left!=NULL && root->right!=NULL){
      int mini=minVal(root->right)->data;
      root->data=mini;
      root->right=deleteFromBST(root->right , mini);
      return root;
    }
  }
  else if(root->data>x){
    root->left=deleteFromBST(root->left , x);
    return root;
  }
  else{
    root->right=deleteFromBST(root->right , x);
    return root;
  }
}
