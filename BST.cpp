#include<bits/stdc++.h>
using namespace std;
class Node{
public:
  int data;
  Node* right;
  Node* left;
  Node(int data){
    this->data=data;
    this->right=NULL;
    this->left=NULL;
  }
};

Node* insertNode(Node* root , int val){
  if(root==NULL){
    root=new Node(val);
    return root;
  }
  if(root->data<val){
    root->right=insertNode(root->right , val);
  }
  else{
    root->left=insertNode(root->left , val);
  }
  return root;
}

void takeInput(Node* &root){
  cout<<"Enter data"<<endl;
  int d;
  cin>>d;
  while(d!=-1){
    root=insertNode(root , d);
    cin>>d;
  }
}

void levelOrderTraversal(Node* root){
  queue<Node*>q;
  q.push(root);
  q.push(NULL);

  while(!q.empty()){
    Node* temp=q.front();
    q.pop();

    if(temp==NULL){
      cout<<endl;
      if(!q.empty()){
        q.push(NULL);
      }
    }
    else{
      cout<<temp->data<<" ";
      if(temp->left!=NULL){
        q.push(temp->left);
      }
      if(temp->right!=NULL){
        q.push(temp->right);
      }
    }
  }
}

void inorder(Node* root){
  if(root==NULL){
    return;
  }
  inorder(root->left);
  cout<<root->data<<" ";
  inorder(root->right);
}

void preorder(Node* root){
  if(root==NULL){
    return;
  }
  cout<<root->data<<" ";
  preorder(root->left);
  preorder(root->right);
}

void postorder(Node* root){
  if(root==NULL){
    return;
  }
  postorder(root->left);
  postorder(root->right);
  cout<<root->data<<" ";
}

int main(){
  Node* root=NULL;
  takeInput(root);

  cout<<"Levele Order Traversal\n";
  levelOrderTraversal(root);

  cout<<"Inorder Traversal\n";
  inorder(root);cout<<endl;

  cout<<"Preorder Traversal\n";
  preorder(root);cout<<endl;

  cout<<"Postorder Traversal\n";
  postorder(root);cout<<endl;
  
  return 0;
}
