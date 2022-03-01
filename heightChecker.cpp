//https://leetcode.com/problems/height-checker/
class Solution {
public:
    int heightChecker(vector<int>& heights) 
    {
        vector<int>expected;
        
        for(auto i:heights)
        {
            expected.push_back(i);
        }
        sort(expected.begin() , expected.end());
        
        int i=0 , count=0;
        while(i<heights.size())
        {
            if(heights[i]!=expected[i])
                count++;
            i++;
        }
        return count;
    }
};
