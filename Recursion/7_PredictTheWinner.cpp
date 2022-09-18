//https://leetcode.com/problems/predict-the-winner/
class Solution {
    int solve(vector<int>&num , int i , int j){
        if(i>j){
            return 0;
        }
        
        if(i==j){
            return num[i];
        }
        int op1 = num[i] + min(solve(num , i+2 , j) , solve(num , i+1 , j-1));
        
        int op2 = num[j] + min(solve(num , i+1 , j-1) , solve(num , i , j-2));
        
        return max(op1 , op2);
    }
public:
    bool PredictTheWinner(vector<int>& nums) {
        int p1Score=solve(nums , 0 , nums.size()-1);
        
        int totalScore=0;
        for(int i=0;i<nums.size();i++){
            totalScore+=nums[i];
        }
        
        int p2Score=totalScore-p1Score;
        
        if(p1Score>=p2Score){
            return true;
        }
        return false;
    }
};
