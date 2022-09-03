//https://leetcode.com/problems/add-strings/
class Solution {
    void addStr(string a , string b , int carry , string& ans , int i , int j){
        if(i<0 && j<0 && carry==0){
            return;
        }
        int first=0;
        int second=0;
        
        if(i>=0){
            first=a[i]-'0';
        }
        if(j>=0){
            second=b[j]-'0';
        }
        
        int sum=first+second+carry;
        int lastDigit=sum%10;
        carry=sum/10;
        ans.push_back(lastDigit+'0');
        
        addStr(a , b , carry , ans , i-1 , j-1);
    }
public:
    string addStrings(string num1, string num2) {
        string ans="";
        
        addStr(num1 , num2 , 0 , ans , num1.size()-1 , num2.size()-1);
        
        reverse(ans.begin() , ans.end());
        
        return ans;
    }
};
