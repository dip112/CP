//https://practice.geeksforgeeks.org/problems/bst-to-max-heap/1
class Solution{
    void inorder(Node* root , vector<int>&in){
        if(root==NULL){
            return;
        }
        inorder(root->left , in);
        in.push_back(root->data);
        inorder(root->right , in);
    }
    void fillPreorder(Node* root , vector<int>&in , int &i){
        if(root==NULL){
            return;
        }
        
        fillPreorder(root->left , in , i);
        fillPreorder(root->right , in , i);
        root->data=in[i++];
    }
  public:
    void convertToMaxHeapUtil(Node* root)
    {
        vector<int>in;
        inorder(root , in);
        // sort(in.begin() , in.end() , greater<int>());
        int i=0;
        fillPreorder(root , in , i);
    }    
};
