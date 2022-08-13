//https://www.codingninjas.com/codestudio/problems/dijkstra-s-shortest-path_920469?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
#include<bits/stdc++.h>
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    unordered_map<int , list<pair<int , int>>>adj;
    //make adjacency list
    for(int i=0;i<edges;i++){
        int u=vec[i][0];
        int v=vec[i][1];
        int w=vec[i][2];
        
        adj[u].push_back(make_pair(v , w));
        adj[v].push_back(make_pair(u , w));
    }
    
    vector<int>dist(vertices);
    //initialize dist array with INT_MAX
    for(int i=0;i<vertices;i++){
        dist[i]=INT_MAX;
    }
    //initialize distance of source node with 0
    dist[source]=0;
    
    set<pair<int , int>>s;
    //insert source node and its distance in set
    s.insert(make_pair(dist[source] , source));
    
    while(!s.empty()){
        //get node with minimum distance from top of set
        auto top=*(s.begin());
        //get node
        int topNode=top.second;
        //get its distance
        int nodeDist=top.first;
        s.erase(s.begin());
        
        //process of neighbour node
        for(auto neighbour:adj[topNode]){
            //if get minimum distanace
            if((nodeDist+neighbour.second)<dist[neighbour.first]){
                //find and remove if another pair exist in set
                auto record=s.find(make_pair(dist[neighbour.first] , neighbour.first));
                if(record!=s.end()){
                    s.erase(record);
                }
                
                //update distance
                dist[neighbour.first]=nodeDist+neighbour.second;
                //insert neighbour node and its distance into set
                s.insert(make_pair(dist[neighbour.first] , neighbour.first));
            }
        }
    }
    return dist;
}
//Time: O(ElogV)
//Space: O(E+V)
