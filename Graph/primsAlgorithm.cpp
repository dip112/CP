//https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1
//https://www.codingninjas.com/codestudio/problems/prim-s-mst_1095633?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

//algorithm:
//          1. mark key[source]=0;
//             parent[source]=-1
//
//          2. find node u with minimum cost and mst[u]==false
//             then mark mst[u]=true
//
//          3. find u's adjacency list and update neighbours key and parent array as
//             if(mst[neighbour]==false && w<key[neighbour])
//                key[neighbour]=w
//                parent[neighbour]=u


#include<bits/stdc++.h>
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    unordered_map<int , list<pair<int , int>>>adj;
    
    //create adjacency list
    for(int i=0;i<g.size();i++){
        int u=g[i].first.first;
        int v=g[i].first.second;
        int w=g[i].second;
        
        adj[u].push_back(make_pair(v , w));
        adj[v].push_back(make_pair(u , w));
    }
  
    vector<int>key(n+1 , INT_MAX); //as node start with 1
    vector<bool>mst(n+1 , false);
    vector<int>parent(n+1 , -1);
    
    //initialize source node
    key[1]=0;
    parent[1]=-1;
    
    for(int i=1;i<n;i++){   // 1 to n: cause we already process source node
        int mini=INT_MAX;
        int u;
        
        //finding node with minimum cost in key array
        for(int v=1;v<=n;v++){                //-------|
            if(mst[v]==false && key[v]<mini){ //       |
                u=v;                          //       |     to finding node with min cost our time complexsity is O(n^2) in this case
                mini=key[v];                  //       |     if we use priority queue then to get node with min cost our time complexsity will be O(n*logn) 
            }                                 //       |
        }                                     //-------|
        
      //mark node with min cose as true means for spanning tree it is already processed
        mst[u]=true;
        
      //update key and parent array of current's nodes neighbours 
        for(auto it:adj[u]){
            int v=it.first;
            int w=it.second;
            
            if(mst[v]==false && w<key[v]){
                key[v]=w;
                parent[v]=u;
            }
        }
    }
    
    vector<pair<pair<int, int>, int>>ans;
    
    //create minimum spanning tree
    for(int i=2;i<=n;i++){
        ans.push_back({{parent[i] , i} , key[i]});
    }
    
    return ans;
}
