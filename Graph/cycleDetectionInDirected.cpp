//https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
//https://www.codingninjas.com/codestudio/problems/detect-cycle-in-a-directed-graph_1062626?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
#include<bits/stdc++.h>
bool cycleDetectDFS(int node , unordered_map<int , bool>&visited , unordered_map<int , bool>&dfsVisited ,                              unordered_map<int , list<int>>&adj){
    visited[node]=1;
    dfsVisited[node]=1;
    
    for(auto neighbour:adj[node]){
        if(!visited[neighbour]){
            bool cycleDetected=cycleDetectDFS(neighbour , visited , dfsVisited , adj);
            if(cycleDetected){
                return true;
            }
        }
        else if(dfsVisited[neighbour]){
            return true;
        }
    }
    dfsVisited[node]=0;
    return false;
}
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    unordered_map<int , list<int>>adj;
    
    for(int i=0;i<edges.size();i++){
        int u=edges[i].first;
        int v=edges[i].second;
        
        adj[u].push_back(v);
    }
    
    unordered_map<int , bool>visited;
    unordered_map<int , bool>dfsVisited;
    
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            bool cycleDetected=cycleDetectDFS(i , visited , dfsVisited , adj);
            if(cycleDetected){
                return true;
            }
        }
    }
    return false;
}
