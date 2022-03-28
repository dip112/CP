#include<bits/stdc++.h>
using namespace std;
class Node{
public:
  int data;
  Node* prev;
  Node* next;
  Node(int data)
  {
    this->data=data;
    this->prev=NULL;
    this->next=NULL;
  }

  ~Node(){
    if(this->next!=NULL){
      delete this->next;
      //next=NULL;
    }
    cout<<"Memory freed for current node\n";
  }
};

void insertFirst(Node* &head , Node* &tail){
  int val;
  cout<<"Enter value for insertion\n";
  cin>>val;
  if(head==NULL){
    Node* temp=new Node(val);
    head=temp;
    tail=temp;
  }
  else{
    Node* temp=new Node(val);
    temp->next=head;
    head->prev=temp;
    head=temp;
  }
}

void insertLast(Node* &tail , Node* &head){
  int val;
  cout<<"Enter the value for insertion\n";
  cin>>val;
  if(tail==NULL){
    Node* temp=new Node(val);
    tail=temp;
    head=temp;
  }
  else{
    Node* temp=new Node(val);
    tail->next=temp;
    temp->prev=tail;
    tail=temp;
  }
}

void insertAtPosition(Node* &head , Node* &tail){
  int pos;
  cout<<"Enter the position for insertion\n";
  cin>>pos;

  if(pos==1){
    insertFirst(head , tail);
    return;
  }
  int cnt=1;
  Node* temp=head;
  while(cnt<pos-1)
  {
    temp=temp->next;
    cnt++;
  }

  if(temp->next==NULL){
    insertLast(tail , head);
    return;
  }
  int val;
  cout<<"Enter the value for insertion\n";
  cin>>val;
  Node* newNode=new Node(val);
  newNode->next=temp->next;
  temp->next->prev=newNode;
  temp->next=newNode;
  newNode->prev=temp;
}

void deleteNode(Node* &head){
  if(head==NULL){
    cout<<"Deletion not possible\n";
    return;
  }
  int pos;
  cout<<"Enter position for deletion\n";
  cin>>pos;

  if(pos==1){
    Node* temp=head;
    cout<<head->data<<" deleted\n";
    temp->next->prev=NULL;
    head=temp->next;
    temp->next=NULL;
    delete temp;
  }
  else{
    int cnt=1;
    Node* curr=head;
    Node* pre=NULL;
    while(cnt<pos){
      pre=curr;
      curr=curr->next;
      cnt++;
    }
    cout<<curr->data<<" deleted\n";
    curr->prev=NULL;
    pre->next=curr->next;
    curr->next=NULL;
    delete curr;
  }
}

void getLength(Node* &head){
  Node* temp=head;
  int len=0;
  while(temp!=NULL){
    len++;
    temp=temp->next;
  }
  cout<<"The length of list is: "<<len<<endl;
}

void print(Node* &head){
  if(head==NULL)
  {
    cout<<"List is empty\n";
  }
  else{
    Node* temp=head;
    while(temp!=NULL){
      cout<<temp->data<<" -> ";
      temp=temp->next;
    }cout<<endl;
  }
}

int main(){
  // int n;
  // cout<<"Enter the first value\n";
  // cin>>n;
  //Node* node=new Node(n);
  Node* head=NULL;
  Node* tail=NULL;

  while(1){
    cout<<"Enter 1 for insertFirst\n"<<"Enter 2 for insertLast\n"<<"Enter 3 for insertAtPosition\n"<<"Enter 4 for getLength\n"<<"Enter 5 for print\n"<<"Enter 6 for delete node\n"<<"Enter 7 for exit\n";
    int ch;
    cin>>ch;
    switch(ch){
      case 1: insertFirst(head , tail);
      break;
      case 2: insertLast(tail , head);
      break;
      case 3: insertAtPosition(head , tail);
      break;
      case 4: getLength(head);
      break;
      case 5: print(head);
      break;
      case 6: deleteNode(head);
      break;
      case 7: exit(0);
      break;
      default: cout<<"Enter valid option\n";
    }
  }
  return 0;
}
