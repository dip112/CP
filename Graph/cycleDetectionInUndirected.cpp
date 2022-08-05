//https://www.codingninjas.com/codestudio/problems/cycle-detection-in-undirected-graph_1062670?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
//using BFS
#include<bits/stdc++.h>
bool isCycleBFS(int node , unordered_map<int , list<int>>&adj , unordered_map<int , bool>&visited ,                                  unordered_map<int , int>&parent){
    parent[node]=-1;
    visited[node]=1;
    queue<int>q;
    q.push(node);
    
    while(!q.empty()){
        int front=q.front();
        q.pop();
        
        for(auto neighbour:adj[front]){
            if(visited[neighbour]==true && neighbour!=parent[front]){
                return 1;
            }
            else if(!visited[neighbour]){
                q.push(neighbour);
                visited[neighbour]=1;
                parent[neighbour]=front;
            }
        }
    }
    return 0;
}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    unordered_map<int , list<int>>adj;
    
    for(int i=0;i<m;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    unordered_map<int , bool>visited;
    unordered_map<int , int>parent;
    
    for(int i=0;i<n;i++){
        if(!visited[i]){
            bool ans=isCycleBFS(i , adj , visited , parent);
            if(ans==1){
                return "Yes";
            }
        }
    }
    return "No";
}

//Using DFS
bool isCycleDFS(int node , int parent , unordered_map<int , list<int>>&adj , unordered_map<int , bool>&visited){
    visited[node]=true;
    for(auto neighbour:adj[node]){
        if(!visited[neighbour]){
            bool isDetected=isCycleDFS(neighbour , node , adj , visited);
            if(isDetected){
                return true;
            }
        }
        else if(neighbour!=parent){
            return true;
        }
    }
    return false;
}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    unordered_map<int , list<int>>adj;
    
    for(int i=0;i<m;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    unordered_map<int , bool>visited;
    unordered_map<int , int>parent;
    
    for(int i=0;i<n;i++){
        if(!visited[i]){
            bool ans=isCycleDFS(i , -1 , adj , visited);
            if(ans==1){
                return "Yes";
            }
        }
    }
    return "No";
}
//time: O(V+E)
