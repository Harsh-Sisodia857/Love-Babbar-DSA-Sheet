#include<bits/stdc++.h>
using namespace std;

void bfs(int src, vector<int> &dist, unordered_map<int, list<int>> &adj){
    dist[src] = 0;
    queue<int> q;
    q.push(src);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        if(dist[node] != INT_MAX){
            for(auto it : adj[node]){
                // for unit weighted graph
                if(dist[node] + 1 < dist[it]){
                    dist[it] = dist[node] + 1;
                    q.push(it);
                }
            }
        }
    }
}

    int main()
{
    int N, V;
    cout << "Enter no. of nodes and edges : ";
    cin >> N>> V;

    unordered_map<int, list<int>> adj;
    for (int i = 0; i < V; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> dist(N, INT_MAX);
    int src = 0;
    bfs(src, dist, adj);
    
    // distance vector
    for(auto it : dist){
            it == INT_MAX ? cout << " INF " : cout << it<<" ";
    }
        return 0;
}