//question link: https://leetcode.com/problems/cells-with-odd-values-in-a-matrix/
//time complexsity: O(m*n);

class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices)
    {
        vector<vector<int>> vec( m , vector<int> (n , 0));

        int row=indices.size();

        for(int i=0;i<row;i++)
        {
            for(int j=0;j<n;j++)
            {
                vec[indices[i][0]][j]++;
            }
        }

        for(int i=0;i<row;i++)
        {
            for(int j=0;j<m;j++)
            {
                vec[j][indices[i][1]]++;
            }
        }

        int count=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(vec[i][j]%2!=0)
                {
                    count++;
                }
            }
        }
        return count;
    }
};
