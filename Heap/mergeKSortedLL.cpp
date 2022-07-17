//https://www.codingninjas.com/codestudio/problems/merge-k-sorted-lists_992772?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
//https://leetcode.com/problems/merge-k-sorted-lists/
//https://practice.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1
class compare{
    public:
    bool operator()(Node<int>*a , Node<int>*b){
        return a->data>b->data;
    }
};
Node<int>* mergeKLists(vector<Node<int>*> &arr)
{
    priority_queue<Node<int>* , vector<Node<int>*> , compare>pq;
    int k=arr.size();
    
    if(k==0){
        return NULL;
    }
    for(int i=0;i<k;i++){
        if(arr[i]!=NULL){
            pq.push(arr[i]);
        }
    }
    Node<int>*head=NULL;
    Node<int>*tail=NULL;
    
    while(pq.size()>0){
        Node<int>*temp=pq.top();
        pq.pop();
        if(temp->next!=NULL){
            pq.push(temp->next);
        }
        if(head==NULL){
            head=temp;
            tail=temp;
        }
        else{
            tail->next=temp;
            tail=temp;
        }
    }
    return head;
}
//Time:O(n*klog(k))
//Space: O(k)
