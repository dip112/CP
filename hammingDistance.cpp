//https://leetcode.com/problems/hamming-distance/
class Solution {
public:
    int hammingDistance(int x, int y) 
    {
        int distance=0;
        int z=x^y;
        
        while(z)
        {
            if((z&1)==1)
                distance++;
            z=z>>1;
        }
        return distance;
    }
};
