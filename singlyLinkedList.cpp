#include<bits/stdc++.h>
using namespace std;

class Node{
public:
  int data;
  Node* next;

  Node(int data)
  {
    this->data=data;
    this->next=NULL;
  }
  ~Node()
  {
    if(this->next!=NULL)
    {
      delete next;
      //this->next=NULL;
    }
  }
};

void print(Node* &head)
{
  Node* temp=head;
  if(head==NULL)
  {
    cout<<"List is empty\n";
  }
  while(temp!=NULL)
  {
    cout<<temp->data<<" ";
    temp=temp->next;
  }cout<<endl;
}

void insertFirst(Node* &head)
{
  int val;
  cout<<"Enter tha value \n";
  cin>>val;
  Node* temp=new Node(val);
  temp->next=head;
  head=temp;
}

void insertLast(Node* &tail)
{
  int val;
  cout<<"Enter the value\n";
  cin>>val;

  Node* temp=new Node(val);
  tail->next=temp;
  tail=temp;
}

void insertAtPosition(Node* &head , Node* &tail)
{
  int pos , val , cnt=1;
  cout<<"Enter the position for insertion\n";
  cin>>pos;

  //insert at first insert at position
  if(pos==1)
  {
    insertFirst(head);
    return;
  }

  Node* temp=head;
  while(cnt<pos-1)
  {
    temp=temp->next;
    cnt++;
  }

  //insert at last position
  if(temp->next==NULL)
  {
    insertLast(tail);
    return;
  }
  cout<<"Enter the value\n";
  cin>>val;
  Node* newNode=new Node(val);
  newNode->next=temp->next;
  temp->next=newNode;
}

void deleteNode(Node* &head)
{
  if(head==NULL)
  {
    cout<<"Deletion not possible\n";
    return;
  }
  int pos;
  cout<<"Enter the position for deletion\n";
  cin>>pos;

  if(pos==1)
  {
    Node* temp=head;
    cout<<head->data<<" deleted\n";
    head=head->next;
    temp->next=NULL;
    delete temp;
  }
  else
  {
      int cnt=1;
      Node* curr=head;
      Node* prev=NULL;
      while(cnt<pos)
      {
        prev=curr;
        curr=curr->next;
        cnt++;
      }
      cout<<curr->data<<" deleted\n";
      prev->next=curr->next;
      curr->next=NULL;
      delete curr;
  }
}

int main()
{
  int n;
  cout<<"Enter the first value\n";
  cin>>n;
  Node* node1=new Node(n);

  Node* head=node1;
  Node* tail=node1;

  while(1)
  {
    cout<<"Enter 1 for insertFirst\n"<<"Enter 2 for insertLast\n"<<"Enter 3 for insertAtPosition\n"<<"Enter 4 for deleteNode\n"<<"Enter 5 for print\n"<<"Enter 6 for exit\n";
    int ch;
    cin>>ch;
    switch(ch)
    {
      case 1: insertFirst(head);
      break;
      case 2: insertLast(tail);
      break;
      case 3: insertAtPosition(head , tail);
      break;
      case 4:deleteNode(head);
      break;
      case 5: print(head);
      break;
      case 6: exit(0);
      break;
      defualt: cout<<"Enter valid option\n";
    }
  }

  return 0;
}
