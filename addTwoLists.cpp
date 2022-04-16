//https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1
//https://leetcode.com/problems/add-two-numbers-ii/
class Solution
{
    void insertAtTail(struct Node* &head , struct Node* &tail , int val){
        Node* temp=new Node(val);
        if(head==NULL){
            head=temp;
            tail=temp;
            return;
        }
        else{
            tail->next=temp;
            tail=temp;
        }
    }
    public:
    struct Node* reverse(struct Node* head){
        struct Node* curr=head;
        struct Node* prev=NULL;
        struct Node* next=NULL;
        
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            
            prev=curr;
            curr=next;
        }
        return prev;
    }
    struct Node* addNode(struct Node* first , struct Node* second){
        int carry=0;
        int sum=0;
        Node* ansHead=NULL;
        Node* ansTail=NULL;
        
        while(first!=NULL || second!=NULL || carry!=0){
            int val1=0;
            if(first!=NULL){
                val1=first->data;
            }
            int val2=0;
            if(second!=NULL){
                val2=second->data;
            }
            sum=carry+val1+val2;
            int digit=sum%10;
            carry=sum/10;
            
            insertAtTail(ansHead , ansTail , digit);
            
            if(first!=NULL){
                first=first->next;
            }
            if(second!=NULL){
                second=second->next;
            }
        }
        return ansHead;
    }
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        first=reverse(first);
        second=reverse(second);
        
        struct Node* ans=addNode(first , second);
        
        ans=reverse(ans);
        return ans;
    }
};
