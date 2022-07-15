//https://leetcode.com/problems/kth-largest-element-in-an-array/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        priority_queue<int>pq;
        
        for(auto i:nums){
            pq.push(i);
        }
        
        int count=0 , ele;
        
        while(count<k){
            ele=pq.top();
            pq.pop();
            count++;
        }
        return ele;
    }
};
