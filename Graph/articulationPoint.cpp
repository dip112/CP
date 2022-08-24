#include<bits/stdc++.h>
using namespace std;

//https://www.codingninjas.com/codestudio/library/articulation-points-in-a-graph

void dfs(int node , int parent , vector<int>&disc , vector<int>&low , unordered_map<int , bool>&vis,
          unordered_map<int , list<int>>&adj , vector<int>&ap , int &timer){
  vis[node]=true;
  //update discover & low array with timer value
  disc[node]=low[node]=timer++;

  int child=0;

  for(auto neighbour:adj[node]){
    if(neighbour==parent){
      continue;
    }
    if(!vis[neighbour]){
      dfs(neighbour , node , disc , low , vis , adj , ap , timer);
      //while returning update low array of current node
      low[node]=min(low[node] , low[neighbour]);
      //check articulation point
      if(low[neighbour]>=disc[node] && parent!=-1){
        ap[node]=1;
      }
      //to track how many child are for each node
      child++;
    }
    //for back edge
    else{
      low[node]=min(low[node] , disc[neighbour]);
    }
  }
  //seperatly handel for starting node if it is articulation point or not
  if(parent==-1 && child>1){
    ap[node]=1;
  }
}

int main(){
  int n=5 , e=5;

  vector<pair<int , int>>edges;

  edges.push_back(make_pair(0,3));
  edges.push_back(make_pair(3,4));
  edges.push_back(make_pair(0,4));
  edges.push_back(make_pair(0,1));
  edges.push_back(make_pair(1,2));

  unordered_map<int , list<int>>adj;

  for(int i=0;i<e;i++){
    int u=edges[i].first;
    int v=edges[i].second;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<int>disc(n , -1);
  vector<int>low(n , -1);
  unordered_map<int , bool>vis;
  int timer=0;
  vector<int>ap(n , 0);

  for(int i=0;i<n;i++){
    if(!vis[i]){
      dfs(i , -1 , disc , low , vis , adj , ap , timer);
    }
  }

  cout<<"print articulation points"<<endl;
  for(int i=0;i<n;i++){
    if(ap[i]!=0){
      cout<<i<<",";
    }
  }cout<<endl;

  return 0;
}
