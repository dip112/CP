//https://www.codingninjas.com/codestudio/problems/rat-in-a-maze_1215030?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
bool isSafe(int newX , int newY , vector<vector<bool>>vis , vector<vector<int>>arr , int n){
  //it is safe state if x and y in index range and path is not visited and it is a open path
    if((newX>=0 && newX<n) && (newY>=0 && newY<n) && vis[newX][newY]==0 && arr[newX][newY]==1){
        return 1;
    }
    else{
        return 0;
    }
}
void solve(int x , int y , int n ,vector<string>&ans , vector<vector<bool>>&vis , vector<vector<int>>&arr , string path){
  //reached destination  
  if(x==n-1 && y==n-1){
        ans.push_back(path);
        return;
    }
    //Down
    if(isSafe(x+1 , y , vis , arr , n)){
        //marked path as visited
        vis[x][y]=1;
        solve(x+1 , y , n , ans , vis , arr , path+'D');
        //when backtraked marked path as unvisited for other possible solution
        vis[x][y]=0;
    }
    //Left
    if(isSafe(x , y-1 , vis , arr , n)){
        vis[x][y]=1;
        solve(x , y-1 , n , ans , vis , arr , path+'L');
        vis[x][y]=0;
    }
    //Right
    if(isSafe(x , y+1 , vis , arr , n)){
        vis[x][y]=1;
        solve(x , y+1 , n , ans , vis , arr , path+'R');
        vis[x][y]=0;
    }
    //Up
    if(isSafe(x-1 , y , vis , arr , n)){
        vis[x][y]=1;
        solve(x-1 , y , n , ans , vis , arr , path+'U');
        vis[x][y]=0;
    }
}
vector < string > searchMaze(vector < vector < int >> & arr, int n) {
    vector<string>ans;
    vector<vector<bool>>visited(n,vector<bool>(n,0));
    string path="";
    
    if(arr[0][0]==0){
        return ans;
    }
    
    solve(0 , 0 , n , ans , visited , arr , path);
    return ans;
}
//Time: O(4^(n*n)) as 4 possible movement
//Space: O(n*n)
