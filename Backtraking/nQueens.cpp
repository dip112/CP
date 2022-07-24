//https://www.codingninjas.com/codestudio/problems/the-n-queens-puzzle_981286?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
//https://leetcode.com/problems/n-queens/
void addAns(vector<vector<int>>&board , vector<vector<int>>&ans , int n){
    vector<int>temp;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            temp.push_back(board[i][j]);
        }
    }
    ans.push_back(temp);
}
bool isSafe(int row , int col , vector<vector<int>>&board , int n){
    int x=row;
    int y=col;
    //leftward
    while(y>=0){
        if(board[x][y]==1){
            return 0;
        }
        y--;
    }
    //up diagonal
    x=row;
    y=col;
    while(x>=0 && y>=0){
        if(board[x][y]==1){
            return 0;
        }
        x--;
        y--;
    }
    //down diagonal
    x=row;
    y=col;
    while(x<n && y>=0){
        if(board[x][y]==1){
            return 0;
        }
        x++;
        y--;
    }
    return 1;
}
void solve(int col , int n , vector<vector<int>>&board , vector<vector<int>>&ans){
    if(col==n){
        addAns(board , ans , n);
        return;
    }
    for(int row=0;row<n;row++){
        if(isSafe(row , col , board , n)){
            board[row][col]=1;
            solve(col+1 , n , board , ans);
            board[row][col]=0;
        }
    }
}
vector<vector<int>> nQueens(int n)
{
	vector<vector<int>>board(n , vector<int>(n , 0));
    vector<vector<int>>ans;
    solve(0 , n , board , ans);
    
	return ans;
}

//leetcode
class Solution {
    void addAns(int n , vector<vector<char>>&board , vector<vector<string>>&ans){
        vector<string>temp;
        string s="";
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                s+=board[i][j];
            }
            temp.push_back(s);
            s.clear();
        }
        ans.push_back(temp);
    }
    bool isSafe(int row , int col , vector<vector<char>>&board , int n){
        int x=row;
        int y=col;
        
        while(y>=0){
            if(board[x][y]=='Q'){
                return 0;
            }
            y--;
        }
        
        x=row;
        y=col;

        while(x>=0 && y>=0){
            if(board[x][y]=='Q'){
                return 0;
            }
            x--;
            y--;
        }
        
        x=row;
        y=col;
        
        while(x<n && y>=0){
            if(board[x][y]=='Q'){
                return 0;
            }
            x++;
            y--;
        }
        return 1;
    }
    void solve(int col , int n , vector<vector<char>>&board , vector<vector<string>>&ans){
        if(col==n){
            addAns(n , board , ans);
            return;
        }
        for(int row=0;row<n;row++){
            if(isSafe(row , col , board , n)){
                board[row][col]='Q';
                solve(col+1 , n , board , ans);
                board[row][col]='.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>>board(n , vector<char>(n,'.'));
        vector<vector<string>>ans;
        
        solve(0 , n , board , ans);
        return ans;
    }
};

//Time: O(n!)
//Space: O(n*n)
