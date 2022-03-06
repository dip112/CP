#include<iostream>
#include<vector>
using namespace std;
//https://leetcode.com/contest/weekly-contest-283/problems/cells-in-a-range-on-an-excel-sheet/
vector<string> cellsInRange(string s)
{
  vector<string>v;

  int col=abs(s[0]-s[3]);

  int row1 , row2;

  row1=s[1]-'0';
  row2=s[4]-'0';
  int k=0;
  for(int i=0;i<=col;i++)
  {
    string temp="";
    for(int j=row1;j<=row2;j++)
    {
      char c=s[0]+k;
      temp+=c;
      temp+=j+'0';
      v.push_back(temp);
      temp.clear();
    }
    k++;
  }
  return v;
}
int main()
{
  string s="U7:X9";
  vector<string>res;
  res=cellsInRange(s);
  for(auto i:res)
  {
    cout<<i<<" ";
  }
  cout<<endl;
  return 0;
}
