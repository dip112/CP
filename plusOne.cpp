#include<bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/plus-one/
vector<int> plusOne(vector<int>& digits) {

        // int n=digits.size()-1;
        //
        // if(digits[n]==9){
        //     if(digits[n-1]<9){
        //         digits[n]=1;
        //         digits.push_back(0);
        //     }
        //     else{
        //         while(digits[n]==9 && n>=0){
        //             digits[n]=0;
        //             n--;
        //         }
        //         if(n<0){
        //             digits.push_back(0);
        //             int m=digits.size()-1;
        //             for(int i=m;i>0;i--){
        //                 digits[i]=digits[i-1];
        //             }
        //             digits[0]=1;
        //         }
        //         else{
        //             digits[n]++;
        //         }
        //     }
        // }
        //
        // else{
        //     digits[n]++;
        // }
        //return digits;

//  ------------------------------------------------------------------------
        //         long long int num=0;
//         vector<int>ans;

//         for(auto i:digits){
//             num=num*10+i;
//         }

//         num+=1;
//         while(num){
//             int digit=num%10;
//             ans.push_back(digit);
//             num=num/10;
//         }

//         int s=0 , e=ans.size()-1;
//         while(s<=e){
//             swap(ans[s] , ans[e]);
//             s++;
//             e--;
//         }
//         return ans;
//----------------------------------------------------------------------------
  int n=digits.size()-1;

  for(int i=n;i>=0;i--){

    if(digits[i]==9){

      digits[i]=0;
    }

    else{

      digits[i]++;

      return digits;
    }
  }

  digits.push_back(0);

  digits[0]=1;

  return digits;
}
int main(){
  vector<int>v{9,9};
  vector<int>ans;
  ans=plusOne(v);
  for(auto i:ans){
    cout<<i<<" ";
  }cout<<endl;
  return 0;
}
