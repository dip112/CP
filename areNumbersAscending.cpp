#include<iostream>
#include<vector>
using namespace std;
bool areNumbersAscending(string s)
{
  vector<int>v;

  for(int i=0; i<s.size(); i++)
  {
    int flag=0;
    int num = 0;
    while(s[i]>='0' && s[i]<='9')
    {
      num = num*10+(s[i]-'0');
      i++;
      flag=1;
    }
    if(flag==1)
    {
      v.push_back(num);
    }

  }

  for(int i=0;i<v.size()-1;i++)
  {
    if(v[i]<v[i+1])
      continue;
    else
      return 0;
  }
  return 1;
}
int main()
{
  string s="1 box has 3 blue 4 red 6 green and 12 yellow marbles";

  cout<<areNumbersAscending(s)<<endl;
  return 0;
}
