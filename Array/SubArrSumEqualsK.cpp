//https://leetcode.com/problems/subarray-sum-equals-k/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int , int>m;
        
        int sum=0 , ans=0;
        m[sum]=1;
        
        for(auto it:nums){
            sum+=it;
            
            int rest=sum-k;
            if(m.find(rest)!=m.end()){
                ans+=m[rest];
            }
            m[sum]++;
        }
        return ans;
    }
};
