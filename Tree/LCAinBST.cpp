//https://www.codingninjas.com/codestudio/problems/lca-in-a-bst_981280?leftPanelTab=0
//https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* P, TreeNode<int>* Q)
{
	while(root!=NULL){
        if(root->data<P->data && root->data<Q->data){
            root=root->right;
        }
        else if(root->data>P->data && root->data>Q->data){
            root=root->left;
        }
        else{
            return root;
        }
    }
}

//------------------------------------------------------------------
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL){
            return NULL;
        }
        if(root->val<p->val && root->val<q->val){
            return lowestCommonAncestor(root->right , p ,q);
        }
        if(root->val>p->val && root->val>q->val){
            return lowestCommonAncestor(root->left , p ,q);
        }
        return root;
    }
};
