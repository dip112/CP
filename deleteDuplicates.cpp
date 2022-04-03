//https://leetcode.com/problems/remove-duplicates-from-sorted-list/
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL){
            return NULL;
        }
        if(head->next==NULL){
            return head;
        }
        ListNode* temp=head;
        ListNode* forward=head->next;
        
        while(forward!=NULL){
            while(forward!=NULL && temp->val==forward->val  ){
                forward=forward->next;
            }
            if(forward==NULL){
                temp->next=forward;
            }
            else{
                temp->next=forward;
            }
            temp=forward;
            if(forward!=NULL){
                forward=forward->next;
            }
        }
        return head;
    }
};
