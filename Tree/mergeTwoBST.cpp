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

//approach2
void BSTtoSortedLL(TreeNode<int> *root , TreeNode<int> *&head){
    if(root==NULL){
        return ;
    }
    BSTtoSortedLL(root->right , head);
    root->right=head;
    if(head!=NULL){
        head->left=root;
    }
    head=root;
    BSTtoSortedLL(root->left , head);
}
TreeNode<int> *mergeSortedLL(TreeNode<int> *&head1 , TreeNode<int> *&head2){
    TreeNode<int> *head=NULL;
    TreeNode<int> *tail=NULL;
    while(head1!=NULL && head2!=NULL){
        if(head1->data<head2->data){
            if(head==NULL){
                head=head1;
                tail=head1;
                head1=head1->right;
            }
            else{
                tail->right=head1;
                head1->left=tail;
                tail=head1;
                head1=head1->right;
            }
        }
        else{
            if(head==NULL){
                head=head2;
                tail=head2;
                head2=head2->right;
            }
            else{
                tail->right=head2;
                head2->left=tail;
                tail=head2;
                head2=head2->right;
            }
        }
    }
    while(head1!=NULL){
        tail->right=head1;
        head1->left=tail;
        tail=head1;
        head1=head1->right;
    }
    while(head2!=NULL){
        tail->right=head2;
        head2->left=tail;
        tail=head2;
        head2=head2->right;
    }
    return head;
}
int countNodes(TreeNode<int> *head){
    TreeNode<int>*temp=head;
    int count=0;
    while(temp!=NULL){
        count++;
        temp=temp->right;
    }
    return count;
}
TreeNode<int>* sortedLLtoBST(TreeNode<int>* &head , int n){
    if(n<=0 || head==NULL){
        return NULL;
    }
    TreeNode<int>*left=sortedLLtoBST(head , n/2);
    TreeNode<int>*root=head;
    root->left=left;
    head=head->right;
    root->right=sortedLLtoBST(head , (n-n/2-1));
    return root;
}
TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){
    //convert 1st
    TreeNode<int> *head1=NULL;
    BSTtoSortedLL(root1 , head1);
    head1->left=NULL;
    
    TreeNode<int> *head2=NULL;
    BSTtoSortedLL(root2 , head2);
    head2->left=NULL;
    
    TreeNode<int> *head=mergeSortedLL(head1 , head2);
    
    int n=countNodes(head);
    return sortedLLtoBST(head , n);
}
//Time: O(M+N)
//Spcce: O(H1+H2)
