
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	struct node *next;
	int data;
}N;
void insert(N* head,  N* node )
{
    N* temp = head;
    while(temp->next!=NULL && temp->next->data < node->data)
    {
        temp  = temp->next;
    }
    node->next = temp->next;
    temp->next = node;
}

N* insertionSortList(N* head) {
     N* temp = NULL;

    N* newhead = (N*)malloc(sizeof(N));
		newhead->data = -1;
		newhead->next = NULL;

    while(head!=NULL)
    {
        temp = head;
        head = head->next;
        temp->next = NULL;
        insert(newhead, temp);
    }
    return newhead->next;
}

N* CREATE(N *start){
	N *new,*t;
	new=(N*)malloc(sizeof(N));
	printf("Enter your data\n");
	scanf("%d",&new->data);
	new->next=NULL;
	if(start==NULL){
		start=new;
	}
	else{
		t=start;
		while(t->next!=NULL){
			t=t->next;
		}
		t->next=new;
	}
	return(start);
}
void DISPLAY(N *start){
	if(start==NULL){
		printf("Empty List\n");
	}
	else{
		while(start!=NULL){
			printf("%d ",start->data);
			start=start->next;
		}printf("\n");
	}
}

int main(){
	N *start=NULL;
	int ch;
	while(1){
		printf("1.CREATE\n2.DISPLAY\n3.insertionSortList\n4.EXIT\nEnter your choice\n");
		scanf("%d",&ch);
		switch(ch){
			case 1:start=CREATE(start);break;
			case 2:DISPLAY(start);break;
			case 3:start=insertionSortList(start);break;
      case 4:exit(1);
			default: printf("Enter a valid option\n");
		}
	}
	return 0;
}
