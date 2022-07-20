//https://leetcode.com/problems/maximum-number-of-pairs-in-array/
class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        vector<int>ans(2);
        int n=nums.size();
        
        unordered_map<int ,int>m;
        
        for(auto i:nums){
            m[i]++;
        }
        
        int sum=0;
        
        for(auto it:m){
            sum+=it.second/2;
        }
        
        ans[0]=sum;
        ans[1]=n-(sum*2);
        return ans;
    }
};
