//question link: https://leetcode.com/problems/matrix-diagonal-sum/

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat)
    {
        int row=mat.size();
        int col=mat[0].size();

        int i1 , i2 , j1 , j2;
        i1=j1=0;
        i2=0;
        j2=col-1;

        int mid=0 , sum=0;
        while(i1!=row && j1!=col || i2!=row && j2!=0)
        {
            sum+=mat[i1][j1]+mat[i2][j2];

            if(i1==i2 && j1==j2)
            {
                mid=mat[i1][j1];
            }
            i1++;
            j1++;
            i2++;
            j2--;
        }

        return sum-mid;
    }
};
