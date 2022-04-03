class Solution {
public:
    //https://leetcode.com/problems/add-binary/
    string addBinary(string a, string b) {

        int i=a.size()-1 , j=b.size()-1;

        string ans;

        int carry=0;

        while(i>=0 && j>=0){
            if((a[i]=='0' && b[j]=='1') || (a[i]=='1' && b[j]=='0')){
                if(carry!=1){
                    ans+='1';
                    i--;
                    j--;
                }
                else{
                    ans+='0';
                    carry=1;
                    i--;
                    j--;
                }
            }
            else if(a[i]=='0' && b[j]=='0'){
                if(carry!=1){
                    ans+='0';
                    i--;
                    j--;
                }
                else{
                    ans+='1';
                    carry=0;
                    i--;
                    j--;
                }
            }
            else{
                if(carry!=1){
                    ans+='0';
                    carry=1;
                    i--;
                    j--;
                }
                else{
                    ans+='1';
                    carry=1;
                    i--;
                    j--;
                }
            }
        }
        if(i==-1 && j==-1 && carry==1){
          ans+='1';
        }
        if(i>=0 && j==-1){
            while(i>=0){
                if(carry!=1){
                    ans+=a[i];
                    i--;
                }
                else{
                    if(a[i]=='0'){
                        ans+='1';
                        carry=0;
                        i--;
                    }
                    else{
                        ans+='0';
                        carry=1;
                        i--;
                    }
                }
            }
            if(carry==1){
              ans+='1';
            }
        }
        if(i==-1 && j>=0){
            while(j>=0){
                if(carry!=1){
                    ans+=b[j];
                    j--;
                }
                else{
                    if(b[j]=='0'){
                        ans+='1';
                        carry=0;
                        j--;
                    }
                    else{
                        ans+='0';
                        carry=1;
                        j--;
                    }
                }
            }
            if(carry==1){
              ans+='1';
            }

        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
};
