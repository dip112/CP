//https://leetcode.com/problems/maximum-subarray/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {//Kadane's Algorithm
        int sum=0;
        int Max=INT_MIN;
        
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            Max=max(Max , sum);
            
            if(sum<0){
                sum=0;
            }
        }
        return Max;
    }
};
