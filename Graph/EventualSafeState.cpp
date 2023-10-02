#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool dfsCheck(int node,vector<int> &vis,vector<int> &dfsVis,vector<int> &safeNode,vector<int> adj[]){
        vis[node] = 1;
        dfsVis[node] = 1;
        
        // processing neighbour
        for(auto it : adj[node]){
            if(!vis[it]){
                if(dfsCheck(it,vis,dfsVis,safeNode,adj))
                    return true; // cycle found
            }else if(dfsVis[it]){
                return true; // cycle found
            }
        }
        safeNode[node] = 1; // cycle not found
        dfsVis[node] = 0;
        return false; // cycle not found
    }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int> safeNode(V,-1);
        vector<int> ans;
        vector<int> vis(V,0);
        vector<int> dfsVis(V,0);
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                dfsCheck(i,vis,dfsVis,safeNode,adj);
            }
        }
        
        for(int i = 0; i < V; i++){
            if(safeNode[i] == 1)
                ans.push_back(i);
        }
        return ans;
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}