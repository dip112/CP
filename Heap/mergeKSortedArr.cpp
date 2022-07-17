//https://www.codingninjas.com/codestudio/problems/merge-k-sorted-arrays_975379?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
//https://practice.geeksforgeeks.org/problems/merge-k-sorted-arrays/1
//approach1
#include<bits/stdc++.h>
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{

    vector<int> ans;
    for(auto &array :kArrays){
        ans.insert(ans.end(), array.begin(), array.end());
    }
    sort(ans.begin(), ans.end());
    return ans;
}
//Time: O(n*k*log(n*k)
//Space: O(n*k)

//approach2
#include<bits/stdc++.h>
vector<int> mergeKSortedArrays(vector<vector<int>>&arr, int k)
{
    vector<int>ans;
    priority_queue<int , vector<int> , greater<int>>pq;
    
    for(int i=0;i<k;i++){
        for(int j=0;j<arr[i].size();j++){
            pq.push(arr[i][j]);
        }
    }
    while(pq.size()>0){
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}
//Time: O(n*k)
//Space: O(n*k)
