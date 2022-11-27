#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>

void printMST(int parent[] , int **adj , int V){
  printf("Edge\tWeight\n");
  for(int i=1;i<V;i++){
    printf("%d - %d\t%d\n" , parent[i] , i , adj[i][parent[i]]);
  }
}
int minKey(int key[] , bool isMST[] , int V){
  int min=INT_MAX , minIndex;
  for(int i=0;i<V;i++){
    if(isMST[i]==false && key[i]<min){
      min=key[i];
      minIndex=i;
    }
  }
  return minIndex;
}
void primsAlgo(int **adj , int V){
  int parent[V];
  int key[V];
  bool isMST[V];

  for(int i=0;i<V;i++){
    key[i]=INT_MAX;
    isMST[i]=false;
  }

  key[0]=0;
  parent[0]=-1;

  for(int i=0;i<V-1;i++){
    int u=minKey(key , isMST , V);
    isMST[u]=true;
    for(int v=0;v<V;v++){
      if(adj[u][v] && isMST[v]==false && adj[u][v]<key[v]){
        parent[v]=u;
        key[v]=adj[u][v];
      }
    }
  }
  printMST(parent , adj , V);
}
int main(){
  int **adj,V;
  printf("Enter the size of vertices\n");
  scanf("%d",&V);
  adj=(int**)malloc(V*sizeof(int));
  for(int i=0;i<V;i++)
  {
    adj[i]=(int*)malloc(V*sizeof(int));
  }
  for(int i=0;i<V;i++)
  {
    for(int j=0;j<V;j++)
    {
      printf("Enter the adjacency matrix %d%d index\n",i,j);
      scanf("%d",&adj[i][j]);
    }
  }
  primsAlgo(adj , V);
  return 0;
}
