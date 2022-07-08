#include<bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/divide-a-string-into-groups-of-size-k/
vector<string> divideString(string s, int k, char fill) {
  vector<string>ans;
  int i=0;
  while(i<s.size()){
    string temp;
    int count=0;
    while(count<k && i<s.size()){
      temp+=s[i];
      i++;
      count++;
    }
    if(temp.size()==k){
      ans.push_back(temp);
      temp.clear();
    }
    else{
      int count=0;
      int n=k-temp.size();
      while(count<=n){
      temp+=fill;
      count++;
      }
      ans.push_back(temp);
    }
  }
  return ans;
}
int main(){
  string s="bgycymgbblobvpdf";
  vector<string>ans;
  ans=divideString(s , 67 , 'u');
  for(auto ch:ans){
    cout<<ch<<",";
  }cout<<endl;
  return 0;
}
