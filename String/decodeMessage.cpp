//https://leetcode.com/problems/decode-the-message/
class Solution {
public:
    string decodeMessage(string key, string msg) {
        unordered_map<char , char>m;
        int j=0;
        for(int i=0;i<key.size();i++){
            if(key[i]==' '){
                continue;
            }
            if(m.find(key[i])==m.end()){
                m[key[i]]='a'+j;
                j++;
            }
            
        }
        
        string ans="";
        for(auto c:msg){
            if(c==' '){
                ans+=' ';
            }
            else{
                ans+=m[c];
            }
        }
        return ans;
    }
};
