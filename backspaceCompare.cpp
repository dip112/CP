//https://leetcode.com/problems/backspace-string-compare/
//approach1
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string temp1="" , temp2="";
        
        for(auto c:s){
            if(c=='#' && !temp1.empty()){
                temp1.pop_back();
            }
            else if(c!='#'){
                temp1.push_back(c);
            }
        }
        for(auto c:t){
            if(c=='#' && !temp2.empty()){
                temp2.pop_back();
            }
            else if(c!='#'){
                temp2.push_back(c);
            }
        }
        
        int i=0 , j=0;
        
        if(temp1.size()!=temp2.size()){
            return 0;
        }
        
        while(i<temp1.size() && j<temp2.size()){
            if(temp1[i]!=temp2[j]){
                return 0;
            }
            i++;
            j++;
        }
        return 1;
    }
};
//TC:O(n)
//SP:O(n+m)

//approach2
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int index1=0;
        
        for(int i=0;i<s.size();i++){
            if(s[i]=='#'){
                if(index1>0){
                    index1--;
                }
            }
            else{
                s[index1++]=s[i];
            }
        }
        
        int index2=0;
        
        for(int i=0;i<t.size();i++){
            if(t[i]=='#'){
                if(index2>0){
                    index2--;
                }
            }
            else{
                t[index2++]=t[i];
            }
        }
        if(index1!=index2){
            return 0;
        }
        
        for(int i=0;i<index1;i++){
            if(s[i]!=t[i]){
                return 0;
            }
        }
        return 1;
    }
};
//TC:O(n)
//SP:O(1)
