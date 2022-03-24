#include<bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/delete-columns-to-make-sorted/
int minDeletionSize(vector<string>& strs)
    {
        vector<string>temp;

        int i=0 , count=0;
        while(i<strs[0].size())
        {
            string strTemp;
            for(auto ch:strs)
            {
                strTemp+=ch[i];
            }
            temp.push_back(strTemp);
            strTemp.clear();
            i++;
        }

        for(auto ch:temp)
        {
            for(int i=0;i<ch.size()-1;i++)
            {
                if(ch[i]<=ch[i+1])
                    continue;
                else
                {
                   count++;
                    break;
                }
            }
        }
        return count;
    }
int main()
{
  vector<string>strs{"rrjk","furt","guzm"};

  cout<<"Result: "<<minDeletionSize(strs)<<endl;
  return 0;

}
