//https://leetcode.com/problems/counting-bits/
class Solution {
public:
    vector<int> countBits(int n) 
    {
        vector<int>v;
        
        for(int i=0;i<=n;i++)
        {
            int count=0;
            int j=i;
            
            while(j!=0)
            {
                if((j&1)==1)
                    count++;
                j=j>>1;
            }
            v.push_back(count);
        }
        return v;
    }
};
