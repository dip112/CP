#include<iostream>
#include <bits/stdc++.h>
using namespace std;
string reverseWords(string s)
    {
        int k=0;
        for(int i=0;i<s.size();++i)
        {
            if(s[i]==' ')
            {
              reverse(s.begin()+k , s.begin()+i);
              k=i+1;
            }
        }
        reverse(s.begin()+k , s.end());
        return s;
  }

int main()
{
  string s= "Let's take LeetCode contest";

  string ans=reverseWords(s);

  for(int i=0;i<s.size();i++)
  {
    cout<<ans[i];
  }
  cout<<endl;
  return 0;
}
