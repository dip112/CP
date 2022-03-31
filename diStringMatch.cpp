//https://leetcode.com/problems/di-string-match/
class Solution {
public:
    vector<int> diStringMatch(string s) {
        
        vector<int>ans;
        
        int n=s.length();
        
        int start=0 , end=n;
        
        for(auto c:s){
            if(c=='I'){
                ans.push_back(start);
                start++;
            }
            else{
                ans.push_back(end);
                end--;
            }
        }
        ans.push_back(start);
        return ans;
    }
};
