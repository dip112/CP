//https://www.codingninjas.com/codestudio/problems/_893049?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0
//https://practice.geeksforgeeks.org/problems/predecessor-and-successor/1
//https://leetcode.com/problems/inorder-successor-in-bst/

//approach2
pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    int pred=-1;
    int succ=-1;
    BinaryTreeNode<int>*temp=root;
    
    while(temp->data!=key){
        if(key<temp->data){
            succ=temp->data;
            temp=temp->left;
        }
        else{
            pred=temp->data;
            temp=temp->right;
        }
    }
    BinaryTreeNode<int>* leftTree=temp->left;
    while(leftTree!=NULL){
        pred=leftTree->data;
        leftTree=leftTree->right;
    }
    
    BinaryTreeNode<int>* rightTree=temp->right;
    while(rightTree!=NULL){
        succ=rightTree->data;
        rightTree=rightTree->left;
    }
    return {pred , succ};
}
//time: O(N)
//space: O(1)
