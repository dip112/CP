//https://www.codingninjas.com/codestudio/problems/remove-duplicates-from-unsorted-linked-list_1069331?source=youtube&campaign=YouTube_Lovebabbar29thJan&utm_source=youtube&utm_medium=affiliate&utm_campaign=YouTube_Lovebabbar29thJan&leftPanelTab=0
//approach 1

Node *removeDuplicates(Node *head)
{
    if(head==NULL){
		return NULL;
	}
	if(head->next==NULL){
		return head;
	}
	
	Node * curr=head;
	
	while(curr!=NULL){
		Node* temp=curr->next;
		Node* backward=curr;
		while(temp!=NULL){
			if(curr->data==temp->data){
				Node* nodeToDelete=temp;
				backward->next=temp->next;
				temp=backward->next;
				delete(nodeToDelete);
			}
			else{
				backward=temp;
				temp=temp->next;
			}
		}
		curr=curr->next;
	}
	return head;
}
//time complexsity: O(n^2)
//space complexsity: O(1)

//approach2

Node *removeDuplicates(Node *head)
{
    if(head==NULL || head->next==NULL){
		return head;
	}
	map<int , bool>visited;
	
	Node*  curr=head;
	Node* prev=NULL;
	
	while(curr!=NULL){
		if(visited[curr->data]==true){
			prev->next=curr->next;
			//delete(curr);
		}
		else{
			visited[curr->data]=true;
			prev=curr;
		}
		curr=curr->next;
	}
	return head;
}
//time complexsity: O(n)
//space complexsity: O(n)
