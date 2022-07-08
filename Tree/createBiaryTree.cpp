#include<bits/stdc++.h>
using namespace std;

class node{
public:
  int data;
  node* left;
  node* right;
  node(int data){
    this->data=data;
    this->left=NULL;
    this->right=NULL;
  }
};

node* buildTree(node* root){
  cout<<"Enter data: "<<endl;
  int data;
  cin>>data;
  root=new node(data);

  if(data==-1){
    return NULL;
  }
  cout<<"Enter data for left of "<<data<<endl;
  root->left=buildTree(root->left);
  cout<<"Eter data for right of "<<data<<endl;
  root->right=buildTree(root->right);

  return root;
}

void levelOrderTraversal(node* root){
  queue<node*>q;
  q.push(root);
  q.push(NULL);

  while(!q.empty()){
    node* temp=q.front();
    q.pop();

    if(temp==NULL){ //check for end of level using null value
      cout<<endl;
      if(!q.empty()){
        q.push(NULL); //if queue is not empty then push another null value to queue
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

void inorder(node* root){
  if(root==NULL){
    return;
  }
  inorder(root->left);
  cout<<root->data<<" ";
  inorder(root->right);
}

void preorder(node* root){
  if(root==NULL){
    return;
  }
  cout<<root->data<<" ";
  preorder(root->left);
  preorder(root->right);
}

void postorder(node* root){
  if(root==NULL){
    return;
  }
  postorder(root->left);
  postorder(root->right);
  cout<<root->data<<" ";
}

void buildFromLeveleOrder(node* &root){
  queue<node*>q;
  cout<<"Enter data for root"<<endl;
  int data;
  cin>>data;
  root=new node(data);
  q.push(root);

  while(!q.empty()){
    node* temp=q.front();
    q.pop();

    cout<<"Enter data for left of "<<temp->data<<endl;
    int leftData;
    cin>>leftData;
    if(leftData!=-1){
      temp->left=new node(leftData);
      q.push(temp->left);
    }

    cout<<"Enter data for right of "<<temp->data<<endl;
    int rightData;
    cin>>rightData;
    if(rightData!=-1){
      temp->right=new node(rightData);
      q.push(temp->right);
    }
  }
}

int main(){
  node* root=NULL;
  // root=buildTree(root);

  buildFromLeveleOrder(root);

  levelOrderTraversal(root);

  cout<<"Inorder Traversal"<<endl;
  inorder(root);cout<<endl;

  cout<<"Preorder Traversal"<<endl;
  preorder(root);cout<<endl;
  
  cout<<"Postorder Traversal"<<endl;
  postorder(root);cout<<endl;

  return 0;
}
