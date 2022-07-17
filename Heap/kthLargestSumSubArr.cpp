//https://www.codingninjas.com/codestudio/problems/k-th-largest-sum-contiguous-subarray_920398?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
//https://practice.geeksforgeeks.org/problems/k-th-largest-sum-contiguous-subarray/1
//approach1
class Solution{
public:
    int kthLargest(vector<int> &arr,int N,int K){
        vector<int>sumStore;
    
        for(int i=0;i<N;i++){
            int sum=0;
            for(int j=i;j<N;j++){
                sum+=arr[j];
                sumStore.push_back(sum);
            }
        }
        
        sort(sumStore.begin() , sumStore.end());
        
        return sumStore[sumStore.size()-K];
    }
};
//Time: O(n^2)
//Space: O(n^2)

//approach2
class Solution{
public:
    int kthLargest(vector<int> &arr,int n,int k){
        priority_queue<int , vector<int> , greater<int>>pq;
        
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=arr[j];
                
                if(pq.size()<k){
                    pq.push(sum);
                }
                else{
                    if(sum>pq.top()){
                        pq.pop();
                        pq.push(sum);
                    }
                }
            }
        }
        return pq.top();
    }
};
//Time: O(n^2)
//Space: O(k)
