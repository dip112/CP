//https://leetcode.com/problems/shortest-path-visiting-all-nodes/
//https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1
//https://www.codingninjas.com/codestudio/problems/bfs-in-graph_973002?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
//We say that BFS is the algorithm to use if we want to find the shortest path in an undirected, unweighted graph.
#include<bits/stdc++.h>
void addAdjacent(unordered_map<int , set<int>>&adj , vector<pair<int, int>> &edges){
    for(int i=0;i<edges.size();i++){
        int u=edges[i].first;
        int v=edges[i].second;
        
        adj[u].insert(v);
        adj[v].insert(u);
    }
}
void bfs(unordered_map<int , set<int>>&adj , unordered_map<int , bool>&visited , vector<int>&ans ,             int node){
    queue<int>q;
    q.push(node);
    visited[node]=1;
    
    while(!q.empty()){
        int temp=q.front();
        q.pop();
        ans.push_back(temp);
        for(auto i:adj[temp]){
            if(!visited[i]){
                q.push(i);
                visited[i]=1;
            }
        }
    }
}
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    unordered_map<int , set<int>>adj;
    unordered_map<int , bool>visited;
    vector<int>ans;
    
    //add adjacent list
    addAdjacent(adj , edges);
    
    for(int i=0;i<vertex;i++){ //loop for disconnected graph
        if(!visited[i]){
            bfs(adj , visited , ans , i);
        }
    }
    return ans;
}
//Time: O(v+e)
//Space: O(v+e)
