#include<iostream>
using namespace std;

//question link:https://leetcode.com/problems/minimum-time-to-type-word-using-special-typewriter/

int minTimeToType(string word)
    {
        int sec=0 , temp;

        temp=abs(word[0]-'a');
        cout<<"temp "<<temp<<endl;
        if(temp<=13)
        {
            sec+=temp;
            sec++;
        }
        else
        {
            sec+=(26-temp);
            sec++;
        }

        for(int i=0;i<word.size()-1;i++)
        {
            int temp=abs(word[i]-word[i+1]);
            if(temp<=13)
            {
                sec+=temp;
                sec++;
                cout<<"inside "<<sec<<endl;
            }
            if(temp>13)
            {
                sec+=(26-temp);
                sec++;
            }
        }
        return sec;
    }
int main()
{
  string word="bza";

  cout<<"Result "<<minTimeToType(word)<<endl;
  return 0;
}
