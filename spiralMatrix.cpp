//https://leetcode.com/problems/spiral-matrix-ii/
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        vector<vector<int>>ans (n , vector<int>(n ,0));
        
        int count=0;
        int total=n*n;
        
        int sRow=0 , sCol=0;
        int eRow=n-1 , eCol=n-1;
        
        int j=1;
        
        while(sRow<=eRow && sCol<=eCol){
            for(int i=sCol ; count<total && i<=eCol ; i++){
                ans[sRow][i]=j;
                count++;
                j++;
            }
            sRow++;
            
            for(int i=sRow ; count<total && i<=eRow ; i++){
                ans[i][eCol]=j;
                j++;
            }
            eCol--;
            
            for(int i=eCol ; count<total && i>=sCol ; i--){
                ans[eRow][i]=j;
                j++;
            }
            eRow--;
            
            for(int i=eRow ; count<total && i>=sRow ; i--){
                ans[i][sCol]=j;
                j++;
            }
            sCol++;
        }
        return ans;
    }
};
