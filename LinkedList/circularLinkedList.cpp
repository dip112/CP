#include<bits/stdc++.h>
using namespace std;
class Node{
public:
  int data;
  Node* next;
  Node(int val){
    this->data=val;
    next=NULL;
  }
  ~Node(){
    cout<<this->data<<" deleted\n";
    if(this->next!=NULL){
      delete this->next;
      this->next=NULL;
    }
  }
};

void insertNode(Node* &head , Node* &tail){
  int val;
  cout<<"Enter value for insertion\n";
  cin>>val;
  if(tail==NULL && tail==NULL){
    Node* newNode=new Node(val);
    head=newNode;
    tail=newNode;
    newNode->next=newNode;
  }
  else{
    Node* newNode=new Node(val);
    tail->next=newNode;
    newNode->next=head;
    tail=newNode;
  }
}
void deleteNode(Node* &head , Node* &tail){
  if(head==NULL){
    cout<<"Deletion not possible\n";
    return;
  }
  else{
    int element;
    cout<<"Enter element that yo want delete\n";
    cin>>element;
    Node* prev=tail;
    Node* curr=prev->next;
    while(element!=curr->data){
      prev=curr;
      curr=curr->next;
    }

    prev->next=curr->next;
    if(curr==prev){
      tail=NULL;
    }
    else if(tail==curr){
      tail=prev;
    }
    curr->next=NULL;
    delete curr;
  }
}

void print(Node* &tail){
  if(tail==NULL){
    cout<<"List is empty\n";
    return ;
  }
  else{
    Node* curr=tail;
    do{
      cout<<tail->data<<" ";
      tail=tail->next;
    }while(curr!=tail);
    cout<<endl;
  }
}
int main(){
  Node* head=NULL;
  Node* tail=NULL;
  while(1){
    cout<<"Enter 1 for insertNode\n"<<"Enter 2 for print\n"<<"Enter 3 for deleteNode\n"<<"Enter 4 for exit\n";
    int ch;
    cin>>ch;
    switch(ch){
      case 1: insertNode(head , tail);
      break;
      case 2: print(head);
      break;
      case 3: deleteNode(head , tail);
      break;
      case 4: exit(0);
      break;
      defualt: cout<<"Enter valid option\n";
    }
  }
  return 0;
}
