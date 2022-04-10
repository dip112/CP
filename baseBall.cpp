#include<bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/baseball-game/
int calPoints(vector<string>& ops) {
        vector<int>v;
        int i=-1;
        for(int j=0;j<ops.size();j++){
            if(ops[j]=="C" && !v.empty()){
                v.pop_back();
                i--;
            }
            else if(ops[j]=="D" && !v.empty()){
                int temp=v[i]*2;
                v.push_back(temp);
                i++;
            }
            else if(ops[j]=="+"){
                int sum=v[i]+v[i-1];
                v.push_back(sum);
                i++;
            }
            else{
                int temp=stoi(ops[j]);
                v.push_back(temp);
                i++;
            }
        }
        int ans=0;
        for(auto i:v){
            ans+=i;
        }
        return ans;
    }
int main(){
  vector<string>ops{"5","-2","4","C","D","9","+","+"};
  cout<<"Ans: "<<calPoints(ops)<<endl;
  return 0;
}
