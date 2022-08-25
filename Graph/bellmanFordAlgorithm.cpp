//shortest path finding algorithm apply on directed -ve weighted graph
//https://www.codingninjas.com/codestudio/problems/bellmon-ford_2041977?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
//https://practice.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1
//https://leetcode.com/problems/network-delay-time/

int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    vector<int>dist(n+1 , 1e9);
    dist[src]=0;
    //n-1 times
    for(int i=1;i<=n;i++){
        //traverese on edges
        for(int j=0;j<m;j++){
            int u=edges[j][0];
            int v=edges[j][1];
            int w=edges[j][2];
            
            if(dist[u]!=1e9 && ((dist[u]+w)<dist[v])){
                dist[v]=(dist[u]+w);
            }
        }
    }
    
    //check for negative cycle
    int flag=0;
    for(int j=0;j<m;j++){
        int u=edges[j][0];
        int v=edges[j][1];
        int w=edges[j][2];
            
        if(dist[u]!=1e9 && ((dist[u]+w)<dist[v])){
            flag=1;
        }
    }
    
    if(flag==0){
        return dist[dest];
    }
    return -1;
}
//Time: O((N-1)*E)
//Space: O(N*E)
