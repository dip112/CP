//https://leetcode.com/problems/sudoku-solver/
//https://www.codingninjas.com/codestudio/problems/sudoku-solver_699919?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
bool isSafe(int row , int col , vector<vector<int>>&board , int val){
    for(int i=0;i<board.size();i++){
        //check for row
        if(board[row][i]==val){
            return false;
        }
        //check for column
        if(board[i][col]==val){
            return false;
        }
        //check for sub-grids
        if(board[3*(row/3) + i/3][3*(col/3) + i%3]==val){
            return false;
        }
    }
    return true;
}
bool solve(vector<vector<int>>&board){
    int n=board[0].size();

    for(int row=0;row<n;row++){
        for(int col=0;col<n;col++){
            if(board[row][col]==0){
                for(int i=1;i<=9;i++){
                    if(isSafe(row , col , board , i)){
                        board[row][col]=i;
                        bool nextCall=solve(board);
                        if(nextCall){
                            return true;
                        }
                        else{
                            board[row][col]=0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}
void solveSudoku(vector<vector<int>>& sudoku)
{
	solve(sudoku);
}
