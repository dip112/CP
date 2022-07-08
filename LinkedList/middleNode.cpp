//https://leetcode.com/problems/middle-of-the-linked-list/
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        
        //if(head==NULL)
        
        int len=0;
        
        ListNode* temp=head;
        
        while(temp!=NULL){
            len++;
            temp=temp->next;
        }
        ListNode* curr=head;
        
        int cnt1=1;
        len=(len/2);
        while(cnt1<=len){
            curr=curr->next;
            cnt1++;
        }
        head=curr;
        return head;
    }
};
