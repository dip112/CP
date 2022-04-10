//https://practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1/
//https://leetcode.com/problems/palindrome-linked-list/

//approach1

class Solution{
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        vector<int>v;
        
        Node* temp=head;
        
        while(temp!=NULL){
            v.push_back(temp->data);
            temp=temp->next;
        }
        
        int s=0 , e=v.size()-1;
        
        while(s<=e){
            if(v[s]!=v[e])
            {
                return 0;
            }
            s++;
            e--;
        }
        return 1;
    }
};
//time complexsity: O(n)
//space complexsity: O(n)

//approach2
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        
        if(head->next==NULL){
            return 1;
        }
        
        int num=0;
        
        ListNode* temp=head;
        
        while(temp!=NULL){
            num=num*10+temp->val;
            temp=temp->next;
        }
        
        int n=num;
        int sum=0;
        
        while(n){
            int digit=n%10;
            sum=sum*10+digit;
            n=n/10;
        }
        
        if(num==sum){
            return 1;
        }
        else{
            return 0;
        }
    }
};
//time complexsity: O(n)
//space complexsity: O(1)

//approach3
class Solution {
    ListNode* getMid(ListNode* head){
        
        ListNode* slow=head;
        ListNode* fast=head->next;
        
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
    
    ListNode* reverse(ListNode* head){
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* next=NULL;
        
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            
            prev=curr;
            curr=next;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        
        if(head->next==NULL){
            return 1;
        }
        
        ListNode* mid=getMid(head);
        
        ListNode* temp=mid->next;
        mid->next=reverse(temp);
        
        ListNode* head1=head;
        ListNode* head2=mid->next;
        
        while(head2!=NULL){
            if(head1->val!=head2->val){
                return 0;
            }
            head1=head1->next;
            head2=head2->next;
        }
        return 1;
    }
};
//time complexsity: O(n)
//space complexsity: O(1)
