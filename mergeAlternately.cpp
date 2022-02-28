//https://leetcode.com/problems/merge-strings-alternately/
class Solution {
public:
    string mergeAlternately(string word1, string word2) 
    {
        string s;
        
        int i=0 , j=0;
        
        while(i<word1.size() && j<word2.size())
        {
            s+=word1[i];
            s+=word2[j];
            i++;
            j++;
        }
        for(int k=i;k<word1.size();k++)
        {
            s+=word1[k];
        }
        for(int k=j;k<word2.size();k++)
        {
            s+=word2[k];
        }
        return s;
    }
};
