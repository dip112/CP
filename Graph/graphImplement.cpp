#include<bits/stdc++.h>
using namespace std;
template<typename t>
class Graph{
public:
  unordered_map<t , list<t>>adj;

  void addEdges(t u , t v , bool direction){
    adj[u].push_back(v);

    if(direction==0){
      adj[v].push_back(u);
    }
  }

  void printEdges(){
    for(auto it:adj){
      cout<<it.first<<"-> ";

      for(auto j:it.second){
        cout<<j<<", ";
      }cout<<endl;
    }
  }
};

int main(){
  int n;
  cout<<"Enter the number of nodes\n";
  cin>>n;

  int m;
  cout<<"Enter the number of edges\n";
  cin>>m;

  Graph<int> g;

  cout<<"Enter edges\n";
  for(int i=0;i<m;i++){
    int u , v;
    cin>>u>>v;
    g.addEdges(u , v , 0);  //0 means undirected graph
  }

  g.printEdges();

  return 0;
}
