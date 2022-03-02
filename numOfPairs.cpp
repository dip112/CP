//https://leetcode.com/problems/number-of-pairs-of-strings-with-concatenation-equal-to-target/
class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) 
    {
        int count=0;
        
        for(int i=0;i<nums.size()-1;i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[i]+nums[j]==target)
                    count++;
            }
        }
        for(int i=nums.size()-1;i>0;i--)
        {
            for(int j=i-1;j>=0;j--)
            {
                if((nums[i]+nums[j])==target)
                    count++;
            }
        }
        return count;
    }
};
