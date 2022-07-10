#include<iostream>
#include<vector>
using namespace std;
vector<int> shortestToChar(string s, char c)
{
  vector<int>ans , pos;

  for(int i=0;i<s.size();i++)
  {
    if(s[i]==c)
    {
      pos.push_back(i);
    }
  }

  for(int i=0;i<s.size();i++)
  {
    int Min=INT_MAX;
    for(int j=0;j<pos.size();j++)
    {
      Min=min(Min , abs(pos[j]-i));
    }
    ans.push_back(Min);
  }
  return ans;
}
int main()
{
  string s="loveleetcode";
  char c='c';
  vector<int>ans;
  ans=shortestToChar(s , c);
  for(auto i:ans)
  {
    cout<<i<<" ";
  }
  cout<<endl;
  return 0;
}
