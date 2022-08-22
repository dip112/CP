//https://www.codingninjas.com/codestudio/problems/minimum-spanning-tree_631769?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
#include<bits/stdc++.h>
bool cmp(vector<int>&a , vector<int>&b){
    return a[2]<b[2];
}
void getSet(vector<int>&parent , vector<int>&rank , int n){
    for(int i=0;i<n;i++){
        parent[i]=i;
        rank[i]=0;
    }
}

int findParent(vector<int>&parent , int node){
    if(node==parent[node]){
        return node;
    }
    
    return parent[node]=findParent(parent , parent[node]);
}

void unionSet(int u , int v , vector<int>&parent , vector<int>&rank){
    u=findParent(parent , u);
    v=findParent(parent , v);
    
    if(rank[u]<rank[v]){
        parent[u]=v;
    }
    else if(rank[v]<rank[u]){
        parent[v]=u;
    }
    else{
        parent[v]=u;
        rank[u]++;
    }
}

int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
    vector<int>parent(n);
    vector<int>rank(n);
    
    getSet(parent , rank , n);
    
    sort(edges.begin() , edges.end() , cmp);
    
    int minWeight=0;
    
    for(int i=0;i<edges.size();i++){
        //find the parent of u & v
        int u=findParent(parent , edges[i][0]);
        int v=findParent(parent , edges[i][1]);
        int w=edges[i][2];
        
        //if u & v belongs to different component
        if(u!=v){
            minWeight+=w;
          
            //merge u & v into same component
            unionSet(u , v , parent , rank);
        }
    }
    return minWeight;
}
