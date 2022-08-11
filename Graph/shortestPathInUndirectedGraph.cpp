//https://www.codingninjas.com/codestudio/problems/shortest-path-in-an-unweighted-graph_981297?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
#include<bits/stdc++.h>
vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	unordered_map<int , list<int>>adj;
	for(int i=0;i<m;i++){
        int u=edges[i].first;
        int v=edges[i].second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    unordered_map<int, bool>visited(n);
    unordered_map<int, int>parent;
    queue<int>q;
    visited[s]=1;
    parent[s]=-1;
    q.push(s);
    
    while(!q.empty()){
        int front=q.front();
        q.pop();
        for(auto i:adj[front]){
            if(!visited[i]){
                visited[i]=1;
                parent[i]=front;
                q.push(i);
            }
        }
    }
    
    vector<int>ans;
    int current=t;
    ans.push_back(current);
    
    while(current!=s){
        current=parent[current];
        ans.push_back(current);
    }
    reverse(ans.begin() , ans.end());
    
    return ans; 
}
//Time: O(N+E)
//Space: O(N+E)
