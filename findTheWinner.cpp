//https://leetcode.com/problems/find-the-winner-of-the-circular-game/
#include<iostream>
#include<vector>
using namespace std;
int findTheWinner(int n, int k)
   {
       vector<int> v;

       for(int i=1;i<=n;i++)
       {
           v.push_back(i);
       }

       int i=0;
       while(v.size()>1)
       {
           int n=v.size();
           i=(i+k-1)%n;
           v.erase(v.begin()+i);
       }
       int res=0;
       if(v.size()==1)
       {
         res=v[0];
       }
       return res;
   }
int main()
{
  int n , k;
  cout<<"ENter the value of n and k\n";
  cin>>n>>k;

  cout<<"Result: "<<findTheWinner(n , k)<<endl;
  return 0;
}
