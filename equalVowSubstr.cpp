//question link: https://leetcode.com/problems/determine-if-string-halves-are-alike/

class Solution {
    bool findVow(char ch)
    {
        string v="aeiou";
        if(v.find(ch)!=-1)
            return true;
        else
            return false;
    }
public:
    bool halvesAreAlike(string s)
    {
        for(int i=0;i<s.length();i++)
        {
            if(s[i]>='a' && s[i]<='z')
            {
                continue;
            }
            else
            {
                s[i]=s[i]+32;
            }
        }

        int n=s.length();
        int mid=n/2;

        int cnt_r=0 , cnt_l=0;

        for(int i=0;i<mid;i++)
        {
           if(findVow(s[i]))
               cnt_l++;
        }

        for(int i=mid;i<s.length();i++)
        {
            if(findVow(s[i]))
                cnt_r++;
        }
        if(cnt_l==cnt_r)
            return true;
        else
            return false;
    }
};
