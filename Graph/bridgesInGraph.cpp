//https://www.codingninjas.com/codestudio/problems/bridges-in-graph_893026?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
#include<bits/stdc++.h>
void dfs(int node , int parent , int &timer , vector<int>&disc , vector<int>&low , 
         unordered_map<int , list<int>>&adj , vector<vector<int>>&result , unordered_map<int , bool>&visited){
    visited[node]=true;
    
    //set discover and low array with timer value and then increase timer 
    disc[node]=low[node]=timer++;
    
    for(auto neighbour:adj[node]){
        //if neighbour is same as parent then ignore
        if(neighbour==parent){
            continue;
        }
        if(!visited[neighbour]){
            dfs(neighbour , node , timer , disc , low , adj , result , visited);
            //when return back to parent node update parent nodes low array
            low[node]=min(low[node] , low[neighbour]);
            //check if it is bridge or not
            if(low[neighbour]>disc[node]){
                vector<int>ans;
                ans.push_back(node);
                ans.push_back(neighbour);
                result.push_back(ans);
            }
        }
        //if back edges present
        else{
            low[node]=min(low[node] , disc[neighbour]);
        }
    }
}
vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    unordered_map<int , list<int>>adj;
    //create adjacency list
    for(int i=0;i<e;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<int>disc(v , -1);
    vector<int>low(v , -1);
    
    int parent=-1;
    unordered_map<int , bool>visited;
    int timer=0;
    
    vector<vector<int>>result;
    
    //call dfs
    for(int i=0;i<v;i++){
        if(!visited[i]){
            dfs(i , parent , timer , disc , low , adj , result , visited);
        }
    }
    return result;
}

//Time: O(V+E)
//Space: (V)
