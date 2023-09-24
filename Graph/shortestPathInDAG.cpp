#include<bits/stdc++.h>
using namespace std;
// input :
// Enter no.of nodes and edges : 6 6 
// 4 0 1 
// 4 1 1 
// 3 1 1 
// 2 3 1 
// 5 2 1 
// 5 0 1 
void topoSort(int node, unordered_map<int, list<pair<int, int>>> &adjList, int V, vector<bool> &vis, stack<int> &st)
{
    vis[node] = true;
    // in this line we can store dfs of graph ---> dfs.push_back(node)
    for(auto it : adjList[node]){
        if(!vis[it.first])
            topoSort(it.first, adjList, V, vis, st);
    }
    // to find topological sort while returning from dfs call of node we push the node to the stack
    st.push(node);
}

vector<int> findTopological(unordered_map<int, list<pair<int, int>>> &adjList, int V)
{
    stack<int> st;
    vector<bool> vis(V, false);
    for (int i = 0; i < V; i++){
        if(!vis[i]){
            topoSort(i,adjList, V, vis,st);
        }
    }
    vector<int> topologicalSort;
    while(!st.empty()){
        int topEle = st.top();
        st.pop();
        topologicalSort.push_back(topEle);
    }
    return topologicalSort;
}

    int main()
{
    int e, v;
    cout << "Enter no. of nodes and edges : ";
    cin >> v >> e;
    unordered_map<int, list<pair<int,int>>> adjList;
    for (int i = 0; i < e; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adjList[u].push_back({v,w});
    }
    // printing the graph
    for(auto it : adjList){
        cout << it.first << " : ";
        for(auto j : it.second)
            cout <<"{"<< j.first <<","<<j.second<< "} ->";
        cout << "NULL"<<endl;
    }
    // finding topological sort
    vector<int> topo = findTopological(adjList,v);
    // printing topological sort
    for(auto it : topo){
        cout << it << " ";
    }

    // finding distance from src node to all node
    vector<int> dist(v, INT_MAX);
    int src = 1;
    dist[src] = 0;
    for (int j = 0; j < topo.size(); j++){
        int i = topo[j];
        if(dist[i] != INT_MAX){
            for(auto it : adjList[i])
            if(dist[i] + it.second < dist[it.first]){
                dist[it.first] = dist[i] + it.second;
            }
        }
    }

    cout << "\nDISTANCE FROM SRC NODE TO ALL OTHER NODE : " << endl;
    // distance vector
    for(auto it : dist){
        cout << it << " ";
    }

    return 0;
}