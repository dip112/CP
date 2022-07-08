//https://www.codingninjas.com/codestudio/problems/interview-shuriken-42-detect-and-remove-loop_241049?leftPanelTab=0?source=youtube&campaign=YouTube_codestudio_lovebabbar28thjan&utm_source=youtube&utm_medium=affiliate&utm_campaign=YouTube_codestudio_lovebabbar28thjan

Node* floydDetectLoop(Node* head){
  if(head==NULL){
    return NULL;
  }
  Node* fast=head;
  Node* slow=head;

  while(slow!=NULL && fast!=NULL){
    fast=fast->next;
    if(fast!=NULL){
      fast=fast->next;
    }
    slow=slow->next;
    if(slow==fast){
      return slow;
    }
  }
  return NULL;
}

Node* getStartOfLoop(Node* head){
  if(head==NULL){
    return NULL;
  }
  Node* intersection=floydDetectLoop(head);
    if(intersection==NULL){
        return NULL;
	}
  Node* slow=head;

  while(slow!=intersection){
    slow=slow->next;
    intersection=intersection->next;
  }
  return slow;
}

Node* removeLoop(Node* head){
  if(head==NULL){
    return NULL;
  }

  Node* startOfLoop=getStartOfLoop(head);
  if(startOfLoop==NULL){
      return head;
  }
  Node* temp=startOfLoop;

  while(temp->next!=startOfLoop){
    temp=temp->next;
  }
  temp->next=NULL;
  return head;
}
