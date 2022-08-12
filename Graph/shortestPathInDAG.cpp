#include<bits/stdc++.h>
using namespace std;

class Graph{
  public:
    unordered_map<int , list<pair<int , int>>>adj;

    //create adjacency list
    void addEdges(int u , int v , int weight){
      pair<int,  int>p=make_pair(v , weight);
      adj[u].push_back(p);
    }

    //printing adjacency list
    void printEdges(){
      cout<<"Printing edges\n";
      for(auto i:adj){
        cout<<i.first<<" -> ";
        for(auto j:i.second){
          cout<<"( "<<j.first<<" , "<<j.second<<" )";
        }cout<<endl;
      }
    }

    //get topological order
    void dfs(int node , unordered_map<int , bool>&visited , stack<int>&s){
      visited[node]=1;
      for(auto i:adj[node]){
        if(!visited[i.first]){
          dfs(i.first , visited , s);
        }
      }
      s.push(node);
    }

    //get shortest path
    void getShortestPath(stack<int>&s , vector<int>&distance){
      while(!s.empty()){
        int top=s.top();
        s.pop();
        if(distance[top]!=INT_MAX){
          for(auto i:adj[top]){
            if((distance[top] + i.second) < distance[i.first]){
              distance[i.first]=distance[top]+i.second;
            }
          }
        }
      }
    }
};

int main(){
  Graph g;
  g.addEdges(0,1,5);
  g.addEdges(0,2,3);
  g.addEdges(1,2,2);
  g.addEdges(1,3,6);
  g.addEdges(2,3,7);
  g.addEdges(2,4,4);
  g.addEdges(2,5,2);
  g.addEdges(3,4,-1);
  g.addEdges(4,5,-2);

  g.printEdges();

  int n=6;

  unordered_map<int , bool>visited;
  stack<int>s;

  for(int i=0;i<n;i++){
    if(!visited[i]){
      g.dfs(i , visited , s);
    }
  }

  vector<int>distance(n);
  int src=1;

  for(int i=0;i<n;i++){
    distance[i]=INT_MAX;
  }

  distance[src]=0;

  g.getShortestPath(s , distance);

  cout<<"Shortest Path's\n";

  for(auto i:distance){
    cout<<i<<" , ";
  }cout<<endl;

  return 0;
}
