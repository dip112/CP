//https://leetcode.com/problems/is-subsequence/
class Solution {
    int solve(string s , string t , int i , int j){
        if(i>=s.size() || j>=t.size()){
            return 0;
        }
        if(s[i]==t[j]){
            return 1+solve(s , t , i+1 , j+1);
        }
        else{
            return solve(s , t , i , j+1);
        }
    }
public:
    bool isSubsequence(string s, string t) {
        int ans=solve(s , t , 0 , 0);
        
        if(ans==s.size()){
            return true;
        }
        return false;
    }
};
