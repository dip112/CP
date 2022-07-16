//https://practice.geeksforgeeks.org/problems/merge-two-binary-max-heap0144/1
class Solution{
    void heapifyAlgorithm(vector<int>&arr , int n , int i){
        int parent=i;
        int left=2*i+1;
        int right=2*i+2;
        
        if(n>left && arr[parent]<arr[left]){
            parent=left;
        }
        if(n>right && arr[parent]<arr[right]){
            parent=right;
        }
        
        if(parent!=i){
            swap(arr[i] , arr[parent]);
            heapifyAlgorithm(arr , n , parent);
        }
    }
    public:
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        vector<int>ans;
        for(auto i:a){
            ans.push_back(i);
        }
        for(auto i:b){
            ans.push_back(i);
        }
        int size=ans.size();
        
        for(int i=size/2-1;i>=0;i--){
            heapifyAlgorithm(ans , size , i);
        }
        return ans;
    }
};
