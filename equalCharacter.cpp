#include<iostream>
using namespace std;
bool areOccurrencesEqual(string s)
   {
       int arr[26]={0};

       for(auto c:s)
       {
           int index=c-'a';

           arr[index]++;
       }

       for(int i=1;i<s.size();i++)
       {
           int temp=arr[s[0]-'a'];
           int index=s[i]-'a';

           if(temp!=arr[index])
               return false;
           else
           {
               continue;
           }
       }
       return true;
   }

int main()
{
  string s="tveixwaeoezcf";

  cout<<"Result:"<< areOccurrencesEqual(s)<<endl;
  return 0;
}
