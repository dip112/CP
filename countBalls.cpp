//https://leetcode.com/problems/maximum-number-of-balls-in-a-box/
class Solution {
public:
    int countBalls(int lowLimit, int highLimit) 
    {
        map<int , int>m;
        
        for(int i=lowLimit;i<=highLimit;i++)
        {
            int sum=0;
            int j=i;
            while(j)
            {
                int digit=j%10;
                sum+=digit;
                j=j/10;
            }
            m[sum]++;
        }
        int Max=0;
        for(auto i:m)
        {
            Max=max(Max , i.second);
        }
        return Max;
    }
};
