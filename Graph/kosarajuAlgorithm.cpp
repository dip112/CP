//used to find strongly connected components
//https://www.codingninjas.com/codestudio/problems/count-strongly-connected-components-kosaraju-s-algorithm_1171151?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
//https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1

#include<bits/stdc++.h>
void dfs(int node , unordered_map<int , bool>&vis , unordered_map<int , list<int>>&adj ,stack<int>&s){
    vis[node]=true;
    
    for(auto neighbour:adj[node]){
        if(!vis[neighbour]){
            dfs(neighbour , vis , adj , s);
        }
    }
    s.push(node);
}

void revDfs(int node , unordered_map<int , bool>&vis , unordered_map<int , list<int>>&adj){
    vis[node]=true;
    
    for(auto nbr:adj[node]){
        if(!vis[nbr]){
            revDfs(nbr , vis , adj);
        }
    }
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
	unordered_map<int , list<int>>adj;
    
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        
        adj[u].push_back(v);
    }
    
    stack<int>s;
    unordered_map<int , bool>vis;
    
    //topo sort
    for(int i=0;i<v;i++){
        if(!vis[i]){
            dfs(i , vis , adj , s);
        }
    }
    
    //transpose graph
    unordered_map<int , list<int>>trans;
    for(int i=0;i<v;i++){
        vis[i]=false;
        for(auto nbr:adj[i]){
            trans[nbr].push_back(i);
        }
    }
    
    //calling dfs bassed on topo. sort
    int count=0;
    while(!s.empty()){
        int top=s.top();
        s.pop();
        if(!vis[top]){
            count++;
            revDfs(top , vis , trans);
        }
    }
    return count;
}
//Time: O(N+E)
//Space: O(N)
