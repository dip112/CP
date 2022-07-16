//https://practice.geeksforgeeks.org/problems/is-binary-tree-heap/1
//https://www.codingninjas.com/codestudio/problems/is-binary-heap-tree_893136?leftPanelTab=0
class Solution {
    int cntNode(struct Node* root){
        if(root==NULL){
            return 0;
        }
        int ans=1+cntNode(root->left)+cntNode(root->right);
        return ans;
    }
    bool isCBT(struct Node* root , int i , int cnt){
        if(root==NULL){
            return true;
        }
        if(i>=cnt){
            return false;
        }
        else{
            bool left=isCBT(root->left , 2*i+1 , cnt);
            bool right=isCBT(root->right , 2*i+2 , cnt);
            return left&&right;
        }
    }
    bool isMaxOrder(struct Node* root){
        if(root->left==NULL && root->right==NULL){
            return true;
        }
        if(root->right==NULL){
            return (root->data>root->left->data);
        }
        else{
            bool left=isMaxOrder(root->left);
            bool right=isMaxOrder(root->right);
            return (left&&right) && (root->data>root->left->data)&& (root->data>root->right->data);
        }
    }
  public:
    bool isHeap(struct Node* tree) {
        int i=0;
        int cnt=cntNode(tree);
        
        if(isCBT(tree , i , cnt) && isMaxOrder(tree)){
            return true;
        }
        else{
            return false;
        }
    }
};
