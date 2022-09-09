//https://leetcode.com/problems/climbing-stairs/
//https://www.codingninjas.com/codestudio/problems/count-ways-to-reach-nth-stairs_798650?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
//memoization
class Solution {
    int solve(int n , int i , vector<int>&dp){
        if(i==n){
            return 1;
        }
        if(i>n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        dp[i]=(solve(n , i+1 , dp)+solve(n , i+2 , dp));
        return dp[i];
    }
public:
    int climbStairs(int n) {
        vector<int>dp(n+1 , -1);
        return solve(n , 0 , dp);
    }
};
//Time: O(N)
//Space: O(N)+O(N)

//space optimization
class Solution {
public:
     int climbStairs(int n) {
        if (n <= 2) {
            return n;
        }
        int prev = 2, prev2 = 1, res;
         
        for (int i = 3; i <= n; i++) {
            
            res = prev + prev2;
            prev2 = prev;
            prev = res;
        }
        return res;
    }
};
//Time: O(N)
//Space: O(1)
