#include<iostream>
using namespace std;
//https://leetcode.com/problems/maximum-number-of-words-you-can-type/
bool find(string word , string br)
{
  for(int i=0;i<br.size();i++)
  {
    if(word.find(br[i])!=string::npos)
    {
      return 1;
    }
  }
  return 0;
}
int canBeTypedWords(string text, string brokenLetters)
{
  int type=0;

  string temp="";

  for(int i=0;i<=text.size();i++)
  {
    if(text[i]!=' ' && i!=text.size())
    {
      temp+=text[i];
    }

    else
    {
      if(find(temp , brokenLetters)==0)
      {
        type++;
      }
      temp.clear();
    }
  }
  return type;
}
int main()
{
  string text="leet code";
  cout<<text.size()<<endl;
  string b="lt";
  cout<<"result "<<canBeTypedWords(text , b)<<endl;
  return 0;
}
