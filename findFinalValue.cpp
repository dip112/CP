//https://leetcode.com/problems/keep-multiplying-found-values-by-two/
class Solution {
    bool Search(vector<int>&nums , int k)
    {
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==k)
                return 1;
            else
                continue;
        }
        return 0;
    }
public:
    int findFinalValue(vector<int>& nums, int original) 
    {
        
        if(Search(nums , original))
        {
            original*=2;
            return findFinalValue(nums , original);
        }
        return original;
    }
};
