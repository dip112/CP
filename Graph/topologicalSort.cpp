//https://www.codingninjas.com/codestudio/problems/topological-sort_982938?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
//https://practice.geeksforgeeks.org/problems/topological-sort/1

//using dfs
#include<bits/stdc++.h>
void topoSort(int node , unordered_map<int , list<int>>&adj , vector<bool>&visited , stack<int>&s){
    visited[node]=1;
    
    for(auto neighbour:adj[node]){
        if(!visited[neighbour]){
            topoSort(neighbour , adj , visited , s);
        }
    }
    s.push(node);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    unordered_map<int , list<int>>adj;
    
    for(int i=0;i<e;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        
        adj[u].push_back(v);
    }
    
    vector<bool>visited(v);
    stack<int>s;
    
    for(int i=0;i<v;i++){
        if(!visited[i]){
            topoSort(i , adj , visited , s);
        }
    }
    
    vector<int>ans;
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}

//using kahn's algorithm
#include<bits/stdc++.h>
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    unordered_map<int , list<int>>adj;
    //create adjacency list
    for(int i=0;i<e;i++){
        int u=edges[i][0];
        int v=edges[i][1];
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
    
    vector<int>ans;
    //do bfs
    while(!q.empty()){
        int front=q.front();
        q.pop();
        ans.push_back(front);
        //find neighbours
        for(auto neighbour:adj[front]){
            indegree[neighbour]--;
            if(indegree[neighbour]==0){
                q.push(neighbour);
            }
        }
    }
    return ans;
}
