//https://www.codingninjas.com/codestudio/problems/nth-fibonacci-number_74156?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
//https://leetcode.com/problems/fibonacci-number/
//recursion+memoization
#include<bits/stdc++.h>
using namespace std;
int fibo(int n , vector<int>&dp){
    if(n<=1){
        return n;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    dp[n]=fibo(n-1 , dp)+fibo(n-2 , dp);
    return dp[n];
}
int main()
{
    int n;
    cin>>n;
    vector<int>dp(n+1);
    for(int i=0;i<=n;i++){
        dp[i]=-1;
    }
    cout<<fibo(n , dp)<<endl;
    return 0;
}
//Time: O(n)
//Space: O(n)+O(n)

//tabulation
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int>dp(n);
    dp[0]=0;
    dp[1]=1;
    
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    cout<<dp[n]<<endl;
    return 0;
}
//Time: O(n)
//Space: O(n)

class Solution {
public:
    int fib(int n) {
        if(n<=1){
            return n;
        }
        
        int prev1=0;
        int prev2=1;
        
        for(int i=2;i<=n;i++){
            int curr=prev1+prev2;
            prev1=prev2;
            prev2=curr;
        }
        return prev2;
    }
};
//Time: O(n)
//Space: O(1)
