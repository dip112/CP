//https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
//https://www.codingninjas.com/codestudio/problems/detect-cycle-in-a-directed-graph_1062626?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

//using dfs
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

//using bfs|kahn's algorithm
#include<bits/stdc++.h>
int detectCycleInDirectedGraph(int v, vector < pair < int, int >> & edges) {
  unordered_map<int , list<int>>adj;
    //create adjacency list
    for(int i=0;i<edges.size();i++){
        int u=edges[i].first-1;    //as in this case node start from 1, to make it 0 subtract by 1
        int v=edges[i].second-1;
        adj[u].push_back(v);
    }
    
    //find indigree of all nodes
    vector<int>indegree(v);
    for(auto i:adj){
        for(auto j:i.second){
            indegree[j]++;
        }
    }
    
    //push nodes with 0 indegree
    queue<int>q;
    for(int i=0;i<v;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    
    int cnt=0;
    //do bfs
    while(!q.empty()){
        int front=q.front();
        q.pop();
        cnt++;
        //find neighbours
        for(auto neighbour:adj[front]){
            indegree[neighbour]--;
            if(indegree[neighbour]==0){
                q.push(neighbour);
            }
        }
    }
    if(cnt==v){    //for valid topological sort counts equal to number of nodes
        return false;
    }
    else{
        return true;
    }
}
